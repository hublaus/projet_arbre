#include "emplacement.h"
#include "affichage.h"
#include <tps.h>
#include "liste_aretes.h"


void affichage(emplacement* tableau_emplacement, int nombre_sommets , arete *tableau_aretes_MST){

    printf("affichage %d\n", nombre_sommets);

    int longitude_max = 1000000;
    int longitude_min = 700000;
    int latitude_min = 200000;
    //int latitude_max = 450000;
    int difference = longitude_max - longitude_min;

    int taille_fenetre = 900;


    tps_createWindow("Arbres Paris", taille_fenetre, taille_fenetre);

    //int x;
    //int y;
    int x_depart_zoom;
    int y_depart_zoom;

    emplacement_converti_en_pixels *tableau_emplacements_convertis_en_pixels = malloc(nombre_sommets * sizeof(emplacement_converti_en_pixels));


    char nombre[10];


    for (int i = 0; i < nombre_sommets; i++){
        sprintf( nombre, "%lf", tableau_emplacement[i].longitude) ;
        puts(nombre);
        sscanf( nombre, "48.%d", & (tableau_emplacements_convertis_en_pixels[i].x)  );
        printf("Longitude provisoire %d : %d\n", i , tableau_emplacements_convertis_en_pixels[i].x);

        sprintf(nombre, "%lf", tableau_emplacement[i].latitude);
        puts(nombre);
        sscanf( nombre, "2.%d", & (tableau_emplacements_convertis_en_pixels[i].y) );
        printf("Latitude provisoire %d : %d\n", i , tableau_emplacements_convertis_en_pixels[i].y);


        tableau_emplacements_convertis_en_pixels[i].x = (tableau_emplacements_convertis_en_pixels[i].x - longitude_min) * taille_fenetre / difference;
        tableau_emplacements_convertis_en_pixels[i].y = 900 -( (tableau_emplacements_convertis_en_pixels[i].y - latitude_min) * taille_fenetre / difference);
    }

    while(tps_isRunning()) {
        // Dessiner ici

        tps_background(255,255,255);
        tps_setColor(0,0,0);

        for (int i = 0; i < nombre_sommets; i++){
            tps_drawPoint(tableau_emplacements_convertis_en_pixels[i].x, tableau_emplacements_convertis_en_pixels[i].y);
        }

        for (int i = 0; i < (nombre_sommets - 1); i++){
            arete arete_actuelle = tableau_aretes_MST[i];
            tps_drawLine(tableau_emplacements_convertis_en_pixels[arete_actuelle.depart].x, tableau_emplacements_convertis_en_pixels[arete_actuelle.depart].y, tableau_emplacements_convertis_en_pixels[arete_actuelle.arrivee].x, tableau_emplacements_convertis_en_pixels[arete_actuelle.arrivee].y);
        }

        if(tps_mouseIsClicked()) {
            tps_getMousePosition(&x_depart_zoom, &y_depart_zoom);
            printf("x = %d, y = %d\n", x_depart_zoom, y_depart_zoom);
            tps_drawText(20, 20, "Appuyer sur Entré pour commencer ", 20);
        }
        tps_render();


  }
  tps_closeWindow();




}