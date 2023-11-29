#pragma once


/**
* @file définit les structures de données utilisées pour représenter un graphe sous forme de liste d'adjacence et les fonctions qui permettent de manipuler ces structures. A noter qu'il y a probablement un problème avec les fonctions permettant de libérer la mémoire, causant une erreur valgrind (dont je n'ai pas toruvé la cause)
*/

/**
* @brief structure d'un élément d'une liste de liste d'adjacence
*/


typedef struct element_liste_sommets_arrivee {
    int sommet;
    double distance;
    struct element_liste_sommets_arrivee *suivant;
} element_liste_sommets_arrivee;


/**
* @brief structure d'une liste de liste d'adjacence
*/
typedef struct liste_sommets_arrivee {
    int nombre_sommets;
    element_liste_sommets_arrivee *premier;
} liste_sommets_arrivee;


/**
* @brief structure d'un élément d'une liste d'adjacence (c'est-à-dire une liste de sommets d'arrivée)
*/
typedef struct element_liste_adjacence {
    liste_sommets_arrivee *liste;
    struct element_liste_adjacence *suivant;
} element_liste_adjacence;


/**
* @brief structure d'une liste d'adjacence
*/
typedef struct liste_adjacence {
    int nombre_sommets_graphe;
    element_liste_adjacence *premier;
} liste_adjacence;







/**
* @brief crée une liste de sommets d'arrivée (une liste parmi la liste d'adjacence)
* @return liste de sommets d'arrivée (vide)
*/
liste_sommets_arrivee * creer_liste_sommets_arrivee(void);



/**
* @brief ajoute un sommet à la liste de sommets d'arrivée
* @param liste liste de sommets d'arrivée
* @param sommet sommet à ajouter
* @param distance distance entre le sommet de départ (indice de la liste liste dans la liste d'adjacence) et le sommet d'arrivée (celui ajouté)
*/
void append_liste_sommets_arrivee(liste_sommets_arrivee *liste, int sommet, double distance);




/**
* @brief crée une liste d'adjacence
* @return liste d'adjacence (vide, ne contient qu'un pointeur null)
*/
liste_adjacence * creer_liste_adjacence(void);

/** 
* @brief ajoute une liste de sommets d'arrivée à la liste d'adjacence
* @param liste liste d'adjacence
*/
void ajouter_liste_sommets_arrivee_vide(liste_adjacence *liste);

/** 
* @brief crée une liste d'adjacence d'un graphe à n sommets
* @param n nombre de sommets du graphe
* @return liste d'adjacence contenant n listes de sommets d'arrivée vides (chacune de ces listes ne contient qu'un pointeur null)
*/

liste_adjacence * creer_liste_adjacence_a_n_sommets(int n);


/** 
* @brief ajoute un sommet à la liste de sommets d'arrivée correspondant au sommet de départ i (celui à la ième place dans la liste d'adjacence) de la liste d'adjacence
* @param liste liste d'adjacence
* @param sommet sommet à ajouter (sommet d'arrivée)
* @param distance distance entre le sommet de départ (indice de la liste liste dans la liste d'adjacence) et le sommet d'arrivée (celui ajouté)
* @param i indice du sommet de départ (indice de la liste liste dans la liste d'adjacence)
*/
void ajouter_sommet_liste_adjacence(liste_adjacence *liste, int sommet, double distance, int i);


/** 
* @brief stocke la liste d'adjacence dans un fichier
* @param liste liste d'adjacence
* @param nom_fichier nom du fichier dans lequel stocker la liste d'adjacence
*/


void stocker_liste_adjacence(liste_adjacence *liste, char *nom_fichier);



/** 
* @brief free la liste de sommets d'arrivée
* @param list liste de sommets d'arrivée
*/
void free_liste_sommets_arrivee(liste_sommets_arrivee *list);

/** 
* @brief free la liste d'adjacence
* @param list liste d'adjacence
*/
void free_liste_adjacence(liste_adjacence *list);
