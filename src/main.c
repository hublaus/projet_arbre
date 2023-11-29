#include <stdio.h>
#include <stdlib.h>
#include "ligne_de_commande_arbre_couvrant.h"
#include "emplacement.h"
#include "liste_aretes.h"
#include "graphe.h"
#include "affichage.h"
#include <string.h>
#include "sauvegarde.h"
#include "Prim.h"
#include "entree.h"


int main(int argc, char **argv){

    options opt;

    traitement_arguments_ligne_de_commande(argc, argv, &opt);

    emplacement *tableau_emplacement = lecture_fichier_binaire(&opt);




    if (opt.nom_fichier_liste_emplacements_arbres_sortie != NULL){

        sauvegarde_liste_emplacements_arbres(tableau_emplacement, &opt);
    }

    
    
    
    
    int nombre_arbres_moins_un = opt.nombre_arbres - 1;
    arete *liste_aretes_arbre_couvrant_de_poids_minimal = malloc(sizeof(arete)*nombre_arbres_moins_un);


    Prim(liste_aretes_arbre_couvrant_de_poids_minimal , &opt, tableau_emplacement);






    if (opt.nom_fichier_liste_adjacence_sortie != NULL){
        sauvegarde_liste_adjacence(liste_aretes_arbre_couvrant_de_poids_minimal, &opt);
    }

    if (opt.nom_fichier_liste_aretes_sortie != NULL){
        char chemin_liste_aretes[100]= "sauvegarde_arbre_couvrant/";
        strcat(chemin_liste_aretes, opt.nom_fichier_liste_aretes_sortie);
        afficher_tableau_arete(liste_aretes_arbre_couvrant_de_poids_minimal, nombre_arbres_moins_un, chemin_liste_aretes);
        }

    if (opt.affichage_graphique){
        affichage(tableau_emplacement, opt.nombre_arbres, liste_aretes_arbre_couvrant_de_poids_minimal);
    }











    free(liste_aretes_arbre_couvrant_de_poids_minimal);

    free(tableau_emplacement);




    return 0;
}



