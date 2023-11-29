#pragma once

/**
* @brief structure stockant les options de la ligne de commande pour l'action arbre_couvrant
*/

typedef struct options{
    int nombre_arbres;
    char *nom_fichier_binaire_entree;
    char* nom_fichier_liste_adjacence_sortie;
    int affichage_graphique;
    char *nom_fichier_liste_aretes_sortie;
    char *nom_fichier_liste_emplacements_arbres_sortie;

    } options;


/**
* @brief traite les arguments de la ligne de commande pour l'action arbre_couvrant
* @param argc nombre d'arguments de la ligne de commande
* @param argv tableau contenant les arguments de la ligne de commande
* @param opt pointeur sur la structure options dans laquelle seront stockées les options de l'utilisateur
*/
void traitement_arguments_ligne_de_commande(int argc, char **argv, options *opt);