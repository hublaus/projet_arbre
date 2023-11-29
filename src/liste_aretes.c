#include <stdio.h>
#include <stdlib.h>
#include "liste_aretes.h"








liste_aretes * ll_create(void) {
    liste_aretes * list = malloc(sizeof(liste_aretes));
    if (list == NULL){//test malloc
        fprintf(stderr,"Erreur allocation mémoire\n");
        exit (1); 
        }
    list->first = NULL;

    list->taille = 0;
    return list;
}

void ll_append(liste_aretes *list, arete a) {

    list->taille = (list->taille) + 1;

    ll_node * new_element = malloc(sizeof(ll_node));
    if(new_element == NULL) {
        fprintf(stderr, "Allocation error in ll_append\n");
        exit(1);
    }
    new_element->next = NULL;
    new_element->ar = a;

    if(list->first == NULL) {
        list->first = new_element;
        return;
    }

    ll_node *it = list->first;
    while(it->next != NULL) {
        it = it->next;
    }
    it->next = new_element;
}

arete ll_get(const liste_aretes *list, unsigned int value_idx) {
    if(value_idx >= list->taille) {
        fprintf(stderr, "Index out of bounds in ll_get\n");
        exit(1);
    }

    ll_node *it = list->first;

    for(unsigned int i = 0; i < value_idx; i++) {
        it = it->next;
    }
    return it->ar;
}

int ll_size( liste_aretes *list) {
    return list->taille;
}


void ll_free(liste_aretes *list) {
//cas liste non existante (list=NULL, list-> first n'existe pas)
    if (list==NULL){
        return;
    }

//cas liste vide
    ll_node *pointeur = list->first;
    if (pointeur == NULL){
        free(list);
        return;
    }
    int taille = ll_size(list);

    ll_node *tableau[taille];
    pointeur = list->first;
    int compteur=0;

    while (pointeur->next != NULL){
        tableau[compteur]=pointeur;
        pointeur = pointeur->next;
        compteur++;
    }
    //le dernier pointeur non nul n'est pas libéré (dernière étape à rajouter)
    tableau[compteur]=pointeur;

    for(int k=taille-1 ; k>=0; k--){
        free(tableau[k]);
    }
    free(list);
     

    return;
}




void ll_prepend(liste_aretes *list,arete a){

    list->taille = (list->taille) +1;

    ll_node *new_element = malloc(sizeof(ll_node));
    new_element->ar = a;
    if(new_element == NULL) {
        fprintf(stderr, "Allocation error in ll_append\n");
        exit(1);
    }
    if(list->first == NULL) {
        list->first = new_element;
        return;
    }
    new_element->next = list->first;
    list->first = new_element;



    return ;
}

arete ll_first(liste_aretes *list) {
    return list->first->ar;

}

arete ll_last(liste_aretes *list) {
    ll_node *pointeur=list->first;
    while(pointeur->next != NULL){
        pointeur = pointeur->next;
    }
    return pointeur->ar;

}

void ll_pop_last(liste_aretes *list) {
    ll_node *pointeur = list->first;
    ll_node *pre;
    while(pointeur->next != NULL){
        pre=pointeur;
        pointeur = pointeur->next;
    }
    free(pointeur);
    pre->next=NULL;

    list->taille = (list->taille) -1;
    return;

}

void ll_pop_first(liste_aretes *list) {
    

    ll_node *pointeur = list->first;
    ll_node *sauvegarde = list->first->next;
    free(pointeur);
    list->first = sauvegarde;

    list->taille = (list->taille) -1;
    return;

}

void ll_remove(liste_aretes *list, int idx){

    if (idx ==0){
        ll_pop_first(list);
        return;
    }


    ll_node *precedent_precedent = list->first;
    for (int i = 0 ; i<idx-1 ; i++){
        precedent_precedent = precedent_precedent->next;
    }
    ll_node *precedent = precedent_precedent->next;


    ll_node *sauvegarde = precedent->next; 
    free(precedent);
    precedent_precedent->next = sauvegarde;

    list->taille = (list->taille)-1;
    }



void ll_insert(liste_aretes *list, arete a, int idx){


    if (idx == 0){
        ll_prepend(list,a);
    }

    list->taille = (list-> taille + 1);



    ll_node *new_element = malloc(sizeof(ll_node));
    if(new_element == NULL) {
        fprintf(stderr, "Allocation error in ll_append\n");
        exit(1);
    }
    new_element->ar = a;




    ll_node *precedent_precedent = list->first;
    for (int i=1 ; i<idx ; i++){
        precedent_precedent = precedent_precedent->next;
    }
    ll_node *precedent = precedent_precedent->next;


    ll_node *sauvegarde = precedent;
    precedent_precedent->next = new_element;
    new_element->next = sauvegarde;
    
 
}


void ll_set(liste_aretes*list, arete a, int idx){
    ll_node *pointeur = list->first;
    for (int i=0 ; i<idx ; i++){
        pointeur = pointeur->next;
    }
    pointeur->ar = a;
    return;
}


void afficher_arete (arete a, FILE *fichier, double *distance_totale){
    *distance_totale = *distance_totale + a.distance;
    fprintf(fichier,"arete de poids %lf entre les sommets %d et %d\n",a.distance,a.depart,a.arrivee);
}

void afficher_tableau_arete (arete *tableau_aretes, int taille, char *nom_fichier){

    double distance_totale=0.0;
    FILE *fichier = fopen(nom_fichier,"w");
    if (fichier == NULL){
        printf("erreur ouverture fichier\n");
        return;
    }
    for (int i=0 ; i<taille ; i++){
        afficher_arete(tableau_aretes[i], fichier, &distance_totale);
    }
    fprintf(fichier,"distance totale : %lf kilomètres\n",distance_totale);
    return;
}
