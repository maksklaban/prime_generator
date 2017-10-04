#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <set>

#define SOURCEFILE "source.xml"
#define RESULTFILE "result.xml"

typedef struct {
    int low;
    int hign;
} Range;


class Application {
    private:
        std::set<int>* results;
        std::regex* pattern;
        std::vector<Range*>* ranges;
        std::fstream* data;
    public:
        Application(std::regex* pattern);
        virtual ~Application();

        const std::regex& getPatt();
        const std::std::vector<Range*>& getRanges();

        void downloadXml(std::string filename=SOURCEFILE);
        void uploadResults(std::string filename=RESULTFILE);

        virtual void calculate() = 0;
};
