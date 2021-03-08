#include <iostream>
#include "rational.h"
#include <cstdbool>

using namespace std;

int main() {
    Rational x(-1024, 32), y(-3, 9), z(2, 0), w(-1025, 32);
    cout << "neg x: ";
    (x.neg()).print();

    cout << "inv x: ";
    (x.inv()).print();

    cout << "y + z = ";
    (y + z).print();

    cout << "y - z = ";
    (y - z).print();

    cout << "y * z = ";
    (y * z).print();

    cout << "y / z = ";
    (y / z).print();

    cout << "x == w? - " << (x == w) << endl;

    cout << "x != w? - " << (x != w) << endl;

    cout << "x < w? - " << (x < w) << endl;

    cout << "x <= w? - " << (x <= w) << endl;

    cout << "x > w? - " << (x > w) << endl;

    cout << "x >= w? - " << (x >= w) << endl;

    return 0;
}
