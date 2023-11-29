#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ligne_de_commande_fichier_binaire.h"

void traitement_arguments_ligne_de_commande(int argc, char **argv , options* opt){
    int c;
    opt->nombre_arbres = 205317;
    opt->nom_fichier_sortie = NULL;
    opt->nom_fichier_entree = NULL;
    opt->verification = 0;

    while ((c = getopt (argc, argv, "n:i:o:v")) != -1){
        switch (c){
            case 'n':
                opt->nombre_arbres = atoi(optarg);
                if (opt->nombre_arbres > 205317){
                    fprintf(stderr, "Il n'y a que 205317 arbres à Paris\n");
                    exit(1);
                }
                break;
            case 'i':
                opt->nom_fichier_entree = optarg;
                break;
            case 'o':
                opt->nom_fichier_sortie = optarg;
                break;
            case 'v':
                opt->verification = 1;
                break;

        }
    
    }
    if (opt->nom_fichier_entree == NULL){
        fprintf(stderr, "Il faut un fichier d'entrée (option -i 'nom'). Ce dernier doit être écrit en chemin relatif depuis le répertoire creation_fichier_binaire\n");
        exit(1);
    }

    if (opt->nom_fichier_sortie == NULL){
        fprintf(stderr, "Il faut un fichier de sortie(option -o 'nom'). Un fichier à ce nom apparaîtra alors dans le dossier sauvegarde fichier_binaire (ne pas écrire de chemin vers ce fichier\n");
        exit(1);
    }

}