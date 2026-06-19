#include <cstdlib>
#include <math.h>
#include "terrain.h"
#define _USE_MATH_DEFINES

float standardNormalDistribution(float x);
float bimodalDistribution(float x);

Terrain *generateFlatTerrain(int *terrainSize) {
    Terrain *terr = new Terrain;
    terr->size = *terrainSize;
    terr->area = ((float)*terrainSize/1000)*((float)*terrainSize/1000);
    terr->verticalRange = 0;
    terr->heightfield = (float **)malloc(*terrainSize * sizeof(float *));
    float *data = (float *)malloc(*terrainSize * *terrainSize * sizeof(float *));
    for (int i=0; i<*terrainSize; i++) {
        terr->heightfield[i] = data;
        data += *terrainSize;
    }
    return terr;
}

Terrain *generateDonutTerrain(int *terrainSize) {
    Terrain *terr = generateFlatTerrain(terrainSize);
    float height = 0;
    float x = 0;
    for (int i=0; i<*terrainSize; i++) {
        for (int j=0; j<*terrainSize; j++) {
            x = sqrt(pow(i-*terrainSize/2,2)+pow(j-*terrainSize/2,2))/ *terrainSize*10;
            height = bimodalDistribution(x);
            terr->heightfield[i][j] = height;
            if (height > terr->verticalRange) terr->verticalRange = height;
        }
    }
    return terr;
}

float standardNormalDistribution(float x) {
    return 1/(sqrt(2*M_PI)) * pow(M_E,-0.5*pow(x,2));
}

float bimodalDistribution(float x) {
    return standardNormalDistribution(x-2.) + standardNormalDistribution(x+2.);
}

void deleteTerrain(Terrain *terr) {
    free(terr->heightfield[0]);
    free(terr->heightfield);
    delete terr;
}
