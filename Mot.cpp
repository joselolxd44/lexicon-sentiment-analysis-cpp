/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Mot.cpp
 * Author: 51969
 * 
 * Created on 11 de diciembre de 2024, 21:42
 */

#include "Mot.h"

Mot::Mot() {
    
    polarite=0;
}

Mot::Mot(const Mot& orig) {
    /*Comme je travaille avec des objets et que je n'utilise pas de pointeurs, je dois créer mes constructeurs de copie.*/
    this->texte=orig.texte;
    this->polarite=orig.polarite;
}

Mot::~Mot() {
}

void Mot::SetPolarite(int polarite) {
    this->polarite = polarite;
}

int Mot::GetPolarite() const {
    return polarite;
}

void Mot::SetTexte(string texte) {
    this->texte = texte;
}

string Mot::GetTexte() const {
    return texte;
}




