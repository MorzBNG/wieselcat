#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES
using namespace std;

float standardNormalDistribution(float x);
float bimodalDistribution(float x);
int valueToTerminalColor(float input);
void printTerrain();

void printTerrain() {
    int dispSize = 16;
    float nVal = 0;
    float x = 0;

    for (int i=-dispSize; i<=dispSize; i++) {
        for (int j=-dispSize; j<=dispSize; j++) {
            x = sqrt(pow(i,2) + pow(j,2));
            nVal = bimodalDistribution(x/4)*2;
            cout << "\x1B[38;5;" << valueToTerminalColor(nVal) << "m\u2588";
            cout << "\x1B[38;5;" << valueToTerminalColor(nVal) << "m\u2588";
        }
        cout << "\n";
    }
}

float standardNormalDistribution(float x) {
    return 1/(sqrt(2*M_PI)) * pow(M_E,-0.5*pow(x,2));
}

float bimodalDistribution(float x) {
    return standardNormalDistribution(x-2.) + standardNormalDistribution(x+2.);
}

int valueToTerminalColor(float input) {
    return (232+(int)(input*23));
}
