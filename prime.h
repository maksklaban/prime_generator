#ifndef PRIMEGEN_H
#define PRIMEGEN_H

#include "app.h"


class PrimeGen : public Application {
    private:
        bool isPrime(int n);
        void calcPrime(int low, int hign);
    public:
        PrimeGen(std::regex pattern);
        virtual ~PrimeGen();
        
        void calculate();
};


#endif //PRIMEGEN_H
