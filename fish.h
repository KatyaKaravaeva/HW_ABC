//
// Created by kikin on 10.10.2021.
//

#ifndef FINALFINALFINAL3_FISH_H
#define FINALFINALFINAL3_FISH_H
#include <fstream>
#include <string>

struct fish {
    char *name;
    int weight;
    enum type {
        RIVER,
        SEA,
        LAKE
    };
    type t;
};

//------------------------------------------------------------------------------
// entering fish from the input stream
void In(fish &fish, std::ifstream &stream);

//------------------------------------------------------------------------------
// Random input of fish from the input stream.
void InRandom(fish &fish);

//------------------------------------------------------------------------------
// Entering fish from the input stream.
void Out(fish &fish, std::ofstream &stream);

//------------------------------------------------------------------------------
// Calculate the quotient of a division.
double Quotient(fish &c);
#endif //FINALFINALFINAL3_FISH_H
