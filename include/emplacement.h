#pragma once

/**
 * @brief structure stockant les coordonnées d'un emplacement (celui d'un arbre)
 */
typedef struct {
    double longitude;
    double latitude;
} emplacement;

/**
 * @brief calcule la distance entre deux emplacements (en kilomètres)
 * @param point1 premier emplacement
 * @param point2 second emplacement
 * @return la distance entre les deux emplacements (en kilomètres)
 */

double distance_entre_deux_emplacements(emplacement point1, emplacement point2);