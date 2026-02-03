#include <cstdlib>
#include "terrain.h"

Terrain *generateFlatTerrain(int *mapSize) {
    Terrain *terr = (Terrain*)malloc(sizeof(Terrain));
    terr->size = *mapSize;
    terr->area = ((float)*mapSize/1000)*((float)*mapSize/1000);
    terr->verticalRange = 0;
    return terr;
}

void deleteTerrain(Terrain *terr) {
    free(terr);
}
