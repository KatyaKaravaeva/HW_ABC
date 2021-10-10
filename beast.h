//
// Created by kikin on 10.10.2021.
//

#ifndef FINALFINALFINAL3_BEAST_H
#define FINALFINALFINAL3_BEAST_H
#include <fstream>
#include <string>

struct beast {
    char *name;
    int weight;
    enum type {
        PREDATORS,
        HERBIVORES,
        INSECTIVORES
    };
    type t;
};

//------------------------------------------------------------------------------
// Input animals from the input stream.
void In(beast &beast, std::ifstream &stream);

//------------------------------------------------------------------------------
// Random input of animals from the input stream.
void InRandom(beast &beast);

//------------------------------------------------------------------------------
// Entering animals from the input stream.
void Out(beast &beast, std::ofstream &stream);

//------------------------------------------------------------------------------
// Calculate the quotient of a division.
double Quotient(beast &c);

#endif //FINALFINALFINAL3_BEAST_H
