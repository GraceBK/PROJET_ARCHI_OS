//
//  TailleCache.cpp
//  archiOS
//
//  Created by Grace on 30/12/2017.
//  Copyright © 2017 Grace BOUKOU. All rights reserved.
//

#include "TailleCache.hpp"

TailleCache::TailleCache() {
    int cls = CACHE_LINE_SIZE;
    for (taille_data = cls; taille_data <= MAX_TAILLE_DATA_KO * 1024; taille_data = taille_data + cls) {
        nbdonnee = (taille_data) / sizeof(int);
        for (i = 0; i < nbdonnee; i = i + pas) {    // boucle simple qui pre-charge les donnees dans le cache L1
            x = x + tab[i];
        }   // end for i
        gettimeofday(&t1, NULL);    // recuperer ici la valeur de l’horloge juste avant la boucle
        for (i = 0; i < nbdonnee; i = i + pas) {    // boucle qui accede aux lignes cache, avec un pas d’acces
            x = x + tab[i];
        }   // end for i
        gettimeofday(&t2, NULL);    // recuperer ici la valeur de l’horloge a la fin de la boucle
        
        // convertir le temps ecoule en microsecondes
        temps_acces_moyen = (float) ((t2.tv_sec - t1.tv_sec) * 1000000 + t2.tv_usec - t1.tv_usec) / (nbdonnee / pas);
//        printf("Le temps d'acces moyen est de \%f microsecondes lorsque la taille totale des donnees accedees est de \%d Ko\n", temps_acces_moyen, taille_data);
//        std::cout << "Le temps d'acces moyen est de "<< temps_acces_moyen << " microsecondes lorsque la taille totale des donnees accedees est de " << taille_data <<" Ko" << std::endl;
        std::cout << taille_data << "    " << temps_acces_moyen << std::endl;
    }
}   // end for taille_data
