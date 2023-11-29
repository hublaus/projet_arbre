#include "entree.h"
#include "emplacement.h"
#include "ligne_de_commande_arbre_couvrant.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

emplacement* lecture_fichier_binaire(options *opt){
    char chemin[100] = "sauvegarde_fichier_binaire/";
    strcat(chemin, opt->nom_fichier_binaire_entree);

    FILE *fichier_binaire = fopen(chemin, "rb");
    if (fichier_binaire == NULL){
        fprintf(stderr,"Erreur d'ouverture du fichier\n");
        exit (1);
    }


    emplacement *tableau_emplacement = malloc(opt->nombre_arbres * sizeof(emplacement));
    if (tableau_emplacement == NULL){
        fprintf(stderr,"Erreur allocation mémoire\n");
        exit (1);
    }

    fread(tableau_emplacement, sizeof(emplacement), opt->nombre_arbres, fichier_binaire);
    fclose(fichier_binaire);

    return tableau_emplacement;
}