#include <iostream>
#include <math.h>
#include "visualization.h"
#include "terrain.h"
using namespace std;

int valueToTerminalColor(float input);
void printTerrain(Terrain *terr);

void printTerrain(Terrain *terr) {
    int dispSize = 32;
    float dispFactor = (float)terr->size / (float)dispSize;
    float nVal = 0;
    float normFactor = 1 / terr->verticalRange;

    for (int i=0; i<dispSize; i++) {
        for (int j=0; j<dispSize; j++) {
            nVal = terr->heightfield[(int)round(i*dispFactor)][(int)round(j*dispFactor)] * normFactor;
            cout << "\x1B[38;5;" << valueToTerminalColor(nVal) << "m\u2588";
            cout << "\x1B[38;5;" << valueToTerminalColor(nVal) << "m\u2588";
        }
        cout << "\n";
    }
}

int valueToTerminalColor(float input) {
    return (232+(int)(input*23));
}
