#pragma once
#include "emplacement.h"
#include "liste_aretes.h"

/**
*@brief structure stockant les coordonnées d'un emplacement, converties en pixels (pour l'affichage)
*/

typedef struct  emplacement_converti_en_pixels{
    int x;
    int y;
} emplacement_converti_en_pixels;


/**
*@brief convertit les coordonnées des emplacements en pixels
*@param tableau_emplacement tableau contenant les emplacements
*@param nombre_sommets nombre d'emplacements
*@param liste_arete_MST tableau contenant les aretes de l'arbre couvrant de poids minimum
*/
void affichage(emplacement* tableau_emplacement, int nombre_sommets , arete *liste_aretes_MST);