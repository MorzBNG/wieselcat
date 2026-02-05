#ifndef TERRAIN_H
#define TERRAIN_H

struct Terrain {
    int size;
    float area;
    float verticalRange;
    float **heightfield;
};

Terrain *generateFlatTerrain(int *mapSize);
void deleteTerrain(Terrain *terr);
#endif
