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
    //dimInput.erase(remove_if(dimInput.begin(), dimInput.end(), ::isspace), dimInput.end());
    
    if (all_of(dimInput.begin(), dimInput.end(), ::isdigit)) {
        *mapSize = stoi(dimInput);
        float mapArea = *mapSize * *mapSize;
        mapArea = mapArea / 1000000;
        cout << "Size set to " << *mapSize << "m * " << *mapSize << "m = " << mapArea << "km^2" << endl;
        return;
    }

    cout << "\nWrong input format, Try again!" << endl;
    getInputMapSize(mapSize);
}

int main(int argc, char *argv[]) {
    //handle arguments
    //getopt
    //print software signature
    cout << "Wieselcat V0.0.1\n\nTickleTheShark Inc.\nby MorzBNG\n----------------------------\n\n";
    
    getInputMapSize(&mapSize);

    return 1;
}
