//
// Created by kikin on 10.10.2021.
//

#ifndef FINALFINALFINAL3_ANIMAL_H
#define FINALFINALFINAL3_ANIMAL_H

#include "bird.h"
#include "fish.h"
#include "beast.h"

// Structure that summarises all the available figures.
struct animal {
    enum type {
        BIRD, BEAST, FISH
    };
    type type;
    union {
        bird bird1;
        beast beast1;
        fish fish1;
    };
};

//------------------------------------------------------------------------------
// Entering an animal from the input stream.
animal *In(std::ifstream &stream);

//------------------------------------------------------------------------------
// Inputting an animal from the input stream.
animal *InRandom();

//------------------------------------------------------------------------------
// Entering an animal from the input stream.
void Out(animal &animal, std::ofstream &stream);

//------------------------------------------------------------------------------
// Calculate the quotient of a division.
double Quotient(animal &m);


#endif //FINALFINALFINAL3_ANIMAL_H
