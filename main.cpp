#include <iostream>
#include <memory>

#include "app.h"
#include "prime.h"

std::regex pattern("<interval>"
        "(?:[\\d\\D]*?)<low>[\\s]*(-?\\d+)[\\s]*</low>"
        "(?:[\\d\\D]*?)<high>[\\s]*(-?\\d+)[\\s]*</high>"
        "(?:[\\d\\D]*?)</interval>");


int main(int argc, char const *argv[]) {
    auto test = new PrimeGen(pattern);
    
    test->calculate();

    delete test;
    return 0;
}