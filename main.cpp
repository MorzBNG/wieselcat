#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int x = 0;
int y = 0;

int mapSize = 2048;

void getInputMapSize(int *mapSize) {
    cout << "Input map size in meters:\n";
    
    string dimInput = "";
    getline(::cin, dimInput);
    
    if (!all_of(dimInput.begin(), dimInput.end(), ::isdigit)) {
        cout << "\nWrong input format, Try again!" << endl;
        getInputMapSize(mapSize);
        return;
    }
    
    int sizeInput = stoi(dimInput);

    if (sizeInput < 32 || sizeInput > 65536) {
        cout << "Size limits are 32 <= x <= 65536" << endl;
        getInputMapSize(mapSize);
        return;
    }

    *mapSize = sizeInput;
}

int main(int argc, char *argv[]) {
    //handle arguments
    //getopt
    //print software signature
    cout << "Wieselcat V0.0.1\n\nTickleTheShark Inc.\nby MorzBNG\n----------------------------\n\n";
    
    getInputMapSize(&mapSize);

    float mapArea = ((float)mapSize/1000) * ((float)mapSize/1000);
    cout << "Size set to " << mapSize << "m * " << mapSize << "m = " << mapArea << "km^2" << endl;

    return 1;
}
