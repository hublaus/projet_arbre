#include "emplacement.h"
#include <math.h>

double distance_entre_deux_emplacements(emplacement point1, emplacement point2){
    double distance;
    distance = sqrt(pow(point1.latitude - point2.latitude, 2) + pow(point1.longitude - point2.longitude, 2));
    return distance*111.0;
}