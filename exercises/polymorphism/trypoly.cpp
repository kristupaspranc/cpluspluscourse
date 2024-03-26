#include "Polygons.hpp"
#include <iostream>

int main() {
    // create a Pentagon, call its perimeter method
    Pentagon myPenty{5};
    std::cout << myPenty.computePerimeter() << "\n";

    // create a Hexagon, call its perimeter method
    Hexagon myHexy{5};
    std::cout << myHexy.computePerimeter() << "\n";

    // create a Hexagon, call the perimeter method through a reference to Polygon
    Hexagon myOtherHexy{5};
    RegularPolygon & myOtherHexyReferenced{myOtherHexy};
    std::cout << myOtherHexyReferenced.computePerimeter() << "\n";

    // retry virtual method

}
