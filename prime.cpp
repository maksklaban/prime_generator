#include "prime.h"

PrimeGen::PrimeGen(std::regex pattern) : Application(pattern) {}

PrimeGen::~PrimeGen() {}

void PrimeGen::calculate() {
    for (auto x: *(this->ranges)) {
        // std::cout << x.low << " " << x.hign << std::endl;
        this->calcPrime(x.low, x.hign);
    }
}

bool PrimeGen::isPrime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void PrimeGen::calcPrime(int low, int hign) {
    int i = (low > 2) ? low : 2;

    if ((i > hign) | (hign < 2)) {
        return;
    }

    if (i % 2 == 0) {
        if (i == 2) {
            this->results->insert(i);
        } 
        i += 1; 
    }

    for ( ; i <= hign; i += 2) {
        if (isPrime(i)) {
            this->results->insert(i);
        }
    }
}
