#include <iostream>
#include <string>
#include <algorithm>
#include "visualization.h"
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
    //print software signature
    puts("Wieselcat V0.0.1\n\nTickleTheShark Inc.\nby MorzBNG\n----------------------------\n");

    getMapSizeInput(&mapSize);

    float mapArea = ((float)mapSize/1000) * ((float)mapSize/1000);
    cout << "Size set to " << mapSize << "m * " << mapSize << "m = " << mapArea << "km^2\n";
    
    printTerrain();

    return 1;
}
