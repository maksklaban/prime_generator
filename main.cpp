#include <iostream>
#include <memory>

#include "app.h"
#include "prime.h"



int main(int argc, char const *argv[]) {
    std::regex pattern("<interval>"
            "(?:\\s*)<low>[\\s]*(\\d+)[\\s]*</low>"
            "(?:[\\d\\D]*?)<high>[\\s]*(\\d+)[\\s]*</high>"
            "(?:\\s*)</interval>");
    // auto b = std::make_shared<std::regex>(pattern);
    auto test = new PrimeGen(pattern);
    test->calculate();

    // auto test1 = test->getResults();

    // for (auto x: *test1) {
    //     std::cout << x << " ";
    // }
    delete test;
    // std::shared_ptr<Application> test(new Application(b));
    return 0;
}