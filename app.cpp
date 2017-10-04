#include "app.h"

Application::Application(std::regex pattern) : pattern(pattern) {
    this->results = std::make_shared<std::set<int>>();
    this->ranges = std::make_shared<std::vector<Range*>>();
    this->downloadXml();
}

Application::~Application() {}


void Application::downloadXml(std::string filename) {
    std::fstream f(SOURCEFILE);
    std::regex pattern1("<interval>"
            "(?:\\s*)<low>[\\s]*(\\d+)[\\s]*</low>"
            "(?:[\\d\\D]*?)<high>[\\s]*(\\d+)[\\s]*</high>"
            "(?:\\s*)</interval>");

    if (f) {
        std::string bufferStr((std::istreambuf_iterator<char>(f)),
                              std::istreambuf_iterator<char>());;
        std::smatch m;

        while (std::regex_search(bufferStr,m,this->pattern)) {
            Range temp = {std::stoi(m[1]), std::stoi(m[2])};
            ranges->push_back(&temp);
            bufferStr = m.suffix().str();
        }

      f.close();
    }
    else {
      throw FileErrorException();
    }
}