/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   constante.h
 * Author: bguitton
 *
 * Created on 6 mai 2021, 15:51
 */

#ifndef CONSTANTE_H
#define CONSTANTE_H
#define EEPROM_SIZE 512
#define LOADCELL_DOUT_PIN = 26;
#define LOADCELL_SCK_PIN = 25;
#define SERIAL_BAUD 115200

#define uS_TO_S_FACTOR 1000000  /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  2        /* Time ESP32 will go to sleep (in seconds) */

typedef struct {
    float temperature;
    float humidite;
    float pression;
    float eclairement;

} mesure;

typedef struct {
    short temperature;
    unsigned char humidite;
    unsigned short masse;
    unsigned short eclairement;
    unsigned short pression;
    short pointDeRosee;
    char typeTrame = 1;
} trameMesure;

typedef struct {
    float tensionBatterie;
    float puissanceBatterie;
    int tauxDeChargeBatterie;
    float chargeBatterie;
    float intensiteBatterie;
} mesureBatterie;
typedef struct {
    short tension;
    short courant;
    short puissance;
    short charge;
    short nu;
    unsigned char tauxDeCharge;
    char typeTrame = 02;
} trameBatterie;

#endif /* CONSTANTE_H */

