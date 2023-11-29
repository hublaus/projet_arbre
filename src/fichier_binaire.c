#include <stdio.h>
#include <stdlib.h>
#include "ligne_de_commande_fichier_binaire.h"
#include "emplacement.h"
#include <string.h>



int main(int argc, char **argv){


    //int nombre_arbres = 50;

    options opt;

    traitement_arguments_ligne_de_commande(argc, argv, &opt);

    FILE *fichier_entree = fopen(opt.nom_fichier_entree, "r");
    if (fichier_entree == NULL){
        fprintf(stderr,"Erreur d'ouverture du fichier. Le fichier d'entrée doit être écrit sous la forme chemin_relatif_vers_ce_fichier_depuis_creation_fichier_binaire/nom\n");
        exit (1);
    }

    char chemin[100] = "sauvegarde_fichier_binaire/";
    strcat(chemin, opt.nom_fichier_sortie);

    FILE *fichier_sortie = fopen(chemin, "wba");
    if (fichier_sortie == NULL){
        fprintf(stderr,"Erreur écriture du fichier\n");
        exit (1);
    }



    char caractere=0;
    int compteur_separateur;
    emplacement emplacement_arbre;
    //char nombre[10];

    //passage première ligne
    while (caractere != '\n'){
        caractere = fgetc(fichier_entree);
    }

    for (int i = 0; i < opt.nombre_arbres; i++){
        compteur_separateur = 0;



        while (compteur_separateur < 16){
            caractere = fgetc(fichier_entree);
            if (caractere == ';'){
                compteur_separateur++;
            }
        }


        //lecture de l'emplacement
        fscanf(fichier_entree, "%lf,%lf", &emplacement_arbre.longitude, &emplacement_arbre.latitude);
        


        //écriture dans fichier binaire
        fwrite(&emplacement_arbre, sizeof(emplacement), 1, fichier_sortie);
        







    }





    fclose(fichier_entree);
    fclose(fichier_sortie);

    if (opt.verification == 1){
        char chemin_fichier_binaire[100] = "sauvegarde_fichier_binaire/";
        strcat(chemin_fichier_binaire, opt.nom_fichier_sortie);

        FILE *test = fopen(chemin_fichier_binaire, "rb");
        if (test == NULL){
            fprintf(stderr,"Erreur d'ouverture du fichier\n");
            exit (1);
        }
        //printf("test\n"); //test
        for (int i = 0; i < opt.nombre_arbres; i++){
            fread(&emplacement_arbre, sizeof(emplacement), 1, test);
            printf("%lf,%lf\n", emplacement_arbre.longitude, emplacement_arbre.latitude); //test
        }
        fclose(test);
    }






    return 0;


}