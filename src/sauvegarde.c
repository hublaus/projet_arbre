#include "sauvegarde.h"
#include "graphe.h"
#include "liste_aretes.h"
#include "ligne_de_commande_arbre_couvrant.h"
#include "emplacement.h"
#include <stdlib.h>
#include <string.h>

void sauvegarde_liste_adjacence(arete *liste_aretes_arbre_couvrant_de_poids_minimal, options *opt){

    char chemin_liste_adjacence[100] = "sauvegarde_arbre_couvrant/";
    strcat(chemin_liste_adjacence, opt->nom_fichier_liste_adjacence_sortie);

    liste_adjacence *graphe = creer_liste_adjacence_a_n_sommets(opt->nombre_arbres);
    int nombre_arbres_moins_un = opt->nombre_arbres - 1;

    for (int i = 0; i < nombre_arbres_moins_un; i++){
        arete arete_actuelle = liste_aretes_arbre_couvrant_de_poids_minimal[i];
        ajouter_sommet_liste_adjacence(graphe, arete_actuelle.arrivee, arete_actuelle.distance, arete_actuelle.depart);
        ajouter_sommet_liste_adjacence(graphe, arete_actuelle.depart, arete_actuelle.distance, arete_actuelle.arrivee);
    }
    stocker_liste_adjacence(graphe, chemin_liste_adjacence); 
    free_liste_adjacence(graphe);
    return;
}

void sauvegarde_liste_emplacements_arbres(emplacement *tableau_emplacement, options *opt){
    char chemin_emplacement[100] = "sauvegarde_arbre_couvrant/";
    strcat(chemin_emplacement, opt->nom_fichier_liste_emplacements_arbres_sortie);

    FILE *fichier = fopen(chemin_emplacement, "w");
    if (fichier == NULL){
        printf("Erreur lors de l'ouverture du fichier\n");
        exit(1);
    }
    for (int i = 0; i < opt->nombre_arbres; i++){
        fprintf(fichier, "%d %lf,%lf\n", i, tableau_emplacement[i].longitude, tableau_emplacement[i].latitude);
    }
    return;
}