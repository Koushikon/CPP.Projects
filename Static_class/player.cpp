#include "player.h"

int Player::num_player = 0;

int Player::get_num_player(){
    return num_player;
}

Player::Player(string name_val, int hel_val, int xp_val) : name{name_val}, health{hel_val}, xp{xp_val}{
    ++num_player;
    cout<<"\tIncreasing \n";
}

Player::Player() :Player{"", 0, 0}{}

Player::Player(string name) :Player{name, 0, 0}{}

Player::~Player(){
    --num_player;
    cout<<"\tDecreasing \n";
}
