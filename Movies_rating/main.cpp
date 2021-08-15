#include "movies.h"

int main()
{
    // while (true)
    // {
    //     cout << "\n\n=========================="
    //          << "| Press,\n"
    //          << "|\tP-- >> To print numbers.\n"
    //          << "|\tA -->> To Add a number.\n"
    //          << "|\tR -->> To remove the last number.\n"
    //          << "|\tF -->> To find the number you want\n"
    //          << "|\tT or M -->> To display the Total & Mean of the numbers.\n"
    //          << "|\tS -->> To display the smallest number.\n"
    //          << "|\tL -->> To display the largest number.\n"
    //          << "|\tQ -->> To quit.\n"
    //          << "| \tSo, What's your choice? ";
    // }

    cout << "= = = = = = = = = = =\n"
         << "Movies® App version " << MOVIES_APP_VERSION << "\n\n";

    {
        Movies mvs1;
        // mvs1.display_movies();
        // mvs1.watch_movie();
        mvs1.add_movie();
        mvs1.add_movie();
        mvs1.watch_movie();
        mvs1.watch_movie();
        mvs1.display_movies();
    }
    cout << " Destroyed\n\n";

    cout << "= = = = = X = = = = =\n";

    return 0;
}