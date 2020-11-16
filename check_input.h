#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <limits>
#include <cmath>



namespace ITC {
    class pipe;
    class station;
    std::string check_input(std::vector<std::string>, std::string);
    bool check_ans(std::string);
    double check_input(std::string);  //просим число double
    int check_input_int(std::string); //просим число int
    std::string check_input_str(std::string);
    int menu();
}

