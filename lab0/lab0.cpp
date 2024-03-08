#include <iostream>
#include <functional>

using namespace std;

bool gateNOT(bool value) {
    if (value == true) return false;
    else return true;
}

bool gateAND(bool value1, bool value2) {
    if (value1 == true && value2 == true) return true;
    else return false;
}

bool gateOR(bool value1, bool value2) {
    if (value1 == false && value2 == false) return false;
    else return true;
}

bool gateNAND(bool value1, bool value2) {
    return gateNOT(gateAND(value1, value2));
}

bool gateNOR(bool value1, bool value2) {
    return gateNOT(gateOR(value1, value2));
}

bool gateXOR(bool value1, bool value2) {
    if (value1 == false && value2 == false || value1 == true && value2 == true) return false;
    else return true;
}

void table(const function<bool(bool, bool)>& fun, string name) {
    cout << name << endl;
    for (bool value1 : {false, true}) {
        for (bool value2 : {false, true}) {
            cout << value1 << " " << value2 << " " << fun(value1, value2) << endl;
        }
    }
    cout << endl;
}

void table(const function<bool(bool)>& fun, string name) {
    cout << name << endl;
    for (bool value : {false, true}) {
         cout << value << " " << fun(value) << endl;
    }
    cout << endl;
}

int main()
{
    table(gateNOT, "NOT");
    table(gateAND, "AND");
    table(gateOR, "OR");
    table(gateNOR, "NOR");
    table(gateNAND, "NAND");
    table(gateXOR, "XOR");
    system("PAUSE");
}
