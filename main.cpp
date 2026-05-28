#include <iostream>
#include <string>
#include <algorithm>
#include "visualization.h"
#include "terrain.h"
using namespace std;

int terrainSize = 2048;
int terrainResolution = 2048;

bool inputIsInteger(string input) {
    if (input.length() > 5) {
        puts("Input too long!\n");
        return false;
    }

    if (!all_of(input.begin(), input.end(), ::isdigit)) {
        puts("Input is not an integer!\n");
        return false;
    }

    return true;
}

bool inputInLimits(int input, int lower, int upper) {
    if (input < lower || input > upper) {
        cout << "Size limits are " << lower << " <= x <= " << upper << "!\n" << endl;
        return false;
    }
    return true;
}

void getTerrainSizeInput(int *terrainSize) {
    puts("Input map size in meters:");

    string dimInput = "";
    getline(::cin, dimInput);

    if (!inputIsInteger(dimInput)) {
        getTerrainSizeInput(terrainSize);
        return;
    }

    int size = stoi(dimInput);

    if (!inputInLimits(size, 32, 65536)) {
        getTerrainSizeInput(terrainSize);
        return;
    }

    if (size == 1337) puts("\u2587\u2585\u2586\u2587\u2586\u2585\u2585\u2588");

    *terrainSize = size;
}

void getTerrainResolutionInput(int *terrainResolution) {
    puts("Input map resolution:");

    string resInput = "";
    getline(::cin, resInput);

    if (!inputIsInteger(resInput)) {
        getTerrainResolutionInput(terrainResolution);
        return;
    }

    int resolution = stoi(resInput);

    if (!inputInLimits(resolution, 32, 4096)) {
        getTerrainResolutionInput(terrainResolution);
        return;
    }

    *terrainResolution = resolution;
}


int main(int argc, char *argv[]) {
    //handle arguments getopt
    puts("Wieselcat V0.0.1\n\nTickleTheShark Inc.\nby MorzBNG\n----------------------------\n");

    getTerrainSizeInput(&terrainSize);

    float terrainArea = ((float)terrainSize/1000) * ((float)terrainSize/1000);
    cout << "Size set to " << terrainSize << "m * " << terrainSize << "m = " << terrainArea << "km^2\n";

    getTerrainResolutionInput(&terrainResolution);

    Terrain *terr = generateDonutTerrain(&terrainResolution);

    printTerrain(terr);
    puts("\x1b[0m");

    deleteTerrain(terr);
    return 1;
}
