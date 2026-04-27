/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Analyse.h
 * Author: 51969
 *
 * Created on 11 de diciembre de 2024, 21:53
 */

#ifndef ANALYSE_H
#define ANALYSE_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <iterator>
using namespace std;
#include "Phrase.h"
#include "Mot.h"
class Analyse {
public:
    Analyse();
    Analyse(const Analyse& orig);
    virtual ~Analyse();
    void charger_lexicon();
    void charger_commentaires();
    void imprimer_analyse();
    void traiter_mot(string &texte);
private:
    map<string,vector<Phrase>> commentaires;
    map<string,int> nombre_opinions;
    map<string,int> lexicon;
};

#endif /* ANALYSE_H */

