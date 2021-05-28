/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.ino.cpp
 * Author: bguitton
 *
 * Created on 22 mars 2021, 09:19
 */

#include <cstdlib>
#include<Arduino.h>
#include <soc/rtc.h>
#include <string.h>
#include <valarray>
#include "ControleurRuche.h"
#include "constante.h"

//#define uS_TO_S_FACTOR 1000000  /* Conversion factor for micro seconds to seconds */
//#define TIME_TO_SLEEP  10 



using namespace std;


/*
 * 
 */
esp_sleep_wakeup_cause_t wakeup_reason;
ControleurRuche *leControleur;


esp_sleep_wakeup_cause_t print_wakeup_reason() {
    esp_sleep_wakeup_cause_t wakeup_reason;

    wakeup_reason = esp_sleep_get_wakeup_cause();

    return wakeup_reason;
}

void setup() {

    Serial.begin(SERIAL_BAUD);
    Wire.begin();
    EEPROM.begin(EEPROM_SIZE);
   
    
    leControleur = new ControleurRuche();
Serial.println("Setup");
    pinMode(13, INPUT_PULLUP);

    gpio_wakeup_enable((GPIO_NUM_13), GPIO_INTR_HIGH_LEVEL);
   


}

void loop() {
    Serial.println("loop");
    //    leControleur->RecupererDonnees();
      float choix = 0;
     // leControleur->leMenu->AfficherMenu();
    //
    //    while (Serial.available() == 0) {
    //    }
    //    choix = Serial.read();
    //    Serial.println(choix);
    //    leControleur->GestionMenu(choix);

    esp_sleep_enable_gpio_wakeup();
    esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);

    wakeup_reason = print_wakeup_reason();
    
    if (wakeup_reason == ESP_SLEEP_WAKEUP_GPIO) {
          leControleur->leMenu->AfficherMenu();
          do{
          while (Serial.available() == 0) {
        }
        choix = Serial.read();
        Serial.println(choix);
        leControleur->GestionMenu(choix);
          }while(choix!='4');
    }

    if (wakeup_reason == ESP_SLEEP_WAKEUP_TIMER) {
        leControleur->Ordonnancer();


        delay(1000);
    }
    esp_light_sleep_start();

}
