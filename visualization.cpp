#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES
using namespace std;

float standardNormalDistribution(float x);
void printTerrain();
int valueToTerminalColor(float input);

void printTerrain() {
    int dispSize = 16;
    float nVal = 0;
    
    for (int i=-dispSize; i<=dispSize; i++) {
        for (int j=-dispSize; j<=dispSize; j++) {
            nVal = standardNormalDistribution((float)i)*standardNormalDistribution((float)j);
            cout << "\x1B[38;5;" << valueToTerminalColor(nVal*10) << "m\u2588";
        }
        cout << "\n";
    }
}

float standardNormalDistribution(float x) {
    return 1/(sqrt(2*M_PI)) * pow(M_E,-0.5*pow(x,2));
}

int valueToTerminalColor(float input) {
    return (232+(int)(input*23));
}
