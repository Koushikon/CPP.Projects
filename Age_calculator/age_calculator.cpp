#include "age_calculator.h"

// Function prototype
string input(string message);
void extract_date(string &&message, array<int, 3> &date);
int check_valid_year(int &year);

// Class constructor & desctructor

Age_calculator::Age_calculator(string _name) : name{_name} {}

Age_calculator::~Age_calculator()
{
    cout << "[#] " << name << " has died.\n";
}

// Class functions

void Age_calculator::getting_age()
{
    extract_date("Enter the Date of Birth", dob);
    dob.at(2) = check_valid_year(dob.at(2));

    extract_date("Enter the current date", c_date);
    c_date.at(2) = check_valid_year(c_date.at(2));

    // Implement pending current date lesser than the date of birth
}

void Age_calculator::calculate_age()
{
    for (size_t i{}; i < dob.size(); i++)
        dob.at(i) = c_date.at(i) - dob.at(i);
}

void Age_calculator::display_age()
{
    cout << "[#] " << name << " Now you are "
         << dob.at(2) << " Years, "
         << std::abs(dob.at(1)) << " Month, "
         << std::abs(dob.at(0)) << " Days old.\n";
}

// Standalone functions

string input(string message)
{
    string s1{};
    cout << "[+] " << message << "?\n"
         << "\tIn DD/MM/YYYY order: ";
    cin >> s1;
    return s1;
}

void extract_date(string &&message, array<int, 3> &date)
{
    stringstream str1{};
    str1 << input(message);

    size_t i{};
    while (str1.good() && i < 3)
    {
        string word{};
        getline(str1, word, '/');
        date.at(i++) = std::stoi(word);
    }
}

int check_valid_year(int &year)
{
    while (year < MIN_YEAR || year > CURRENT_YEAR)
    {
        if (year < MIN_YEAR)
            cout << "[+] You couldn't possibly that old\n";
        if (year > CURRENT_YEAR)
            cout << "[+] You excedded the current year\n";

        cout << "\tTry Entering year again? ";
        cin >> year;
    }
    return year;
}