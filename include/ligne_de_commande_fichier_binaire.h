#pragma once

/**
* @brief structure stockant les options de la ligne de commande pour l'action bin/fichier_binaire
*/

typedef struct options{
    int nombre_arbres;
    char *nom_fichier_entree;
    char *nom_fichier_sortie;
    int verification;
    } options;

/**
* @brief traite les arguments de la ligne de commande pour l'action bin/fichier_binaire
* @param argc nombre d'arguments de la ligne de commande
* @param argv tableau contenant les arguments de la ligne de commande
* @param opt pointeur sur la structure options dans laquelle seront stockées les options de l'utilisateur
*/
void traitement_arguments_ligne_de_commande(int argc, char **argv, options *opt);