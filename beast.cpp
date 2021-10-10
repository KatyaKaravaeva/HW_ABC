//
// Created by kikin on 10.10.2021.
//

#include "beast.h"
#include <cstring>
#include "includes.h"

void In(beast &beast, std::ifstream &stream) {
    std::string name;
    stream >> name >> beast.weight;
    // Дополнительная проверка на ввод
    if (beast.weight < 1000 || beast.weight > 0) {
        beast.weight = randInt(1, 100);
    }
    beast.name = copyStr(name);
    char type[100];
    stream >> type;
    if (!strcmp(type, "predators")) {
        beast.t = beast::PREDATORS;
    } else if (!strcmp(type, "herbivores")) {
        beast.t = beast::HERBIVORES;
    } else if (!strcmp(type, "insectivores")) {
        beast.t = beast::INSECTIVORES;
    } else {
        beast.t = beast::PREDATORS;
    }
}

void InRandom(beast &beast) {
    beast.name = Word(randInt(5, 10));
    beast.weight = randInt(1, 100);
    int type = randInt(0, 2);
    beast.t = static_cast<beast::type>(type);
}

void Out(beast &beast, std::ofstream &stream) {
    std::string type;
    switch (beast.t) {
        case beast::PREDATORS:
            type = "PREDATORS";
            break;
        case beast::HERBIVORES:
            type = "HERBIVORES";
            break;
        case beast::INSECTIVORES:
            type = "INSECTIVORES";
            break;
    }
    stream << "Beast: name = " << beast.name << ", weight = " << beast.weight << ", type = " << type
           << ", Quotient = " << Quotient(beast) << "\n";
}

double Quotient(beast &c) {
    int count = 0;
    int len = strlen(c.name);
    for (int i = 0; i < len; ++i) {
        count+=c.name[i];
    }
    return static_cast<double>(count) / static_cast<double>(c.weight);
}
