#include "inc/team.hpp"

Team::Team(string player1_name, string player2_name)
{
    this->players[0].set_name(player1_name);
    this->players[1].set_name(player2_name);
}

void Team::set_points(const unsigned int points)
{

}

unsigned int Team::get_points()
{

}

Team::~Team()
{

}
