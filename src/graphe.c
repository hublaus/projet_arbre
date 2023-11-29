#include "graphe.h"
#include <stdlib.h>
#include <stdio.h>

liste_sommets_arrivee * creer_liste_sommets_arrivee(void){
    liste_sommets_arrivee * list = malloc(sizeof(liste_sommets_arrivee));
    if (list == NULL){//test malloc
        fprintf(stderr,"Erreur allocation mémoire\n");
        exit (1); 
        }
    list->premier = NULL;

    list->nombre_sommets = 0;
    return list;
}


void append_liste_sommets_arrivee(liste_sommets_arrivee *liste, int sommet, double distance){
    liste->nombre_sommets = (liste->nombre_sommets) + 1;

    element_liste_sommets_arrivee *nouveau_sommet = malloc(sizeof(element_liste_sommets_arrivee));
    if(nouveau_sommet == NULL) {
        fprintf(stderr, "Allocation error in ll_append\n");
        exit(1);
    }
    nouveau_sommet->suivant = NULL;
    nouveau_sommet->sommet = sommet;
    nouveau_sommet->distance = distance;

    if(liste->premier == NULL) {
        liste->premier = nouveau_sommet;
        return;
    }

    element_liste_sommets_arrivee *it = liste->premier;
    while(it->suivant != NULL) {
        it = it->suivant;
    }
    it->suivant = nouveau_sommet;


}



liste_adjacence * creer_liste_adjacence(void){
    liste_adjacence * list = malloc(sizeof(liste_adjacence));
    if (list == NULL){//test malloc
        fprintf(stderr,"Erreur allocation mémoire\n");
        exit (1); 
        }
    list->premier = NULL;

    return list;
}

void ajouter_liste_sommets_arrivee_vide(liste_adjacence *liste){
    element_liste_adjacence *nouvel_element = malloc(sizeof(element_liste_adjacence));
    if(nouvel_element == NULL) {
        fprintf(stderr, "Allocation error in ll_append\n");
        exit(1);
    }
    nouvel_element->suivant = NULL;
    nouvel_element->liste = creer_liste_sommets_arrivee();

    if(liste->premier == NULL) {
        liste->premier = nouvel_element;
        return;
    }

    element_liste_adjacence *it = liste->premier;
    while(it->suivant != NULL) {
        it = it->suivant;
    }
    it->suivant = nouvel_element;
}


liste_adjacence * creer_liste_adjacence_a_n_sommets(int n){
    liste_adjacence * liste = creer_liste_adjacence();
    for(int i = 0; i < n; i++){
        ajouter_liste_sommets_arrivee_vide(liste);
    }
    return liste;
}


void ajouter_sommet_liste_adjacence(liste_adjacence *liste, int sommet, double distance, int i){
    element_liste_adjacence *it = liste->premier;
    for(int j = 0; j < i; j++){
        it = it->suivant;
    }
    append_liste_sommets_arrivee(it->liste, sommet, distance);
}

void stocker_liste_adjacence(liste_adjacence *liste, char *nom_fichier){
    FILE *fichier = fopen(nom_fichier, "w");
    if (fichier == NULL){
        fprintf(stderr, "Erreur ouverture fichier\n");
        exit(1);
    }
    element_liste_adjacence *it = liste->premier;
    int i = 0;
    //sécurité pour éviter boucle infinie
    while ( (i<liste->nombre_sommets_graphe) && (it != NULL) ){
        fprintf(fichier, "départ %d    ", i);
        element_liste_sommets_arrivee *it2 = it->liste->premier;
        while(it2 != NULL){
            fprintf(fichier, "%d %lf", it2->sommet, it2->distance);
            it2 = it2->suivant;
        }
        fprintf(fichier,"\n");
        it = it->suivant;
        i++;
    }
    fclose(fichier);
    return;
}

void free_liste_sommets_arrivee(liste_sommets_arrivee *list){
//cas liste non existante (list=NULL, list-> first n'existe pas)
    if (list==NULL){
        return;
    }

//cas liste vide
    element_liste_sommets_arrivee *pointeur = list->premier;
    if (pointeur == NULL){
        free(list);
        return;
    }
    int taille = list->nombre_sommets;

    element_liste_sommets_arrivee *tableau[taille];
    pointeur = list->premier;
    int compteur=0;

    while (pointeur->suivant != NULL){
        tableau[compteur]=pointeur;
        pointeur = pointeur->suivant;
        compteur++;
    }
    //le dernier pointeur non nul n'est pas libéré (dernière étape à rajouter)

    for(int k=taille-1 ; k>=0; k--){
        free(tableau[k]);
    }
    free(list);
     

    return;
}


void free_liste_adjacence(liste_adjacence *list){

    int taille = list->nombre_sommets_graphe;

    element_liste_adjacence *tableau[taille];
    element_liste_adjacence *pointeur = list->premier;
    int compteur=0;

    while (pointeur->suivant != NULL){
        tableau[compteur]=pointeur;
        pointeur = pointeur->suivant;
        compteur++;
    }

    for(int k=taille-1 ; k>=0; k--){
        free_liste_sommets_arrivee(tableau[k]->liste);
        free(tableau[k]);
    }
    free(list);
     

    return;
}