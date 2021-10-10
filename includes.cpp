//
// Created by kikin on 10.10.2021.
//

#include "includes.h"
#include <cstring>
#include <ctime>

void initRand() {
    srand((unsigned) time(nullptr));
}

int randInt(int min, int max) {
    return std::rand() % (max - min + 1) + min;
}

char *Word(int len) {
    static const char numericalAlphabet[] =
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "0123456789";
    char *result = new char[len + 1];
    for (int i = 0; i < len; ++i) {
        result[i] = numericalAlphabet[std::rand() % (sizeof(numericalAlphabet) - 1)];
    }
    // Zero terminated.
    result[len] = 0;
    return result;
}

char *copyStr(std::string &str) {
    // Zero terminated string
    char *result = new char[str.length() + 1];
    std::memcpy(result, str.c_str(), str.length() + 1);
    return result;
}

