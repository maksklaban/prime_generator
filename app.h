#ifndef APPLICATION_H
#define APPLICATION_H

#include <fstream>
#include <iostream>
#include <memory>
#include <regex>
#include <string>
#include <set>

#define SOURCEFILE "source.xml"
#define RESULTFILE "result.xml"

typedef struct {
    int low;
    int hign;
} Range;


class FileErrorException {};


class Application {
    private:
        std::shared_ptr<std::set<int>> results;
        std::regex pattern;
        std::shared_ptr<std::vector<Range*>> ranges;

    public:
        Application(std::regex pattern);
        virtual ~Application();

        // const std::shared_ptr<std::regex> getPatt();
        // const std::shared_ptr<std::vector<Range*>> getRanges();

        void downloadXml(std::string filename=SOURCEFILE);
        // void uploadResults(std::string filename=RESULTFILE);

        // virtual void calculate() = 0;
};

#endif //APPLICATION_H
