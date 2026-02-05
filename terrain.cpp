#include <cstdlib>
#include "terrain.h"

Terrain *generateFlatTerrain(int *mapSize) {
    Terrain *terr = new Terrain;
    terr->size = *mapSize;
    terr->area = ((float)*mapSize/1000)*((float)*mapSize/1000);
    terr->verticalRange = 0;
    terr->heightfield = (float **)malloc(*mapSize * sizeof(float *));
    float *data = (float *)malloc(*mapSize * *mapSize * sizeof(float *));
    for (int i=0; i<*mapSize; i++) {
        terr->heightfield[i] = data;
        data += *mapSize;
    }
    return terr;
}

void deleteTerrain(Terrain *terr) {
    free(terr->heightfield[0]);
    free(terr->heightfield);
    delete terr;
}
