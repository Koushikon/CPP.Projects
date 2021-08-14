#ifndef _MOVIES_H_
#define _MOVIES_H_

#include "movie.h"

#include <vector>
#include <array>

using std::array;
using std::vector;

// Hardcoded values
const short MOVIES_APP_VERSION{1};

class Movies
{
    vector<Movie> movie_list;

public:
    Movies();
    ~Movies();

    void add_movie();
    bool movie_exists(const string &name) const;
    void watch_movie();
    void display_movies() const;
};

#endif /* _MOVIES_H_ */