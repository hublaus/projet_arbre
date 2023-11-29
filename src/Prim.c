#include "Prim.h"
#include "liste_aretes.h"
#include "emplacement.h"
#include "fonctions_liste_aretes_pour_Prim.h"

void Prim(arete *liste_aretes_arbre_couvrant_de_poids_minimal, options* opt, emplacement* tableau_emplacement){

    liste_aretes *liste_aretes_Prim = initialisation_liste_aretes(opt->nombre_arbres - 1 , tableau_emplacement);
    arete arete_minimale;
    int dernier_sommet_ajoute;
    int nombre_arbres_moins_un = opt->nombre_arbres - 1;




    for (int i = 0; i < nombre_arbres_moins_un; i++){

        arete_minimale = arete_de_poids_minimum(liste_aretes_Prim);

        liste_aretes_arbre_couvrant_de_poids_minimal[i] = arete_minimale;

        //ajouter test
        supprimer_arete_de_la_liste(liste_aretes_Prim, arete_minimale);

        dernier_sommet_ajoute = arete_minimale.arrivee;

        for (int indice_liste = 0; indice_liste < liste_aretes_Prim->taille; indice_liste++){

            arete arete_actuelle = ll_get (liste_aretes_Prim, indice_liste);

            arete arete_potentielle;
            arete_potentielle.depart = dernier_sommet_ajoute;
            arete_potentielle.arrivee = arete_actuelle.arrivee;
            arete_potentielle.distance = distance_entre_deux_emplacements( tableau_emplacement [arete_potentielle.depart]  , tableau_emplacement [arete_potentielle.arrivee] );


            if (arete_potentielle.distance < arete_actuelle.distance){
                ll_set(liste_aretes_Prim, arete_potentielle, indice_liste);

            }
        }


    }
ll_free(liste_aretes_Prim);
return;
}