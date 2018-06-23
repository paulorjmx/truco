#include "inc/table.hpp"

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

string Table::display_table()
{
    string output = "Vira ";
    output.push_back(this->vira.print_symbol());
    output.push_back(this->vira.print_naipe());
    return output;
}

int Table::calculate_round_winner()
{
    Card tmp_best_card;
    int tmp_winner = -1;
    tmp_best_card = this->cards[0];
    for(int i = 1; i < 4; i++)
    {
        if(tmp_best_card.get_symbol() == (this->vira.get_symbol() + 1) && this->cards[i].get_symbol() == (this->vira.get_symbol() + 1))
        {
            if(tmp_best_card.get_naipe() < this->cards[i].get_naipe())
            {
                tmp_best_card = this->cards[i];
                tmp_winner = i;
            }
        }
        else
        {
            if(this->cards[i].get_symbol() == (this->vira.get_symbol() + 1))
            {

            }
            else if(this->cards[i].get_symbol() == (this->vira.get_symbol() + 1))
            {
                tmp_best_card = this->cards[i];
                tmp_winner = i;
            }
            else if((tmp_best_card.get_symbol() >= 1 && tmp_best_card.get_symbol() <= 3) || (this->cards[i].get_symbol() >= 1 && this->cards[i].get_symbol() <= 3))
            {
                if(this->cards[i].get_symbol() >= 1 && this->cards[i].get_symbol() <= 3)
                {
                    if(tmp_best_card.get_symbol() >= 1 && tmp_best_card.get_symbol() <= 3)
                    {
                        if(this->cards[i].get_symbol() > tmp_best_card.get_symbol())
                        {
                            tmp_best_card = this->cards[i];
                            tmp_winner = i;
                        }
                        else if(this->cards[i].get_symbol() == tmp_best_card.get_symbol())
                        {
                            tmp_winner = -1;
                            break;
                        }
                    }
                    else
                    {
                        tmp_best_card = this->cards[i];
                        tmp_winner = i;
                    }
                }
            }
            else
            {
                if(this->cards[i].get_symbol() > tmp_best_card.get_symbol())
                {
                    tmp_best_card = this->cards[i];
                    tmp_winner = i;
                }
                else if(this->cards[i].get_symbol() == tmp_best_card.get_symbol())
                {
                    tmp_winner = -1;
                    break;
                }
            }
        }
    }
    this->clear();
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
