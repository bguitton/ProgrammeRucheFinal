/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.h
 * Author: bguitton
 *
 * Created on 6 mai 2021, 16:58
 */

#ifndef MENU_H
#define MENU_H

class Menu {
public:
    Menu();
    Menu(const Menu& orig);
    virtual ~Menu();
//private:
    void AfficherMenu();
    void AfficherMenuBatterie();
    void AfficherMenuBalance();
    void AfficherMenuSysteme();

};

#endif /* MENU_H */

