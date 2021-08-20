#include "movie.h"

Movie::Movie(string _name, string _rate, short _watched, short _r_year, float _review)
    : name{_name}, rate{_rate}, watched{_watched}, r_year{_r_year}, review{_review} {}

Movie::~Movie()
{
    cout << " \"" << name << "\" ";
}

void Movie::display_movie() const
{
    cout << "\t🎬 Name: " << name
         << "\n\t🎈 Release: " << r_year << " |🌠 Rating: " << rate
         << "\n\t⭐ User review: " << review << " |📺 Watched: " << watched
         << "\n\n";
}

bool Movie::check_single_movie(const string &new_name) const
{
    bool match{false};
    if (name == new_name)
        match = true;
    return match;
}

void Movie::increase_watch()
{
    watched++;
}