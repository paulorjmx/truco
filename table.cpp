#include "inc/table.hpp"
#include <iomanip>

Table::Table()
{
    for(int i = 0; i < 4; i++)
    {
        this->cards[i].clear();
    }
    this->vira.clear();
    this->cards_on = 0;
}

void Table::set_card(Card c, unsigned int position)
{
    if(this->cards_on < 4)
    {
        this->cards[position] = c;
        this->cards_on++;
    }
}

unsigned int Table::get_cards_on()
{
    return this->cards_on;
}

void Table::clear()
{
    for(int i = 0; i < 4; i++)
    {
        this->cards[i].clear();
    }
    this->cards_on = 0;
}

void Table::set_vira(Card c)
{
    this->vira = c;
}

Card Table::get_vira()
{
    return this->vira;
}

string Table::display_cards()
{
    string output;
    for(int i = 0; i < 4; i++)
    {
        if(this->cards[i].get_symbol() != -1)
        {
            output.push_back(this->cards[i].print_symbol());
            output.push_back(this->cards[i].print_naipe());
        }
        else
        {
            output.push_back('?');
        }
        output += " ";
    }
    return output;
}

string Table::display_vira()
{
    string output;
    output = "Vira ";
    output.push_back(this->vira.print_symbol());
    output.push_back(this->vira.print_naipe());
    return output;
}

int Table::calculate_round_winner()
{
    Card tmp_best_card;
    short int tmp_winner = 0, i = 1, manilha = 0;
    if(this->vira.get_symbol() == 10) manilha = 1;
    else manilha = (this->vira.get_symbol() + 1);
    tmp_best_card = this->cards[0];
    while(i < 4)
    {
        if((tmp_best_card.get_symbol() == manilha) || (this->cards[i].get_symbol() == manilha))
        {
            cout << "manilha" << endl;
            if((tmp_best_card.get_symbol() == manilha) && (this->cards[i].get_symbol() == manilha))
            {
                if(tmp_best_card.get_naipe() < this->cards[i].get_naipe())
                {
                    tmp_winner = i;
                    tmp_best_card = this->cards[i];
                }
            }
            else if((this->cards[i].get_symbol() == manilha))
            {
                tmp_winner = i;
                tmp_best_card = this->cards[i];
            }
        }
        else
        {
            if(tmp_best_card.get_symbol() >= 1 && tmp_best_card.get_symbol() <= 3)
            {
                if(this->cards[i].get_symbol() >= 1 && this->cards[i].get_symbol() <= 3)
                {
                    if(tmp_best_card.get_symbol() < this->cards[i].get_symbol())
                    {
                        tmp_winner = i;
                        tmp_best_card = this->cards[i];
                    }
                    else if(tmp_best_card.get_symbol() == this->cards[i].get_symbol())
                    {
                        if(tmp_winner == 0)
                        {
                            if(i != 2)
                            {
                                tmp_winner = -1;
                                break;
                            }
                        }
                        else
                        {
                            if(tmp_winner == 1)
                            {
                                if(i != 3)
                                {
                                    tmp_winner = -1;
                                    break;
                                }
                            }
                            else if(tmp_winner == 2)
                            {
                                tmp_winner = -1;
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                if(this->cards[i].get_symbol() >= 1 && this->cards[i].get_symbol() <= 3)
                {
                    tmp_winner = i;
                    tmp_best_card = this->cards[i];
                }
                else if(tmp_best_card.get_symbol() < this->cards[i].get_symbol())
                {
                    tmp_winner = i;
                    tmp_best_card = this->cards[i];
                }
                else if(tmp_best_card.get_symbol() == this->cards[i].get_symbol())
                {
                    if(tmp_winner == 0)
                    {
                        if(i != 2)
                        {
                            tmp_winner = -1;
                            break;
                        }
                    }
                    else
                    {
                        if(tmp_winner == 1)
                        {
                            if(i != 3)
                            {
                                tmp_winner = -1;
                                break;
                            }
                        }
                        else if(tmp_winner == 2)
                        {
                            tmp_winner = -1;
                            break;
                        }
                    }
                }
            }
        }
        i++;
    }
    this->clear();
    return tmp_winner;
}

int Table::decide_draw(Card strong_card1, Card strong_card2)
{
    int tmp_winner = -1, manilha = 0;
    if(this->vira.get_symbol() == 10) manilha = 1;
    else manilha = (this->vira.get_symbol() + 1);
    if((strong_card1.get_symbol() == manilha) || (strong_card2.get_symbol() == manilha))
    {
        if((strong_card1.get_symbol() == manilha) && (strong_card2.get_symbol() == manilha))
        {
            if(strong_card1.get_naipe() < strong_card2.get_naipe())
            {
                tmp_winner = 1;
            }
        }
        else if((strong_card2.get_symbol() == manilha))
        {
            tmp_winner = 2;
        }
    }
    else
    {
        if(strong_card1.get_symbol() >= 1 && strong_card1.get_symbol() <= 3)
        {
            if(strong_card2.get_symbol() >= 1 && strong_card2.get_symbol() <= 3)
            {
                if(strong_card2.get_symbol() > strong_card1.get_symbol())
                {
                    tmp_winner = 2;
                }
                else if(strong_card2.get_symbol() < strong_card1.get_symbol())
                {
                    tmp_winner = 1;
                }
                else
                {
                    tmp_winner = -1;
                }
            }
            else
            {
                tmp_winner = 1;
            }
        }
        else
        {
            if(strong_card2.get_symbol() >= 1 && strong_card2.get_symbol() <= 3)
            {
                tmp_winner = 2;
            }
            else if(strong_card1.get_symbol() < strong_card2.get_symbol())
            {
                tmp_winner = 2;
            }
            else if(strong_card1.get_symbol() > strong_card2.get_symbol())
            {
                tmp_winner = 1;
            }
            else
            {
                 tmp_winner = -1;
            }
        }
    }
    return tmp_winner;
}

Table::~Table()
{
    for(int i = 0; i < 4; i++)
    {
        this->cards[i].clear();
    }
    this->vira.clear();
    this->cards_on = 0;
}
