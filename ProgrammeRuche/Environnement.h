/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Environnement.h
 * Author: bguitton
 *
 * Created on 26 mars 2021, 11:14
 */

#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#include<Arduino.h>
#include<Wire.h>
#include<BME280I2C.h>
#include <BH1750.h>
#include "constante.h"


//struct mesure {
//    float temperature;
//    float humidite;
//    float pression;
//    float eclairement;
//};


class Environnement {
public:
    Environnement(bool _debug=false,BME280I2C::I2CAddr adresse=BME280I2C::I2CAddr_0x77);
//    Environnement(const Environnement& orig);
    virtual ~Environnement();
    mesure ObtenirMesures();


private:
    bool debug;
    BH1750 *leBh1750;
    BME280 *leBme280;
   
    mesure lesMesures;


};

#endif /* ENVIRONNEMENT_H */

