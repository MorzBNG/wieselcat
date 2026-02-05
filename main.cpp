#include <iostream>
#include <string>
#include <algorithm>
#include "visualization.h"
#include "terrain.h"
using namespace std;

int mapSize = 2048;

void getMapSizeInput(int *mapSize) {
    puts("Input map size in meters:");
    
    string dimInput = "";
    getline(::cin, dimInput);
    
    if (!all_of(dimInput.begin(), dimInput.end(), ::isdigit)) {
        puts("Input is not an integer, try again!\n");
        getMapSizeInput(mapSize);
        return;
    }

    int sizeInput = stoi(dimInput);

    if (sizeInput < 32 || sizeInput > 65536) {
        puts("Size limits are 32 <= x <= 65536, try again!\n");
        getMapSizeInput(mapSize);
        return;
    }
    if (sizeInput == 1337) puts("\u2587\u2585\u2586\u2587\u2586\u2585\u2585\u2588");
    
    *mapSize = sizeInput;
}

int main(int argc, char *argv[]) {
    //handle arguments
    //getopt
    puts("Wieselcat V0.0.1\n\nTickleTheShark Inc.\nby MorzBNG\n----------------------------\n");

    getMapSizeInput(&mapSize);

    float mapArea = ((float)mapSize/1000) * ((float)mapSize/1000);
    cout << "Size set to " << mapSize << "m * " << mapSize << "m = " << mapArea << "km^2\n";
    
    printTerrain();
    
    puts("\x1b[0m");

    Terrain *terr = generateFlatTerrain(&mapSize);
    for (int i=0; i<terr->size; i++) {
        for (int j=0; j<terr->size; j++) {
            cout << terr->heightfield[i][j];
        }
        cout << "\n";
    }
    //for (int k=0; k<terr->size; k++) {
    //    cout << terr->heightfield[k] << "\n";
    //}
    //cout << terr->heightfield << "\n";
    //cout << terr->heightfield[0] << "\n";
    deleteTerrain(terr);
    return 0;
}
