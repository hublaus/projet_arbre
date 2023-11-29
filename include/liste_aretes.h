#pragma once
#include <stdio.h>

/**
* @brief structure stockant une arête
* @param depart numéro de l'arbre de départ
* @param arrivee numéro de l'arbre d'arrivée
* @param distance distance entre les deux arbres (en kilomètres)
*/
typedef struct arete {
    int depart;
    int arrivee;
    double distance;
} arete;

/**
* @brief structure stockant un élément d'une liste d'arêtes
* @param ar arête
* @param next pointeur vers l'élément suivant
*/
typedef struct ll_node {
    arete ar;
    struct ll_node *next;
} ll_node;

/**
* @brief structure stockant une liste d'arêtes
* @param first pointeur vers le premier élément de la liste
* @param taille taille de la liste
*/
typedef struct liste_aretes{
    ll_node *first;
    int taille;
} liste_aretes;


/**
* @brief crée une liste vide
* @return liste vide (pointeur vers NULL), taille = 0
*/
liste_aretes * ll_create(void);

/** 
* @brief ajoute un élément à la fin de la liste contenant l'arête a
* @param list liste d'arêtes
* @param a arête à ajouter
*/
void ll_append(liste_aretes *list, arete a);

/**
* @brief ajoute un élément au début de la liste contenant l'arête a
* @param list liste d'arêtes
* @param a arête à ajouter
*/
void ll_prepend(liste_aretes *list, arete a);


/** 
* @brief accède à l'élément d'indice i
* @param list liste d'arêtes
* @param i indice de l'élément à accéder
* @return l'élément d'indice i (ou une erreur si i est supérieur à la taille de la liste)
*/
arete ll_get(const liste_aretes *list, unsigned int i);


/** 
* @brief libère la liste
* @param list liste d'arêtes
*/
void ll_free(liste_aretes *list);


/**
* @brief accède au premier élément
* @param list liste d'arêtes
* @return la première arête de la liste
*/

arete ll_first(liste_aretes *list);

/** 
* @brief accède au dernier élément
* @param list liste d'arêtes
* @return la dernière arête de la liste
*/
arete ll_last(liste_aretes *list);


/**
* @brief renvoie la taille de la liste
* @param list liste d'arêtes
* @return taille de la liste
*/
int ll_size(liste_aretes*list);

/**
* @brief retire le dernier élément
* @param list liste d'arêtes
*/

void ll_pop_last(liste_aretes*list);

/**
* @brief retire le premier élément
* @param list liste d'arêtes
*/
void ll_pop_first(liste_aretes*list);

/**
* @brief insère une arête à l'indice idx
* @param list liste d'arêtes
* @param a arête à insérer
* @param idx indice où insérer l'arête
*/
void ll_insert(liste_aretes*list, arete a, int idx);

/**
* @brief retire l'arête à l'indice idx
* @param list liste d'arêtes
* @param idx indice de l'arête à retirer
*/
void ll_remove(liste_aretes*list, int idx);

/**
* @brief modifie l'arête à l'indice idx
* @param list liste d'arêtes
* @param a nouvelle arête
* @param idx indice de l'arête à modifier
*/
void ll_set(liste_aretes*list, arete a, int idx);


/**
* @brief affiche une arête dans un fichier
* @param a arête à afficher
* @param fichier fichier dans lequel afficher l'arête
* @param distance_totale pointeur vers la distance totale parcourue (pour l'affichage global d'un tableau d'arêtes)
*/
void afficher_arete (arete a, FILE *fichier, double *distance_totale);

/**
* @brief affiche un tableau d'arêtes dans un fichier
* @param tableau_aretes tableau d'arêtes à afficher
* @param taille taille du tableau
* @param nom_fichier nom du fichier dans lequel afficher le tableau d'arêtes
*/
void afficher_tableau_arete (arete *tableau_aretes, int taille, char *nom_fichier);
