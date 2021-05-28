/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.cpp
 * Author: bguitton
 * 
 * Created on 6 mai 2021, 16:58
 */

#include "Menu.h"

Menu::Menu() {
}

Menu::Menu(const Menu& orig) {
}

Menu::~Menu() {
}

void Menu::AfficherMenu() {
    Serial.println("\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n");
    Serial.println("\n Faites votre choix :");
    Serial.println("\n 1- Configurer la Batterie");
    Serial.println("\n 2- Configurer la Balance");
    Serial.println("\n 3- Configurer le menu système");
    Serial.println("\n 4- Quitter le mode configuration\n");
}

void Menu::AfficherMenuBatterie() {

    Serial.println("\n \n \n");
    Serial.println("\n Menu Batterie, que souhaitez-vous faire ? \n");
    Serial.println("\n 1- Configurer la capacité de la Batterie \n");
    Serial.println("\n 2- Retourner en arrière\n");

}

void Menu::AfficherMenuBalance() {

    Serial.println(" Menu Balance, que souhaitez-vous faire ?");
    Serial.println("\n 1- Tarer la balance ");
    Serial.println("\n 2- Etalonner la balance ");
    Serial.println("\n 3- Peser ");
    Serial.println("\n 4- Retourner en arrière\n");


}

void Menu::AfficherMenuSysteme() {
    Serial.println("\n \n \n Menu Système, que souhaitez-vous faire ?");
    Serial.println("\n 1- Configurer le nom ");
    Serial.println("\n 2- Afficher la configuration ");
    Serial.println("\n 3- Retourner en arrière\n");
}