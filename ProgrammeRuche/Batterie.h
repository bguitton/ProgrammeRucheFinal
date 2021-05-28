/**
 * @file Batterie.cpp
 * @brief Déclaration de la classe Batterie
 * @version 1.0
 * @author Quentin BRAULT
 * @date 21/05/2021
 * 
 */

#include <Adafruit_INA219.h>
#include "constante.h"
#ifndef BATTERIE_H
#define BATTERIE_H

/** Structure regroupant les caractéristiques de la batterie*/


class Batterie : public Adafruit_INA219 {
public:
    Batterie();
    Batterie(const Batterie& orig);
    virtual ~Batterie();

    void ConfigurerCapacite(int nouvCapacite);
    int DonnerCapacite();
    mesureBatterie CalculerCaracteristiques();
private:
    /** Valeur pour calculer la charge de la batterie*/
    float ancienneIntensite;
    /** Valeur pour calculer la charge de la batterie*/
    float ancienneCharge;
    /** Valeur dela capacité de la batterie*/
    float capacite;

    float intensite;
    mesureBatterie lesMesuresB;

    Adafruit_INA219 *ina219;
};

#endif /* BATTERIE_H */
