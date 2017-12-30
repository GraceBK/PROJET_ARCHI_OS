//
//  TailleCache.hpp
//  archiOS
//
//  Created by Grace on 30/12/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#ifndef TailleCache_hpp
#define TailleCache_hpp

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <sys/time.h>

#define MAX_TAILLE_DATA_KO 4096 // = 4 Mo
#define CACHE_LINE_SIZE 32  // remplacez ici par la taille de votre ligne cache

class TailleCache {
    
public:
    TailleCache();
    
    int tab[(MAX_TAILLE_DATA_KO * 1024)/sizeof(int)];   // tableau des donnees accedees
    int i;  // un compteur de boucle simple
    int j;  // compteur pour repeter une expérience
    int taille_data;    // qui correspond a la taille totale des donnees accedees en Ko
    int nbdonnee;   // = (taille_data * 1024) / sizeof(int)
    struct timeval t1, t2;  // variables utilisees pour mesurer le temps d’execution
    int pas = CACHE_LINE_SIZE / sizeof(int);    // nombre de donnees de type int dans une ligne cache
    float temps_acces_moyen;    // en microsecondes
    int x;
};

#endif /* TailleCache_hpp */
