/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Phrase.cpp
 * Author: 51969
 * 
 * Created on 11 de diciembre de 2024, 21:50
 */

#include "Phrase.h"

Phrase::Phrase() {
    quantite_mots=0;
    score_phrase=0;
}

Phrase::Phrase(const Phrase& orig) {
   this->mots=orig.mots;
   this->quantite_mots=orig.quantite_mots;
    
}

Phrase::~Phrase() {
}

void Phrase::SetQuantite_mots(int quantite_mots) {
    this->quantite_mots = quantite_mots;
}

int Phrase::GetQuantite_mots() const {
    return quantite_mots;
}

void Phrase::ajouter_mot(Mot &mot) {
    mots.push_back(mot);
    quantite_mots++;
}

void Phrase::charger_score(ofstream& arch) {
    
    score_phrase=0;
    for (auto it=mots.begin();it!=mots.end();++it) {
        /*Je charge la polarité du mot*/
        score_phrase= score_phrase + it->GetPolarite();
    }
    

}

void Phrase::SetScore_phrase(double score_phrase) {
    this->score_phrase = score_phrase;
}

double Phrase::GetScore_phrase() const {
    return score_phrase;
}


