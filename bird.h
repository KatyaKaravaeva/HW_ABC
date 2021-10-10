//
// Created by kikin on 10.10.2021.
//
#ifndef FINALFINALFINAL3_BIRD_H
#define FINALFINALFINAL3_BIRD_H
#include <fstream>
#include <string>

struct bird {
    char *name;
    int weight;
    bool flyOrStay;
};

//------------------------------------------------------------------------------
// Entering birds from the input stream.
void In(bird &bird, std::ifstream &stream);

//------------------------------------------------------------------------------
// Random input of birds from the input stream.
void InRandom(bird &bird);

//------------------------------------------------------------------------------
// Entering birds from the input stream.
void Out(bird &bird, std::ofstream &stream);

//------------------------------------------------------------------------------
// Calculate the quotient of a division.
double Quotient(bird &bird);
#endif //FINALFINALFINAL3_BIRD_H
