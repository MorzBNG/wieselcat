#include <iostream>
#include <string>
#include <algorithm>
#include "visualization.h"
#include "terrain.h"
#include "message.h"
using namespace std;

int terrainSize = 2048; //m
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

bool inputInLimits(const int input, const int lower, const int upper) {
    if (input < lower || input > upper) {
        cout << "Size limits are " << lower << " <= x <= " << upper << "!\n" << endl;
        return false;
    }
    if (__builtin_popcountll(input) != 1) printMsg("Dimensions that are not powers of two may lead to unexpected behavior", 1);
    return true;
}

void getTerrainSizeInput(int *terrainSize) {
    puts("Input map size in meters:");

    string dimInput;
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

    string resInput;
    getline(::cin, resInput);

    if (!inputIsInteger(resInput)) {
        getTerrainResolutionInput(terrainResolution);
        return;
    }

    const int resolution = stoi(resInput);

    if (!inputInLimits(resolution, 32, 4096)) {
        getTerrainResolutionInput(terrainResolution);
        return;
    }

    *terrainResolution = resolution;
}

void printTerrainArea(int *terrainSize) {
    float terrainArea = ((float)*terrainSize/1000) * ((float)*terrainSize/1000);
    cout << "Terrain Area is  " << *terrainSize << "m * " << *terrainSize << "m = " << terrainArea << "km^2\n\n";
}

int main(int argc, char *argv[]) {
    //handle arguments getopt
    puts("Wieselcat V0.0.1\n\nTickleTheShark Inc.\nby MorzBNG\n----------------------------\n");

    getTerrainSizeInput(&terrainSize);
    printTerrainArea(&terrainSize);
    getTerrainResolutionInput(&terrainResolution);

    Terrain *terr = generateDonutTerrain(&terrainResolution);

    printTerrain(terr);
    puts("\x001b[0m");

    deleteTerrain(terr);
    return 1;
    //or are you unforgiven too?
}
