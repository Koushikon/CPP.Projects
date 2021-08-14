#ifndef _AGE_CALCULATOR_H_
#define _AGE_CALCULATOR_H_

#include <iostream>
#include <sstream>
#include <string>
#include <array>
#include <cstdlib>

using std::array;
using std::cin;
using std::cout;
using std::string;
using std::stringstream;

// Hardcoded values
const short AGE_CALCULATOR_VERSION{2};
const short MIN_YEAR{1950};
const short CURRENT_YEAR{2021};

class Age_calculator
{
private:
    string name{};
    array<int, 3> dob{}, c_date{};

public:
    Age_calculator(string _name);
    ~Age_calculator();

    void getting_age();
    void calculate_age();
    void display_age();
};

#endif /* _AGE_CALCULATOR_H_ */