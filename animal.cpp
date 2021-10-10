//
// Created by kikin on 10.10.2021.
//

#include "animal.h"
#include "includes.h"

animal *In(std::ifstream &stream) {
    animal *anim;
    int animalType;
    stream >> animalType;
    switch (animalType) {
        case 1:
            anim = new animal;
            anim->type = animal::BIRD;
            In(anim -> bird1, stream);
            return anim;
        case 2:
            anim = new animal;
            anim->type = animal::BEAST;
            In(anim->beast1, stream);
            return anim;
        case 3:
            anim = new animal;
            anim->type = animal::FISH;
            In(anim-> fish1, stream);
            return anim;
        default:
            return nullptr;
    }
}

animal *InRandom() {
    animal *mov;
    int animalType = randInt(1, 3);

    switch (animalType) {
        case 1:
            mov = new animal;
            mov->type = animal::BIRD;
            InRandom(mov->bird1);
            return mov;
        case 2:
            mov = new animal;
            mov->type = animal::BEAST;
            InRandom(mov->beast1);
            return mov;
        case 3:
            mov = new animal;
            mov->type = animal::FISH;
            InRandom(mov->fish1);
            return mov;
        default:
            return nullptr;
    }
}

void Out(animal &animal, std::ofstream &stream) {
    switch (animal.type) {
        case animal::BIRD:
            Out(animal.bird1, stream);
            break;
        case animal::BEAST:
            Out(animal.beast1, stream);
            break;
        case animal::FISH:
            Out(animal.fish1, stream);
            break;
        default:
            stream << "Incorrect animal!\n";
    }
}

double Quotient(animal &m) {
    switch (m.type) {
        case animal::BIRD:
            return Quotient(m.bird1);
        case animal::BEAST:
            return Quotient(m.beast1);
        case animal::FISH:
            return Quotient(m.fish1);
        default:
            return 0;
    }
}

