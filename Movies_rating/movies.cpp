#include "movies.h"

Movies::Movies() {}

Movies::~Movies() {}

void Movies::add_movie()
{
    string name{};
    short rate{}, year{};
    float star{};
    array<string, 5> rating{"G", "PG", "PG-13", "NC-17", "R"};

    if (movie_list.size() == 0 || movie_list.size() > 0)
    {
        cout << "[+] Create a new Movie\n"
             << "\tMovie name? ";
        std::getline(cin, name);

        if (movie_list.size() > 0)
        {
            while (movie_exists(name))
            {
                cout << "[#] This movie is already exists,\n\tTry entering new Movie? ";
                std::getline(cin, name);
            }
        }
    }

    cout << "[+] Movie rating: \n"
         << "\t1 for G\n"
         << "\t2 for PG\n"
         << "\t3 for PG-13\n"
         << "\t4 for NC-17\n"
         << "\t5 for R\n";
    do
    {
        cout << "Now, Your choice? ";
        cin >> rate;
        rate--;
    } while (rate < 0 || rate > 4);
    cout << "[+] Movie Release year? \n";
    do
    {
        cout << "\tIt should be between 1860 and Current year(2021)? ";
        cin >> year;
    } while (year < 1860 || year > 2021);
    do
    {
        cout << "[+] Your Review between 1 to 5.0? ";
        cin >> star;
    } while (star < 1 || star > 5.0);
    cin.ignore();

    {
        Movie *mv1 = new Movie{name, rating.at(rate), year, star};
        movie_list.push_back(*mv1);
        delete mv1;
    }
    cout << "[#] Movie: " << name << " added Successfully ✔\n";
}

bool Movies::movie_exists(const string &name) const
{
    bool is_movie_matched{false};
    for (const Movie &movie : movie_list)
        if (movie.check_single_movie(name))
            is_movie_matched = true;
    return is_movie_matched;
}

void Movies::watch_movie()
{
    if (movie_list.size() == 0)
    {
        cout << "[#] The movies list is empty, First try to create a movie\n";
        add_movie();
    }
    else if (movie_list.size() > 0)
    {
        string name{};
        cout << "[+] Enter Watched Movie name? ";
        getline(cin, name);

        bool found{false};
        for (Movie &movie : movie_list)
            if (movie.check_single_movie(name))
            {
                movie.increase_watch();
                cout << "[#] Movie: " << name << " watched Successfully ✔\n";
                found = true;
            }
        if (!found)
            cout << "[#] There aren't any movie name " << name
                 << ", Try Creating first !\n";
    }
}

void Movies::display_movies() const
{
    cout << "\n[🥽] Movies list: \n";
    if (movie_list.size() == 0)
        cout << "\t--: EMPTY :--\n";
    for (const Movie &movie : movie_list)
        movie.display_movie();
}