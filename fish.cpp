//
// Created by kikin on 10.10.2021.
//
#include "fish.h"
#include <cstring>
#include "includes.h"

void In(fish &fish, std::ifstream &stream) {
    std::string name;
    stream >> name >> fish.weight;
    // On additional assessment - additional input check.
    if (fish.weight > 1000 || fish.weight <= 0) {
        fish.weight = randInt(1, 100);
    }
    fish.name = copyStr(name);
    char type[100];
    stream >> type;
    if (!strcmp(type, "river")) {
        fish.t =  fish::RIVER;
    } else if (!strcmp(type, "sea")) {
        fish.t = fish::SEA;
    } else if (!strcmp(type, "lake")) {
        fish.t = fish::LAKE;
    } else {
        fish.t =  fish::RIVER;
    }
}

void InRandom(fish &fish) {
    fish.name = Word(randInt(5, 10));
    fish.weight = randInt(1, 100);
    int type = randInt(0, 2);
    fish.t = static_cast<fish::type>(type);
}

void Out(fish &fish, std::ofstream &stream) {
    std::string type;
    switch (fish.t) {
        case fish::RIVER:
            type = "RIVER";
            break;
        case fish::SEA:
            type = "SEA";
            break;
        case fish::LAKE:
            type = "LAKE";
            break;
    }
    stream << "Fish: name = " << fish.name << ", weight = " << fish.weight << ", type = " << type
           << ", Quotient = " << Quotient(fish) << "\n";
}

double Quotient(fish &c) {
    int count = 0;
    int len = strlen(c.name);
    for (int i = 0; i < len; ++i) {
        count+=c.name[i];
    }
    return static_cast<double>(count) / static_cast<double>(c.weight);
}
