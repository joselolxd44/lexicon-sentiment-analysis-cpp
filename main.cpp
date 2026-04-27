/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 51969
 *
 * Created on 11 de diciembre de 2024, 21:24
 */

#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <vector>

#include "Analyse.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Analyse analyse;
    
    analyse.charger_lexicon();
    analyse.charger_commentaires();
    analyse.imprimer_analyse();
    return 0;
}

