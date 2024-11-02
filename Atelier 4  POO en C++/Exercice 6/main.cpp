#include <iostream>
#include "Point.h"

int main() {
    
    Point p(2.0, 3.0);
    p.affiche();
    p.deplace(1.5, -0.5);
    p.affiche();

    return 0;
}