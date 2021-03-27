#include <iostream>
#include <string>
#include "model/Mapper.h"
#include "model/Algorithm.h"

int main() {
//    try{
//        std::cout << std::stoi("-") << std::endl;
//    }catch(std::exception& e){
//        std::cout << e.what() << std::endl;
//    }

    Mapper *mapper = new Mapper();
    Algorithm *algorithm = new Algorithm();
    try {
        Routes routes = mapper->mapFileToRoutes(
                "D://Studies//Programming//Courier_project//testFiles//doubleDigits.txt");
        Trip trip = algorithm->generateTrip(routes, *routes.getClients().begin(),
                                            algorithm->generateConnectionArray(routes));
        mapper->mapTripToFile(trip, "D://Studies//Programming//Courier_project//testFiles//resultobj.txt");

    } catch (int e) {
        if (e == -1) std::cout << "Nieprawidlowe dane (stoi)";
        if (e == -2) std::cout << "Nieokreslony kierunek";
    }
//    for (int i = 0; i < 3; i++) {
//        std::cout << routes.getMap().edges[i].getClientA() << std::endl;
//    }
    return 0;
}
