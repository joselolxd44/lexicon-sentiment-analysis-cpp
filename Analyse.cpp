/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Analyse.cpp
 * Author: 51969
 * 
 * Created on 11 de diciembre de 2024, 21:53
 */

#include "Analyse.h"

Analyse::Analyse() {
}

Analyse::Analyse(const Analyse& orig) {
}

Analyse::~Analyse() {
}
/*Je vais charger mon lexicon pour avoir un lexique de mots importants au moment d'analyser le texte*/
void Analyse::charger_lexicon() {
    ifstream arch("lexicon.csv",ios::in);
    if(not arch.is_open()){
        cout<<"Le fichier lexicon.csv n'a pas pu etre ouvert";
        exit(1);
    }
    string strmot;
    int polarite;
    while(true){
        char c;
        Mot mot;       
        getline(arch,strmot,',');
        if(arch.eof())break;
        arch>>polarite;
        arch>>ws;
        mot.SetPolarite(polarite);
        mot.SetTexte(strmot);
        /*J'utilise un stl map pour trouver facilemente le mot recherché, avec son polarité correspondante*/
        lexicon[mot.GetTexte()]=mot.GetPolarite(); 
    }
}

/*Avec cette méthode je vais analyser chaque avis et voir si dans chaque avis, il y a les mots contenun dans le lexicon,
  si c'est le cas, je vais ajouter la polarité du mot au phrase, et par conséquent l'avis*/
void Analyse::charger_commentaires() {
    ifstream arch("commentaires.csv",ios::in);
    if(not arch.is_open()){
        cout<<"Le fichier commentaires.csv n'a pas pu etre ouvert";
        exit(1);
    }
    
    string restaurant, texte;
    while(true){
        /*J'initialise mon phrase et mot ici et je les charge*/
        Phrase phrase;
        getline(arch,restaurant,',');
        if(arch.eof())break;
        while(arch.get()!='\n'){
            string texte;
            arch>>texte;
            /*Puisqe parfoir les mots comporte des caractères tels que ! " (non alphanumériques)
             *  c'est important que je traite le mot*/
            traiter_mot(texte);
            auto it=lexicon.find(texte);
            if(it!=lexicon.end()){
                Mot mot;
                mot.SetPolarite(lexicon[texte]);
                mot.SetTexte(texte);
                /*Je mets le mots dans un stl vector contenu dans l'objet Phrase*/
                phrase.ajouter_mot(mot);
                
            }
            
        }
        /*J'ajoute les phrase dans le stl map contenu dans l'objet Analyse, avec tout l'information*/
        commentaires[restaurant].push_back(phrase);
        /*Pour pouvoir établir une qualification, je vais enregistrer le nombre d'opinions*/
        nombre_opinions[restaurant]=nombre_opinions[restaurant]+1;
    }
}

void Analyse::imprimer_analyse() {
    ofstream arch("rapport.txt",ios::out);
    if(not arch.is_open()){
        cout<<"Le fichier rapport.txt n'a pas pu etre ouvert";
        exit(1);
    }
    /*Je commence à imprimer les qualifications*/
    arch<<endl<<"RAPPORT D'AVIS DES RESTAURANTS"<<endl;
    for(int i=0;i<120;i++)arch<<"-";
    arch<<endl;
    /*Pour pouvir parcourir les stl, je vais utiliser des iterateurs*/
    for ( auto it = commentaires.begin();it!=commentaires.end();it++) {
        double moyen;
        int score=0, nom_avis,score_phrase=0, qualification;
        /*Je trouve le quantité d'opinions*/
        nom_avis=nombre_opinions[it->first];
        arch<<"RESTAURANT: "<<it->first<<endl;
        arch<<setw(15)<<right<<"Total avis: "<<nom_avis<<endl;
        
        for(auto&  phrase: it->second ){
            /*J'additionne les scores*/
            phrase.charger_score(arch);
            score_phrase= score_phrase+phrase.GetScore_phrase();            
            
        }
        /*Je trouve le moyen*/
        moyen=score_phrase/nom_avis;
       
        
        /*Sur la base de ces données, je mets un message dans le rapport*/
        arch<<endl<<setw(50)<<right<<"La qualification moyen de le restaurant est: "<<moyen<<endl;
        if (moyen >= 17) {
            arch<<endl<<setw(80)<<right<<"Exceptionnel : Service et qualité de très haut niveau !              " << std::endl;
        } else if (moyen >= 15) {
            arch<<endl<<setw(80)<<right<<"Excellent : Très bon service, petites améliorations possibles.       " << std::endl;
        } else if (moyen >= 13) {
            arch<<endl<<setw(80)<<right<< "Très bien : Une expérience agréable, mais des points à corriger.    " << std::endl;
        } else if (moyen >= 11) {
            arch<<endl<<setw(80)<<right<< "Correct : Qualité moyenne, il y a des points à améliorer.           " << std::endl;
        } else if (moyen >= 9) {
            arch<<endl<<setw(80)<<right<< "Passable : Expérience mitigée, beaucoup d'améliorations nécessaires." << std::endl;
        } else {
            arch<<endl<<setw(80)<<right<< "Décevant : Très mauvaise expérience, à éviter.                      " << std::endl;
        }
        arch<<endl<<endl;
        for(int i=0;i<120;i++)arch<<"-";
        arch<<endl;

    }

}

void Analyse::traiter_mot(string &texte) {
    /*En utilisant la function isalpha, j'efface chaque caractère pas important*/
    for (int i = 0; texte[i]; i++) {
        if(!isalpha(texte[i])){
            texte[i]=' ';
        /*Puisque chaque mot dans le lexique est en minuscule, je dois m'assurer que chaque lettre le soit également.*/    
        }else texte[i]=tolower(texte[i]);
    }

}
