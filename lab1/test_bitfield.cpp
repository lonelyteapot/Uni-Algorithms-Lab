#include <iostream>
#include "TBitField.h"

using namespace std;

int main() {
    cout << "BitField testing program" << endl;
    cout << "========================" << endl;
    cout << "Valid input:"             << endl;
    cout << "Any number of 0s and 1s"  << endl;
    cout << "========================" << endl;

    TBitField bf1(1), bf2(1);
    cout << "bitfield1:   > " << flush;
    cin >> bf1;
    cout << "bitfield2:   > " << flush;
    cin >> bf2;

    cout << "========================" << endl;

    cout << "bitfield1    = " << bf1          << endl;
    cout << "bitfield2    = " << bf2          << endl;
    cout << "bitfield1|2  = " << (bf1 | bf2)  << endl;
    cout << "bitfield1&2  = " << (bf1 & bf2)  << endl;
    cout << "bitfield~1   = " << ~bf1         << endl;
    cout << "bitfield~2   = " << ~bf2         << endl;
    cout << "bitfield1==2 = " << (bf1 == bf2) << endl;

    return 0;
}
