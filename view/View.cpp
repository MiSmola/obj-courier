//
// Created by djnic on 27.03.2021.
//

#include <string>
#include <iostream>
#include "View.h"

void View::welcomeMessage() {
    std::string logo = "   ______                 _          \n"
                       "  / ____/___  __  _______(_)__  _____\n"
                       " / /   / __ \\/ / / / ___/ / _ \\/ ___/\n"
                       "/ /___/ /_/ / /_/ / /  / /  __/ /    \n"
                       "\\____/\\____/\\__,_/_/  /_/\\___/_/     \n";
    std::cout << logo << std::endl;
    std::cout << "Program do znajdowania najbardziej optymalnej trasy kuriera." << std::endl;
}

void View::displayInstructionScreen() {
    std::cout << "Nalezy zaladowac plik *.txt z rozpisanymi polaczeniami i ich kosztami oraz podac "
                 "miejsce zapisu pliku wynikowego." << std::endl;
    std::cout
            << "Przykladowe wywolanie: \n Courier.exe \n-i <sciezka pliku wejsciowego> \n-o <sciezka pliku wynikowego> \n-h"
            << std::endl;
}

void View::errorMessage() {
    std::cerr << "Wystatpil blad techniczny - sprawdz wywolanie badz plik wejsciowy." << std::endl;
}

void View::errorMapperData() {
    std::cerr << "Mapper Error: Nieprawidlowe dane wejsciowe (stoi)." << std::endl;
}

void View::errorMapperDirection() {
    std::cerr << "Mapper Error: Nieprawidlowo okreslony kierunek." << std::endl;
}

void View::endMessage() {
    std::cout << "Program zakonczyl poszukiwanie i zapisal droge wraz z kosztem w pliku wynikowym." << std::endl;
}
