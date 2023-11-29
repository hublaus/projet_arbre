#pragma once
#include "graphe.h"
#include "liste_aretes.h"
#include "ligne_de_commande_arbre_couvrant.h"
#include "emplacement.h"

/**
* @brief sauvegarde la liste d'adjacence dans un fichier texte (NE MARCHE PAS !!!)
* @param liste_aretes_arbre_couvrant_de_poids_minimal tableau contenant les arêtes de l'arbre couvrant de poids minimal (en entrée)
* @param opt pointeur sur la structure options contenant les options de l'utilisateur
* @return ne renvoie rien, mais sauvegarde la liste d'adjacence dans un fichier texte
*/
void sauvegarde_liste_adjacence(arete *liste_aretes_arbre_couvrant_de_poids_minimal, options *opt);


/**
* @brief sauvegarde la liste des arêtes de l'arbre couvrant de poids minimal dans un fichier texte
* @param liste_aretes_arbre_couvrant_de_poids_minimal tableau contenant les arêtes de l'arbre couvrant de poids minimal (en entrée)
* @param opt pointeur sur la structure options contenant les options de l'utilisateur
* @return ne renvoie rien, mais sauvegarde la liste des arêtes de l'arbre couvrant de poids minimal dans un fichier texte
*/

void sauvegarde_liste_emplacements_arbres(emplacement *tableau_emplacement, options *opt);