/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Phrase.h
 * Author: 51969
 *
 * Created on 11 de diciembre de 2024, 21:50
 */

#ifndef PHRASE_H
#define PHRASE_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;
#include "Mot.h"
class Phrase {
public:
    Phrase();
    Phrase(const Phrase& orig);
    virtual ~Phrase();
    void SetQuantite_mots(int quantite_mots);
    int GetQuantite_mots() const;
    void ajouter_mot(Mot &mot);
    void charger_score(ofstream &arch);
    void SetScore_phrase(double score_phrase);
    double GetScore_phrase() const;
private:
    vector<Mot> mots;
    int quantite_mots;
    double score_phrase;
};

#endif /* PHRASE_H */

