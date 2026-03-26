#include <iostream>
#include "Canvas.hpp"
using namespace lumi;

void space() {
    std::cout << std::endl << std::endl;
}

int main() {
    Canvas<int> canvas;
    
    std::cout << "INSERT W/ CURSOR: " << std::endl;
    canvas.insert(10);
    canvas.position(0).insert(5);
    canvas.display();

    space();

    std::cout << "GET: " << std::endl;
    std::cout << "canvas[0] = " << canvas[0] << std::endl;
    std::cout << "also canvas[0] = " << canvas.first() << std::endl;
    
    space();

    std::cout << "RESERVE: " << std::endl;
    canvas.reserve(8);
    canvas.display();

    space();

    std::cout << "INSERT W/ RANGE: " << std::endl;
    canvas.hold(canvas.begin(), canvas.position(5)).insert(2);
    canvas.display();

    space();

    std::cout << "ERASE W/ CURSOR: " << std::endl;
    canvas.erase(5);
    canvas.end().erase();
    canvas.display();

    space();
    
    std::cout << "ERASE W/ RANGE: " << std::endl;
    canvas.hold(canvas.position(2), canvas.end()).erase(2);
    canvas.display();

    space();

    std::cout << "CLEAR: " << std::endl;
    canvas.clear();
    canvas.display();
    return 0;
}