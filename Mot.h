/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Mot.h
 * Author: 51969
 *
 * Created on 11 de diciembre de 2024, 21:42
 */

#ifndef MOT_H
#define MOT_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;
class Mot {
public:
    Mot();
    Mot(const Mot& orig);
    virtual ~Mot();
    void SetPolarite(int polarite);
    int GetPolarite() const;
    void SetTexte(string texte);
    string GetTexte() const;
    
    
private:
    string texte;
    int polarite;

};

#endif /* MOT_H */

