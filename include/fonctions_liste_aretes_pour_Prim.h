#pragma once
#include "liste_aretes.h"
#include "emplacement.h"


/**
* @brief initialise la liste d'arêtes utilisées pour l'algorithme de Prim
* @param n nombre d'arbres
* @param tableau_emplacement tableau contenant les emplacements
* @return liste_aretes liste d'arêtes initialisée : pour chaque élément, l'arbre de départ est initialisé à 0, celui d'arrivée à son numéro d'ordre d'arrivée (de 1 à n), et la distance est la distance entre l'arbre 0 et l'arbre d'arrivée
*/
liste_aretes* initialisation_liste_aretes (int n, emplacement *tableau_emplacement);


/**
* @brief renvoie l'arête de poids minimum de la liste d'arêtes
* @param liste_aretes liste d'arêtes
* @return arete de poids minimum
*/
arete arete_de_poids_minimum(liste_aretes *liste_aretes);


/**
* @brief supprime une arête a de la liste d'arêtes
* @param liste_aretes liste d'arêtes
* @param a arête à supprimer
*/
void supprimer_arete_de_la_liste(liste_aretes *liste_aretes, arete a);
