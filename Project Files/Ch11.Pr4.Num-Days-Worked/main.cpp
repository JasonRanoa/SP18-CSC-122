#include <iostream>
#include "NumDays.h"
using namespace std;

int main() {
    NumDays nx(32), ni(20);

    cout << "nx " << nx << "\n";
    cout << "ni " << ni << "\n\n";

    nx += ni;

    cout << "nx " << nx << "\n";
    cout << "ni " << ni << "\n\n";

    ni -= 8;

    cout << "nx " << nx << "\n";
    cout << "ni " << ni << "\n\n";

    return 0;
}