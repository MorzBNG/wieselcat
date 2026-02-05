#include <iostream>
#include <string>
#include <algorithm>
#include "visualization.h"
#include "terrain.h"
using namespace std;

int terrainSize = 2048;

void getTerrainSizeInput(int *terrainSize) {
    puts("Input map size in meters:");
    
    string dimInput = "";
    getline(::cin, dimInput);
    
    if (!all_of(dimInput.begin(), dimInput.end(), ::isdigit)) {
        puts("Input is not an integer, try again!\n");
        getTerrainSizeInput(terrainSize);
        return;
    }

    int sizeInput = stoi(dimInput);

    if (sizeInput < 32 || sizeInput > 65536) {
        puts("Size limits are 32 <= x <= 65536, try again!\n");
        getTerrainSizeInput(terrainSize);
        return;
    }
    if (sizeInput == 1337) puts("\u2587\u2585\u2586\u2587\u2586\u2585\u2585\u2588");
    
    *terrainSize = sizeInput;
}

int main(int argc, char *argv[]) {
    //handle arguments
    //getopt
    puts("Wieselcat V0.0.1\n\nTickleTheShark Inc.\nby MorzBNG\n----------------------------\n");

    getTerrainSizeInput(&terrainSize);

    float terrainArea = ((float)terrainSize/1000) * ((float)terrainSize/1000);
    cout << "Size set to " << terrainSize << "m * " << terrainSize << "m = " << terrainArea << "km^2\n";

    Terrain *terr = generateDonutTerrain(&terrainSize);
    
    printTerrain(terr);
    puts("\x1b[0m");
    
    deleteTerrain(terr);
    return 0;
}
