#include "app.h"

Application::Application(std::regex pattern) : pattern(pattern) {
    this->results = std::make_shared<std::set<int>>();
    this->ranges = std::make_shared<std::vector<Range>>();
    this->downloadXml();
}

Application::~Application() {}


void Application::downloadXml(std::string filename) {
    std::fstream f(SOURCEFILE, std::fstream::in);

    if (f.is_open()) {
        std::string bufferStr((std::istreambuf_iterator<char>(f)),
                              std::istreambuf_iterator<char>());;
        std::smatch m;

        while (std::regex_search(bufferStr,m,this->pattern)) {
            Range temp = {std::stoi(m[1]), std::stoi(m[2])};
            ranges->push_back(temp);
            bufferStr = m.suffix().str();
        }

      f.close();
    }
    else {
      throw FileErrorException();
    }
}


const std::shared_ptr<std::set<int>> Application::getResults() {
    return this->results;
}

const std::shared_ptr<std::vector<Range>> Application::getRanges() {
    return this->ranges;
}

std::regex Application::getPatt() {
    return this->pattern;
}
