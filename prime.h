#ifndef PRIMEGEN_H
#define PRIMEGEN_H

#include "app.h"


class PrimeGen : public Application {
    protected:
        std::mutex mtx;
        
        bool isPrime(int n);
        void calcPrime(int low, int hign);

        void genResultsStr(std::string* buffer) override;
    public:
        PrimeGen(std::regex pattern, std::string sourceFile=SOURCEFILE, std::string resFile=RESULTFILE);
        virtual ~PrimeGen();
        
        void calculate() override;
};


#endif //PRIMEGEN_H
