#include "app.h"

Application::Application(std::regex pattern, std::string sourceFile, std::string resFile) {
    this->pattern = pattern;
    this->sourceFile = sourceFile;
    this->resFile = resFile;
    this->results = std::make_shared<std::set<int>>();
    this->ranges = std::make_shared<std::vector<Range>>();
    this->downloadXml();
}

Application::~Application() {}


void Application::downloadXml() {
    std::fstream f(this->sourceFile, std::fstream::in);

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

void Application::uploadResults() {
    std::fstream f(this->sourceFile, std::fstream::in);
    
    if (f.is_open()) {
        std::fstream f1(this->resFile, std::fstream::out);
        std::string bufferStr((std::istreambuf_iterator<char>(f)),
                              std::istreambuf_iterator<char>());;


        this->genResultsStr(&bufferStr);

        f1.write(bufferStr.data(), bufferStr.size());

        f.close();
        f1.close();
    } else {
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
