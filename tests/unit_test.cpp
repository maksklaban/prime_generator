#include <fstream>
#include <iostream>
#include <memory>
#include <regex>
#include <string>
#include <set>
#include <thread>
#include <mutex>

#include "../app.h"
#include "../prime.h"
#include "catch.hpp"


TEST_CASE("prime generator test(test.xml filesource)", "[PrimeGen]") { 
    std::regex pattern("<interval>"
        "(?:[\\d\\D]*?)<low>[\\s]*(-?\\d+)[\\s]*</low>"
        "(?:[\\d\\D]*?)<high>[\\s]*(-?\\d+)[\\s]*</high>"
        "(?:[\\d\\D]*?)</interval>");

    std::string sourcename("test.xml");
    auto test = new PrimeGen(pattern, sourcename);

    SECTION("Download xml results") {
        auto ranges = test->getRanges();

        REQUIRE(test->getSourceFileName() == "test.xml");
        REQUIRE(ranges->empty() == false);
        REQUIRE(ranges->size() == 3);
        REQUIRE((*ranges)[0].low == 100);
        REQUIRE((*ranges)[0].hign == 200);
        REQUIRE((*ranges)[2].hign == 222);
    }

    SECTION("Calculation results") {
        std::shared_ptr<std::set<int>> results;

        test->calculate();

        results = test->getResults();

        REQUIRE(results->empty() == false);
        REQUIRE(results->size() == 81);
        REQUIRE(results->count(2) == 0);
        REQUIRE(results->count(-1) == 0);
        REQUIRE(results->count(101) == 1);
        REQUIRE(results->count(199) == 1);
        REQUIRE(results->count(211) == 1);
        REQUIRE(results->count(223) == 0);
        REQUIRE(results->count(887) == 1);
        REQUIRE(results->count(907) == 0);
    }

    SECTION("Result file tests") {
        using Catch::Matchers::Contains;

        std::fstream f(test->getResFileName());
        std::string bufferStr((std::istreambuf_iterator<char>(f)),
                      std::istreambuf_iterator<char>());
        long size;

        REQUIRE(f.is_open() == true);

        REQUIRE_THAT( bufferStr, Contains("<prime> 101 103 107 109 113 127 131 137 139 149 151 157 163 167 173 179 181"
                                          " 191 193 197 199 211 503 509 521 523 541 547 557 563 569 571 577 587 593 599"
                                          " 601 607 613 617 619 631 641 643 647 653 659 661 673 677 683 691 701 709 719"
                                          " 727 733 739 743 751 757 761 769 773 787 797 809 811 821 823 827 829 839 853"
                                          " 857 859 863 877 881 883 887 </prime>"));
        
        f.seekg (0,f.end);
        size = f.tellg();
        REQUIRE(size == 636);

        f.close();
    }
}

TEST_CASE("prime generator test(test1.xml filesource)", "[PrimeGen]") {
    std::regex pattern("<interval>"
        "(?:[\\d\\D]*?)<low>[\\s]*(-?\\d+)[\\s]*</low>"
        "(?:[\\d\\D]*?)<high>[\\s]*(-?\\d+)[\\s]*</high>"
        "(?:[\\d\\D]*?)</interval>");

    std::string sourcename("test1.xml");
    std::string resultname("result1.xml");
    auto test = new PrimeGen(pattern, sourcename, resultname);

    SECTION("Download xml results") {
        auto ranges = test->getRanges();

        REQUIRE(test->getSourceFileName() == "test1.xml");
        REQUIRE(test->getResFileName() == "result1.xml");
        REQUIRE(ranges->empty() == false);
        REQUIRE(ranges->size() == 4);
        REQUIRE((*ranges)[0].low == -100);
        REQUIRE((*ranges)[0].hign == 100);
        REQUIRE((*ranges)[2].hign == 173);
        REQUIRE((*ranges)[3].hign == 100);
    }

    SECTION("Calculation results") {
        std::shared_ptr<std::set<int>> results;

        test->calculate();

        results = test->getResults();

        REQUIRE(results->empty() == false);
        REQUIRE(results->size() == 26);
        REQUIRE(results->count(2) == 1);
        REQUIRE(results->count(5) != 2);
        REQUIRE(results->count(-1) == 0);
        REQUIRE(results->count(101) == 0);
        REQUIRE(results->count(199) == 0);
        REQUIRE(results->count(11) == 1);
        REQUIRE(results->count(13) == 1);
        REQUIRE(results->count(1) == 0);
        REQUIRE(results->count(-13) == 0);
        REQUIRE(results->count(173) == 1);
        }

    SECTION("Result file tests") {
        using Catch::Matchers::Contains;

        std::fstream f(test->getResFileName());
        std::string bufferStr((std::istreambuf_iterator<char>(f)),
                      std::istreambuf_iterator<char>());

        REQUIRE(f.is_open() == true);

        REQUIRE_THAT( bufferStr, Contains("<prime> 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 "
                                          "79 83 89 97 173 </prime> \n  </root>"));

        f.close();
    }
}