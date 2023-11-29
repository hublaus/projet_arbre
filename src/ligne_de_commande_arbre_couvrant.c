#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ligne_de_commande_arbre_couvrant.h"

void traitement_arguments_ligne_de_commande(int argc, char **argv , options* opt){
    int c;

    opt->nom_fichier_liste_adjacence_sortie = NULL;
    opt->nom_fichier_liste_aretes_sortie = NULL;
    opt->nom_fichier_liste_emplacements_arbres_sortie = NULL;
    opt->affichage_graphique = 0;

    while ((c = getopt (argc, argv, "n:o:as:v:e:")) != -1)
        switch (c){
            case 'n':
                opt->nombre_arbres = atoi(optarg);
                break;
            case 'o':
                opt->nom_fichier_binaire_entree = optarg;
                break;
            case 'a':
                opt->affichage_graphique = 1;
                break;
            case 's':
                opt->nom_fichier_liste_adjacence_sortie = optarg;
                break;
            case 'v':
                opt->nom_fichier_liste_aretes_sortie = optarg;
                break;
            case 'e':
                opt->nom_fichier_liste_emplacements_arbres_sortie = optarg;
                break;
            
            
            
        }

    return;

}