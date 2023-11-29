#include "fonctions_liste_aretes_pour_Prim.h"
#include "emplacement.h"
#include "liste_aretes.h"
#include <stdio.h>



liste_aretes* initialisation_liste_aretes (int n, emplacement* tableau_emplacement){


    liste_aretes *list = ll_create();



    arete a;
    a.depart = 0;




    for (int i=1 ; i<=n ; i++){
        a.arrivee = i;
        a.distance = distance_entre_deux_emplacements(tableau_emplacement[0],tableau_emplacement[i]);
        ll_append(list,a);
    }
    return list;
}







arete arete_de_poids_minimum(liste_aretes *liste_aretes){

    int taille = liste_aretes->taille ;
    int indice_minimum = 0;
    float minimum = ll_get(liste_aretes,0).distance;

    arete arete_actuelle;



    for (int i=1 ; i<taille ; i++){

        arete_actuelle = ll_get(liste_aretes,i);


        if (arete_actuelle.distance < minimum){
            minimum = arete_actuelle.distance;
            indice_minimum = i;
        }
    }

    arete arete_minimum = ll_get(liste_aretes,indice_minimum);
    return arete_minimum;



}



void supprimer_arete_de_la_liste(liste_aretes *liste_aretes, arete a){

    int taille = liste_aretes->taille ;
    int indice_a_supprimer = 0;
    arete arete_actuelle;

    for (int i=0 ; i<taille ; i++){

        arete_actuelle = ll_get(liste_aretes,i);

        if (arete_actuelle.depart == a.depart && arete_actuelle.arrivee == a.arrivee){
            indice_a_supprimer = i;
        }
    }

    ll_remove(liste_aretes,indice_a_supprimer);

}
