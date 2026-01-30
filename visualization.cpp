#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES
using namespace std;

float standardDistribution(float x);
void printTerrain();

void printTerrain() {
    //puts(standardDistribution(1.));
    cout << standardDistribution(0.) << "\n";
}

float standardDistribution(float x) {
    return 1/(sqrt(2*M_PI)) * pow(M_E,-0.5*pow(x,2));
}
