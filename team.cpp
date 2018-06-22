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

void Team::set_points(unsigned int points)
{
    this->points = points;
}

void Team::set_card(unsigned int player_num, Card c)
{
    this->players[player_num].set_cards(c);
}

Card Team::get_card(unsigned int player_num, unsigned int card_position)
{
    return this->players[player_num].get_card(card_position);
}

unsigned int Team::get_points()
{
    return this->points;
}

string Team::display_player_card(unsigned int player_num)
{
    string cards;
    for(int i = 0; i < this->players[player_num].card_quantity(); i++)
    {
        cards += this->players[player_num].display_card(i);
        cards += ";";
    }
    return cards;
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
