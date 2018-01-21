//
//  BandePassante.hpp
//  archiOS
//
//  Created by Grace on 30/12/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#ifndef BandePassante_hpp
#define BandePassante_hpp

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <sys/time.h>

#define MAX_TAILLE_DATA_KO 4096 // = 4 Mo
#define CACHE_LINE_SIZE 32  // remplacez ici par la taille de votre ligne cache

#define CACHE_L1 32
#define CACHE_L2 256
#define CACHE_L3 3072

#define NBRE_REPETITION 9

class BandePassante {
    
public:
    BandePassante();
    
    int double_cache = (CACHE_L1 + CACHE_L2 + CACHE_L3) * 2; // La taille de notre cache
    int tab[(MAX_TAILLE_DATA_KO * 1024)/sizeof(int)];   // tableau des donnees accedees
    int i = 0;  // un compteur de boucle simple
    int j = 0;  // compteur pour repeter une expérience
    int taille_data = 0;    // qui correspond a la taille totale des donnees accedees en Ko
    int nbdonnee = 0;   // = (taille_data * 1024) / sizeof(int)
    struct timeval t1, t2;  // variables utilisees pour mesurer le temps d’execution
    int pas = double_cache / sizeof(int);    // nombre de donnees de type int dans une ligne cache
    float temps_acces_moyen = 0;    // en microsecondes
    int x;

    int data_min ;
};

#endif /* BandePassante_hpp */
