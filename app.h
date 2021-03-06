#ifndef APPLICATION_H
#define APPLICATION_H

#include <fstream>
#include <iostream>
#include <memory>
#include <regex>
#include <string>
#include <set>
#include <thread>
#include <mutex>

#define SOURCEFILE "source.xml"
#define RESULTFILE "result.xml"

typedef struct {
    int low;
    int hign;
} Range;


class FileErrorException {};


class Application {
    protected:
        std::shared_ptr<std::set<int>> results;
        std::shared_ptr<std::vector<Range>> ranges;
        std::regex pattern;
        std::string sourceFile;
        std::string resFile;

        void downloadXml();
        void uploadResults();
        virtual void genResultsStr(std::string* buffer) = 0; 
    public:
        Application(std::regex pattern, std::string sourceFile=SOURCEFILE, std::string resFile=RESULTFILE);
        virtual ~Application();

        const std::string getSourceFileName() const;
        const std::string getResFileName() const;
        const std::regex getPatt() const;
        const std::shared_ptr<std::vector<Range>> getRanges() const;
        const std::shared_ptr<std::set<int>> getResults() const;


        virtual void calculate() = 0;
};

#endif //APPLICATION_H
