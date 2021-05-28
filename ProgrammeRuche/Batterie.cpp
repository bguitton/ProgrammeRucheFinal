
/**
 * @file Batterie.cpp
 * @brief Implémentation de la classe Batterie
 * @version 1.0
 * @author Quentin BRAULT
 * @date 21/05/2021
 * @details Classe récupérant les informations et effectuant les calculs relatif à la batterie
 * 
 */

#include "Batterie.h"
#include "constante.h"

/**
 * @brief Batterie::Batterie
 * @details Initialisation du capteur INA219
 */
Batterie::Batterie() :
ancienneIntensite(0),
capacite(10),
ancienneCharge(10),
intensite(0) {
    ina219 = new Adafruit_INA219();

    ina219->begin();
}

Batterie::Batterie(const Batterie& orig) {
}

Batterie::~Batterie() {
    delete ina219;
}

/**
 * @brief Batterie::ConfigurerCapacite
 * @details Change la valeur de la capacité de la batterie par la valeur de la capacité de la nouvelle batterie
 * @param nouvCapacite la valeur de la capacité de la nouvelle batterie
 */
void Batterie::ConfigurerCapacite(int nouvCapacite) {
    capacite = nouvCapacite;
    ancienneCharge = nouvCapacite;
    ancienneIntensite = 0;
}

/**
 * @brief Batterie::DonnerCapacite
 * @details Retourne la valeur de la capacité de la batterie.
 * @return Valeur de la capacité de la batterie
 */
int Batterie::DonnerCapacite() {
    return capacite;
}

/**
 * @brief Batterie::CalculerCaracteristiques
 * @details Calcule et récupère toutes les caractréristiques nécessaire de la batterie
 * @return Structure regroupant toutes les données
 */
mesureBatterie Batterie::CalculerCaracteristiques() {
    lesMesuresB.tensionBatterie=ina219->getBusVoltage_V();
    lesMesuresB.intensiteBatterie = ina219->getCurrent_mA();
    lesMesuresB.puissanceBatterie = ina219->getPower_mW();

    /**Calcul Charge de la batterie*/
    lesMesuresB.chargeBatterie = ancienneCharge + ((ancienneIntensite + lesMesuresB.intensiteBatterie / 1000) / 2) * 0.5;

    /**Si la charge de la batterie excéde la capacité ou est en dessous de 0, corrige le problème*/
    if (lesMesuresB.chargeBatterie > capacite) {
        lesMesuresB.chargeBatterie = capacite;
    } else if (lesMesuresB.chargeBatterie < 0) {
        lesMesuresB.chargeBatterie = 0;
    }

    ancienneCharge = lesMesuresB.chargeBatterie;
    ancienneIntensite = lesMesuresB.intensiteBatterie / 1000;

    /**Calcul SoC Batterie*/
    lesMesuresB.tauxDeChargeBatterie = (lesMesuresB.chargeBatterie / capacite)*100;


    return lesMesuresB;
}