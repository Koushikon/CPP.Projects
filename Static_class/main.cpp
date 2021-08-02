#include <QCoreApplication>
#include "player.h"

void display_player(){
    cout<<"Active Player: "<<Player::get_num_player()<<"\n";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    display_player();
    Player player1;
    display_player();

    Player player2{"Anime"};
    Player player3{"One", 2, 3};
    display_player();

    {
        Player player4;
        Player player5;
        display_player();
    }
    display_player();

    return a.exec();
}
