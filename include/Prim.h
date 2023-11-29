#pragma once
#include "liste_aretes.h"
#include "ligne_de_commande_arbre_couvrant.h"
#include "emplacement.h"

/**
* @brief Prim : algorithme de Prim pour calculer l'arbre couvrant de poids minimal
* @param liste_aretes_arbre_couvrant_de_poids_minimal tableau contenant les arêtes de l'arbre couvrant de poids minimal (en sortie)
* @param opt pointeur sur la structure options contenant les options de l'utilisateur
* @param tableau_emplacement tableau contenant les emplacements (en entrée)
* @return ne renvoie rien, mais modifie le tableau liste_aretes_arbre_couvrant_de_poids_minimal pour conserver la liste des arêtes de l'arbre couvrant de poids minimal
*/

void Prim(arete *liste_aretes_arbre_couvrant_de_poids_minimal, options* opt, emplacement* tableau_emplacement);