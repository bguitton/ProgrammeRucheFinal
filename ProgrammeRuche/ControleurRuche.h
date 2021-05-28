/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 /

/ 
 * File:   ControleurRuche.h
 * Author: bguitton
 *
 * Created on 4 mai 2021, 09:40
 */

#ifndef CONTROLEURRUCHE_H
#define CONTROLEURRUCHE_H
#include "Balance.h"
#include "Environnement.h"
#include "constante.h"
#include "Menu.h"
#include "Batterie.h"
#include "ModemSigfox.h"





class ControleurRuche {
public:
    ControleurRuche();
    ControleurRuche(const ControleurRuche& orig);
    virtual ~ControleurRuche();

    void EnvoyerDonneesMesures();
    void EnvoyerDonneesBatterie();
    void Ordonnancer();
    void RecupererDonnees();
    void RecupererDonneesBatterie();
    void AfficherConfig();
    void ConfiguerNom();
    void CommandeSaisie();
    void Retour();
    void ConfiguerBatterie();

    void GestionMenu(int _choix);
    void GestionMenuSysteme();
    void GestionMenuBatterie();
    void GestionMenuBalance();
     Menu *leMenu;
 

private:
    mesure lesMesuresC;
    mesureBatterie lesMesuresBatterie;
    float masse;
    float tension;
    float intensite;
    float tauxDeCharge;
    float charge;
    bool choixTrame;
    Balance *laBalance;
    Environnement *unEnvironnement;
    Batterie *laBatterie;
    ModemSigfox *leModemSigfox;
    

};



#endif /* CONTROLEURRUCHE_H */