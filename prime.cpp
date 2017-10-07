#include "prime.h"

PrimeGen::PrimeGen(std::regex pattern, std::string sourceFile, std::string resFile) : Application(pattern, sourceFile, resFile) {}

PrimeGen::~PrimeGen() {}

void PrimeGen::genResultsStr(std::string* buffer) {
    std::size_t pos = buffer->find("</root>");
    std::string buff("  <prime> ");

    for (auto x: *(this->results)) {
        buff += std::to_string(x);
        buff += " ";
    }

    buff += "</prime> \n  ";

    buffer->insert(pos, buff);
}

void PrimeGen::calculate() {
    std::vector<std::thread> threads;

    for (auto x: *(this->ranges)) {
        threads.push_back(std::thread(&PrimeGen::calcPrime, this, x.low, x.hign));
        
    }
    for (auto& y: threads) {
        y.join();
    }

    this->uploadResults();
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
            this->mtx.lock();
            this->results->insert(i);
            this->mtx.unlock();
        } 
        i += 1; 
    }

    for ( ; i <= hign; i += 2) {
        if (isPrime(i)) {
            this->mtx.lock();
            this->results->insert(i);
            this->mtx.unlock();
        }
    }
}
