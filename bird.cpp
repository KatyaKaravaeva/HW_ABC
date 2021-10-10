//
// Created by kikin on 10.10.2021.
//

#include "bird.h"
#include <cstring>
#include "includes.h"

void In(bird &bird, std::ifstream &stream) {
    std::string name;
    stream >> name >> bird.weight >> bird.flyOrStay;
    // Дополнительная проверка на ввод
    if (bird.weight > 10000 || bird.weight < 0) {
        bird.weight = randInt(1, 100);
    }
    if (bird.flyOrStay != 0 && bird.flyOrStay != 1) {
        bird.flyOrStay = randInt(0, 1);
    }
    bird.name = copyStr(name);
}

void InRandom(bird &bird) {
    bird.name = Word(randInt(5, 10));
    bird.weight = randInt(1, 100);
    bird.flyOrStay = randInt(0, 1);
}

void Out(bird &bird, std::ofstream &stream) {
    stream << "Bird: name = " << bird.name << ", weight = " << bird.weight << ", flyOrStay = "
           << bird.flyOrStay
           << ", Quotient = " << Quotient(bird) << "\n";
}

double Quotient(bird &bird) {
    int count = 0;
    int len = strlen(bird.name);
    for (int i = 0; i < len; ++i) {
        count+=bird.name[i];
    }
    return static_cast<double>(count) / static_cast<double>(bird.weight);
}
