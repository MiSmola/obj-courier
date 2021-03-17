#include <iostream>
#include "model/Mapper.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Mapper *mapper = new Mapper();
    Routes routes = mapper->mapFileToRoutes("D://Studies//Programming//Courier_project//testFiles//doubleDigits.txt");
    for (int i = 0; i < 3; i++) {
        std::cout << routes.getMap().edges[i].getClientA() << std::endl;
    }
    return 0;
}
