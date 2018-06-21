#include "inc/team.hpp"

Team::Team()
{
    this->points = 0;
}

Team::Team(string player1_name, string player2_name)
{
    this->players[0].set_name(player1_name);
    this->players[1].set_name(player2_name);
    this->points = 0;
}

void Team::set_points(const unsigned int points)
{
    this->points = points;
}

unsigned int Team::get_points()
{
    return this->points;
}

istream &operator>>(istream &is, Team &obj)
{
    cin >> obj.players[0];
    cin >> obj.players[1];
    return is;
}

void Team::display_player_name(unsigned int player_num)
{
    cout << this->players[player_num].get_name();
}

Team::~Team()
{
    this->points = 0;
}
