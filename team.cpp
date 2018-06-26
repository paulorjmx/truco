#include "inc/team.hpp"
#include <iomanip>

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

unsigned int Team::remaining_cards(unsigned int player_num)
{
    return this->players[player_num].card_quantity();
}

istream &operator>>(istream &is, Team &obj)
{
    cin >> obj.players[0];
    cin >> obj.players[1];
    return is;
}

string Team::display_player_name(unsigned int player_num)
{
    return this->players[player_num].get_name();
}

Card Team::get_strongest_card(Card vira)
{
    Card sc1, sc2, b; // Strongest card; p1, p2
    short int manilha = -1, position_1 = 0, position_2 = 0;
    if(vira.get_symbol() == 10) manilha = 1;
    else manilha = (vira.get_symbol() + 1);
    sc1 = this->players[0].show_card(0);
    sc2 = this->players[1].show_card(0);
    for(int i = 1; i < this->remaining_cards(0); i++)
    {
        if(sc1.get_symbol() == manilha || this->players[0].show_card(i).get_symbol() == manilha)
        {
            if(sc1.get_symbol() == manilha && this->players[0].show_card(i).get_symbol() == manilha)
            {
                if(this->players[0].show_card(i).get_naipe() > sc1.get_naipe())
                {
                    sc1 = this->players[0].show_card(i);
                    position_1 = i;
                }
            }
            else if(this->players[0].show_card(i).get_symbol() == manilha)
            {
                sc1 = this->players[0].show_card(i);
                position_1 = i;
            }
        }
        else
        {
            if(sc1.get_symbol() > 3)
            {
                if(this->players[0].show_card(i).get_symbol() >= 1 && this->players[0].show_card(i).get_symbol() <= 3)
                {
                    sc1 = this->players[0].show_card(i);
                    position_1 = i;
                }
                else
                {
                    if(sc1.get_symbol() < this->players[0].show_card(i).get_symbol())
                    {
                        sc1 = this->players[0].show_card(i);
                        position_1 = i;
                    }
                }
            }
        }
    }

    for(int i = 1; i < this->remaining_cards(1); i++)
    {
        if(sc2.get_symbol() == manilha || this->players[1].show_card(i).get_symbol() == manilha)
        {
            if(sc2.get_symbol() == manilha && this->players[1].show_card(i).get_symbol() == manilha)
            {
                if(this->players[1].show_card(i).get_naipe() > sc2.get_naipe())
                {
                    sc2 = this->players[1].show_card(i);
                    position_2 = i;
                }
            }
            else if(this->players[1].show_card(i).get_symbol() == manilha)
            {
                sc2 = this->players[1].show_card(i);
                position_2 = i;
            }
        }
        else
        {
            if(sc2.get_symbol() > 3)
            {
                if(this->players[1].show_card(i).get_symbol() >= 1 && this->players[1].show_card(i).get_symbol() <= 3)
                {
                    sc2 = this->players[1].show_card(i);
                    position_2 = i;
                }
                else
                {
                    if(sc2.get_symbol() < this->players[1].show_card(i).get_symbol())
                    {
                        sc2 = this->players[1].show_card(i);
                        position_2 = i;
                    }
                }
            }
        }
    }

    sc1 = this->get_card(0, position_1);
    sc2 = this->get_card(1, position_2);
    cout << setfill(' ') << setw(32 + this->display_player_name(0).length()) << this->display_player_name(0) << ": " << sc1.print_symbol() << sc1.print_naipe() << endl;
    cout << setfill(' ') << setw(32 + this->display_player_name(0).length()) << this->display_player_name(1) << ": " << sc2.print_symbol() << sc2.print_naipe() << endl;
    if(sc1.get_symbol() == manilha || sc2.get_symbol() == manilha)
    {
        if(sc1.get_symbol() == manilha && sc2.get_symbol() == manilha)
        {
            if(sc2.get_naipe() > sc1.get_naipe())
            {
                b = sc2;
            }
            else
            {
                b = sc1;
            }
        }
        else if(sc2.get_symbol() == manilha)
        {
            b = sc2;
        }
    }
    else
    {
        if(sc1.get_symbol() > 3)
        {
            if(sc2.get_symbol() >= 1 && sc2.get_symbol() <= 3)
            {
                b = sc2;
            }
            else
            {
                if(sc1.get_symbol() < sc2.get_symbol())
                {
                    b = sc2;
                }
                else
                {
                    b = sc1;
                }
            }
        }
        else
        {
            b = sc1;
        }
    }
    return b;
}

void Team::clear()
{
    this->players[0].clear();
    this->players[1].clear();
}

Team::~Team()
{
    this->points = 0;
}
