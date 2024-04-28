// Client code, using our ADT Rect and Box
// CS162, PCC

#include "Rect.hpp"
#include "Box.hpp"
#include <iostream>
using namespace std;

int main() {
    Rect r;
    Box b("store receipts", "receipt box", 10.0, 10.0, 10.0);
    Box b3;
    b3 = b;
    Rect * r1 = new Rect("rectangle 1", 2.3, 1.5);
    Box * b1 = new Box("for the mail", "box 1", 4.5, 2.2, 3.4);
    b1->getInfo();
    r1->getInfo();
    delete r1;
    delete b1;
    cout << endl;
    
    return 0;
}


