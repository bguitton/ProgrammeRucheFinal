/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModemSigfox.cpp
 * Author: bguitton
 * 
 * Created on 21 mai 2021, 10:31
 */

#include "ModemSigfox.h"

ModemSigfox::ModemSigfox() : Sigfox(27, 26, true) {

}

void ModemSigfox::ForgerTrameMesure(mesure lesMesures, float masse) {


    laTrameMesure.temperature = (short) (lesMesures.temperature * 100);
    laTrameMesure.humidite = (char) lesMesures.humidite;
    laTrameMesure.masse = (short) (masse * 100);
    laTrameMesure.pression = (short) lesMesures.pression;
    laTrameMesure.eclairement = (short) lesMesures.eclairement;
    laTrameMesure.pointDeRosee = 2234;
    laTrameMesure.typeTrame = 1;

    // bool StatusSig=envoyer((void*)&laTrameMesure,sizeof(laTrameMesure));
    // Serial.println("Envoi effectuer");
//    Serial.print("poids :");
//    Serial.println(laTrameMesure.masse);
//    Serial.print("température :");
//    Serial.println(laTrameMesure.temperature);
//    Serial.print("pression :");
//    Serial.println(laTrameMesure.pression);
//    Serial.print("eclairement :");
//    Serial.println(laTrameMesure.eclairement);
//    Serial.print("point de rosée :");
//    Serial.println(laTrameMesure.pointDeRosee);
//    Serial.print("humidité :");
//    Serial.println(laTrameMesure.humidite);
//    Serial.print("type :");
//    Serial.println(laTrameMesure.typeTrame);

}

ModemSigfox::~ModemSigfox() {
}

void ModemSigfox::ForgerTrameBatterie(mesureBatterie lesMesuresBatterie) {
    //float tension = (lesMesuresBatterie.puissanceBatterie / lesMesuresBatterie.intensiteBatterie) * 100.0;
    laTrameBatterie.tension = (short) (lesMesuresBatterie.tensionBatterie*100);
    laTrameBatterie.courant = (short) (lesMesuresBatterie.intensiteBatterie * 100);
    laTrameBatterie.puissance = (short) (lesMesuresBatterie.puissanceBatterie * 100);
    laTrameBatterie.charge = (short) (lesMesuresBatterie.chargeBatterie * 1000);
    laTrameBatterie.nu = 0;
    laTrameBatterie.tauxDeCharge = (short) (lesMesuresBatterie.tauxDeChargeBatterie * 2);
    laTrameBatterie.typeTrame = 2;
         bool StatusSig=envoyer((void*)&laTrameBatterie,sizeof(laTrameBatterie));
        Serial.println("Envoi effectuer");
    Serial.print("tension :");
    Serial.println(laTrameBatterie.tension);
    Serial.print("courant :");
    Serial.println(laTrameBatterie.courant);
    Serial.print("puissance :");
    Serial.println(laTrameBatterie.puissance);
    Serial.print("charge :");
    Serial.println(laTrameBatterie.charge);
    Serial.print("nu :");
    Serial.println(laTrameBatterie.nu);
    Serial.print("taux de charge :");
    Serial.println(laTrameBatterie.tauxDeCharge);
    Serial.print("type :");
    Serial.println(laTrameBatterie.typeTrame);


}
