#include <string>
#include <iostream>
using namespace std;

void printInfoMsg(const string *message) {
    cout << "\x1B[38;5;15m" << "I | " << *message << "\x001b[0m" << endl;
}

void printWarnMsg(const string *message) {
    cout << "\x1B[38;5;208m" << "W | " << *message << "\x001b[0m" << endl;
}

void printErrMsg(const string *message) {
    cout << "\x1B[38;5;196m" << "E | " << *message << "\x001b[0m" << endl;
}

void printMsg(const string &message, const int status) {
    switch(status) {
        case 0: printInfoMsg(&message); break;
        case 1: printWarnMsg(&message); break;
        case 2: printErrMsg(&message); break;
        default: cout << message << endl;
    }
}
