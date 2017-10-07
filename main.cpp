#include <iostream>
#include <memory>

#include "app.h"
#include "prime.h"



int main(int argc, char const *argv[]) {
    std::regex pattern("<interval>"
            "(?:\\s*)<low>[\\s]*(-?\\d+)[\\s]*</low>"
            "(?:[\\d\\D]*?)<high>[\\s]*(-?\\d+)[\\s]*</high>"
            "(?:\\s*)</interval>");
    auto test = new PrimeGen(pattern);
    std::shared_ptr<std::set<int>> test1;

    test->calculate();

    test1 = test->getResults();
    std::cout << test1->size() << std::endl;

    delete test;
    return 0;
}