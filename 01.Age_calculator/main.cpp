#include "age_calculator.h"

int main(int argc, char *argv[])
{
    cout << "= = = = = = = = = = =\n"
         << "Calculator® version " << AGE_CALCULATOR_VERSION << "\n";

    char choice{};
    do
    {
        // Setup user name
        string name{};
        cout << "\n[+] Enter name: ";
        getline(cin, name);

        // Calculating age
        Age_calculator age{name};
        age.getting_age();
        age.calculate_age();
        age.display_age();

        // Getting secend choice
        cout << "[+] Would you like to calculate another age, 😁 My Good sir.\n"
             << "\tPress \"y\" for continue? ";
        cin >> choice;
    } while (tolower(choice) == 'y');

    cout << "= = = = = X = = = = =\n";

    return 0;
}