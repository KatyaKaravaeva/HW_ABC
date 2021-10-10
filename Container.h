//
// Created by kikin on 10.10.2021.
//

#ifndef FINALFINALFINAL3_CONTAINER_H
#define FINALFINALFINAL3_CONTAINER_H

#include "animal.h"

struct container {
    enum {
        max_len = 10000
    };
    int len;
    animal *cont[max_len];
};


// ---------------------------------------------------------------
// Initialises an empty container.
void Init(container &c);

// ---------------------------------------------------------------
// Clearing a container of items (freeing up memory).
void Clear(container &c);

// ---------------------------------------------------------------
// Inputting container contents from a specified stream.
void In(container &c, std::ifstream &stream);

// ---------------------------------------------------------------
// Random entry of container contents
void InRandom(container &c, int size);

// ---------------------------------------------------------------
// Output the container contents to the specified stream.
void Out(container &c, std::ofstream &stream);

// ---------------------------------------------------------------
// Function for combining two halves of an array or returning a sorted array.
void Merge(container &c, int l, int m, int r);

// Sorting
void Sort(container &c, int l, int r);

#endif //FINALFINALFINAL3_CONTAINER_H
