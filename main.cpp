#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "includes.h"
#include "container.h"

void first_error() {
    std::cout << "incorrect command line!\n"
                 "  Waited:\n"
                 "     command -f infile outfile01 outfile02\n"
                 "  Or:\n"
                 "     command -n number outfile01 outfile02\n";
}

void second_error() {
    std::cout << "incorrect qualifier value!\n"
                 "  Waited:\n"
                 "     command -f infile outfile01 outfile02\n"
                 "  Or:\n"
                 "     command -n number outfile01 outfile02\n";
}

void third_error(int size) {
    std::cout << "incorrect number -- " << size;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        first_error();
        return 1;
    }
    std::cout << "Start" << std::endl;
    container container{};
    Init(container);

    if (!strcmp(argv[1], "-f")) {
        std::ifstream stream(argv[2]);
        // Check for the existence of the file, if the file does not exist, a warning will be thrown.
        if (stream.is_open())
            In(container, stream);
        else {
            std::cout << "File doesn't exist" << "\n";
            return 1;
        }
    } else if (!strcmp(argv[1], "-n")) {
        auto size = std::atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            third_error(size);
            return 3;
        }
        // Initialiser.
        srand(static_cast<unsigned int>(time(0)));
        // Filling the container with random numbers.
        InRandom(container, size);
    } else {
        second_error();
        return 2;
    }

    std::ofstream of_stream(argv[3]);
    of_stream << "Input container:\n";
    Out(container, of_stream);

    std::ofstream out_stream(argv[4]);
    Sort(container, 0, container.len - 1);
    out_stream << "Sorted :\n";
    Out(container, out_stream);
    Clear(container);
    std::cout << "Stop" << std::endl;
    return 0;
}