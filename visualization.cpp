#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES
using namespace std;

float standardNormalDistribution(float x);
void printTerrain();

void printTerrain() {
    cout << standardNormalDistribution(0.) << "\n";
    
    int dispSize = 16;
    for (int i=-dispSize; i<=dispSize; i++) {
        for (int j=-dispSize; j<=dispSize; j++) {
            cout << (int)(standardNormalDistribution((float)i/10)*standardNormalDistribution((float)j/10)*60);
        }
        cout << "\n";
    }
}

float standardNormalDistribution(float x) {
    return 1/(sqrt(2*M_PI)) * pow(M_E,-0.5*pow(x,2));
}
