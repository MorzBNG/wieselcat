#include <iostream>
#include "visualization.h"
#include "terrain.h"
using namespace std;

int valueToTerminalColor(float input);
void printTerrain(Terrain *terr);

void printTerrain(Terrain *terr) {
    int dispSize = 16;
    float nVal = 0;

    for (int i=0; i<terr->size; i++) {
        for (int j=0; j<terr->size; j++) {
            nVal = terr->heightfield[i][j];
            cout << "\x1B[38;5;" << valueToTerminalColor(nVal) << "m\u2588";
            cout << "\x1B[38;5;" << valueToTerminalColor(nVal) << "m\u2588";
        }
        cout << "\n";
    }
}

int valueToTerminalColor(float input) {
    return (232+(int)(input*23));
}
