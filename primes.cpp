// C++ program to demonstrate working of regex_match()

// C++ program to demonstrate working of regex_search()
#include <iostream>
#include <fstream>
#include <regex>
#include <string>


#define SOURCEFILE "source.xml"

 
int main() {
  std::ifstream f(SOURCEFILE);
  std::regex pattern("<interval>"
            "(?:\\s*)<low>[\\s]*(\\d+)[\\s]*</low>"
            "(?:[\\d\\D]*?)<high>[\\s]*(\\d+)[\\s]*</high>"
            "(?:\\s*)</interval>");


  if (f) {
    std::string bufferStr((std::istreambuf_iterator<char>(f)),
                            std::istreambuf_iterator<char>());;
    std::smatch m;


    while (std::regex_search (bufferStr,m,pattern)) {
        std::cout << "low " << m[1] << ";  high " << m[2];
        std::cout << std::endl;
        bufferStr = m.suffix().str();
      }
    }
  else {
    std::cout << "error: only " << f.gcount() << " could be read";
  }

  f.close();
    
  return 0;
}

