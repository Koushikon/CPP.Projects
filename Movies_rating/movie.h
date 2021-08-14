#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

class Movie
{
    string name{}, rate{};
    short watched{}, r_year{};
    float review{};
    // string director;
    // double budget;

public:
    Movie(string _name, string _rate, short _r_year, float _review);
    ~Movie();

    void display_movie() const;
    bool check_single_movie(const string &new_name) const;
    void increase_watch();
};

#endif /* _MOVIE_H_ */