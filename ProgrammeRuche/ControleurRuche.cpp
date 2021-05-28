/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ControleurRuche.cpp
 * Author: bguitton
 * 
 * Created on 4 mai 2021, 09:40
 */

#include "ControleurRuche.h"

ControleurRuche::ControleurRuche() {


    lesMesuresC.temperature = 0;
    lesMesuresC.humidite = 0;
    lesMesuresC.pression = 0;
    lesMesuresC.eclairement = 0;
    unEnvironnement = new Environnement(false, BME280I2C::I2CAddr_0x77);
    laBalance = new Balance();
    laBatterie = new Batterie();
    leMenu = new Menu();
    leModemSigfox = new ModemSigfox();
    leModemSigfox->begin();
    choixTrame = true;


    laBalance->ConfiguerOffset(EEPROM.readDouble(0)); // lire le coef offset à l'adresse 0 et configuration de offset
    laBalance->ConfiguerScale(EEPROM.readDouble(10)); // lire le coef scale à l'adresse 10 et configuration de scale

}

ControleurRuche::ControleurRuche(const ControleurRuche& orig) {
}

ControleurRuche::~ControleurRuche() {
}

void ControleurRuche::EnvoyerDonneesMesures() {

}

void ControleurRuche::EnvoyerDonneesBatterie() {

}

void ControleurRuche::RecupererDonnees() {

    lesMesuresC = unEnvironnement->ObtenirMesures();
    masse = laBalance->Peser();
    Serial.print("Temp: ");
    Serial.print(lesMesuresC.temperature);
    Serial.print("°C\t");
    Serial.print("Humidity: ");
    Serial.print(lesMesuresC.humidite);
    Serial.print("% RH\t");
    Serial.print("Pressure: ");
    Serial.print(lesMesuresC.pression / 100);
    Serial.print("hPa\t");
    Serial.print("eclairement: ");
    Serial.print(lesMesuresC.eclairement);
    Serial.println("lux\t");
    Serial.print(masse);
    Serial.println("kg\t");



}

void ControleurRuche::RecupererDonneesBatterie() {
    lesMesuresBatterie = laBatterie->CalculerCaracteristiques();
    Serial.print("Tension:       ");
    Serial.print(lesMesuresBatterie.tensionBatterie);
    Serial.println(" V");
    Serial.print("Courant:       ");
    Serial.print(lesMesuresBatterie.intensiteBatterie);
    Serial.println(" mA");
    Serial.print("Puissance:     ");
    Serial.print(lesMesuresBatterie.puissanceBatterie);
    Serial.println(" mW");
    Serial.print("Charge:        ");
    Serial.print(lesMesuresBatterie.chargeBatterie);
    Serial.println(" Ah");
    Serial.print("Taux de Charge:  ");
    Serial.print(lesMesuresBatterie.tauxDeChargeBatterie);
    Serial.println("%");
    Serial.println("");
    
    delay(1000);

}

void ControleurRuche::Ordonnancer() {
    if (choixTrame == true) {
        //RecupererDonnees();
        choixTrame = false;

    } else {
        RecupererDonneesBatterie();
        choixTrame = true;
    }
}

void ControleurRuche::ConfiguerNom() {

}

void ControleurRuche::CommandeSaisie() {

}

void ControleurRuche::Retour() {
    int choix;
    leMenu->AfficherMenu();
    while (!Serial.available());


    choix = Serial.read();
    GestionMenu(choix);

}

void ControleurRuche::ConfiguerBatterie() {

}

void ControleurRuche::GestionMenu(int _choix) {


    switch (_choix) {
        case '1':
            leMenu->AfficherMenuBatterie();
            GestionMenuBatterie();

            break;
        case '2':
            leMenu->AfficherMenuBalance();
            GestionMenuBalance();
            break;
        case '3':
            leMenu->AfficherMenuSysteme();
            GestionMenuSysteme();

    }

}

void ControleurRuche::GestionMenuSysteme() {
    String nom;
    int choix;
    while (!Serial.available());


    choix = Serial.read();
    switch (choix) {
        case '1':
            Serial.println();
            Serial.print("Entrez le nouveau nom du système : ");
            while (!Serial.available());
            nom = Serial.readString();
            Serial.println("\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n");
            break;
        case '2':
            Serial.println();
            Serial.print("Configuration : ");
            Serial.println(nom);
    }
}

void ControleurRuche::GestionMenuBatterie() {
    int choix;
    int capacite;
    do {
        do {
            while (!Serial.available());
            choix = Serial.read();
        } while (choix < '1' || choix > '3');
        switch (choix) {
            case '1':
                Serial.println("\n \n");
                Serial.print(" La capacité est de : ");
                Serial.print(laBatterie->DonnerCapacite());
                Serial.println("\n \n");
                Serial.print(" Entrez la nouvelle capacité : ");
                do {
                    while (!Serial.available());
                    capacite = Serial.read();
                    capacite = capacite - '0';
                    laBatterie->ConfigurerCapacite(capacite);
                    Serial.print(capacite);
                } while (capacite < 1 || capacite > 9);
                leMenu->AfficherMenuBatterie();
                break;

            case '3':
                Serial.println("\n \n");
                Serial.print(" La capacité est de : ");
                Serial.println(laBatterie->DonnerCapacite());

        }
    } while (choix != '2');
    leMenu->AfficherMenu();
}

void ControleurRuche::GestionMenuBalance() {
    float poidEtalon;
    int choix;

    laBalance->ConfiguerOffset(EEPROM.readDouble(0)); // lire le coef offset à l'adresse 0 et configuration de offset
    laBalance->ConfiguerScale(EEPROM.readDouble(10));
    do {
        while (!Serial.available());
        choix = Serial.read();
        switch (choix) {
            case '1': // l'utilisateur à choisi l'option Tarer
                Serial.println("vider le plateau et appuyer sur une touche pour tarer ");
                while (!Serial.available());
                while (Serial.available()) Serial.read();
                laBalance->TarerLaBalance();
                // Serial.println(laBalance.ObtenirOffset()); affichage de coef offset
                Serial.println("tarage effectuer: \t\t");
                EEPROM.writeDouble(0, laBalance->ObtenirOffset()); // sauvegarder le coef offset à l'adresse 0
                EEPROM.commit();
                Serial.print("masse = ");
                Serial.println(laBalance->Peser());
                break;
            case '2': // l'utilisateur à choisi l'option Tarer
                if (laBalance->TarageEffectuer()) {
                    Serial.println("Poser le poids étalon puis donnez sa valeur en gramme (ex:400g= 400) et appuyez sur entrer ");
                    while (!Serial.available());

                    while (Serial.available() == 0) {
                    }
                    poidEtalon = Serial.parseFloat();


                    while (!Serial.available());
                    while (Serial.available()) Serial.read();
                    Serial.println(poidEtalon); // affiche 4 si l'ont tape 4
                    laBalance->EtalonnerLaBalance(poidEtalon);
                    Serial.println(laBalance->ObtenirScale());
                    EEPROM.writeDouble(10, laBalance->ObtenirScale()); // sauvegarder le coef scale à l'adresse 10
                    EEPROM.commit();
                } else {
                    Serial.println("Vous devez tarer la balance avant de faire un etalonnage ");
                }
                break;
            case '3':
                Serial.print("masse = ");
                Serial.println(laBalance->Peser()); // appel de la fonction peser qui renvoi la masse mesurée


        }
        leMenu->AfficherMenuBalance();
    } while (choix != '4');
    leMenu->AfficherMenu();

}