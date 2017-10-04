#include <iostream>
#include <memory>

#include "app.h"



int main(int argc, char const *argv[]) {
    std::regex pattern("<interval>"
            "(?:\\s*)<low>[\\s]*(\\d+)[\\s]*</low>"
            "(?:[\\d\\D]*?)<high>[\\s]*(\\d+)[\\s]*</high>"
            "(?:\\s*)</interval>");
    // auto b = std::make_shared<std::regex>(pattern);
    Application* test = new Application(pattern);
    delete test;
    // std::shared_ptr<Application> test(new Application(b));
    return 0;
}