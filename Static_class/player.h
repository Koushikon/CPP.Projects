#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include<string>

using std::cout;
using std::string;

class Player
{
    static int num_player;
    string name;
    int health, xp;
public:
    static int get_num_player();
    Player();
    Player(string name);
    Player(string name_val, int hel_val, int xp_val);
    ~Player();
};

#endif // PLAYER_H
