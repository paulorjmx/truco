#include "inc/card.hpp"

Card::Card()
{
    this->symbol = -1;
    this->naipe = PAUS;
}

Card::Card(char symbol, Naipe naipe)
{
    if(symbol == 'A')
    {
        this->symbol = 1;
    }
    else if(symbol == 'Q')
    {
        this->symbol = 8;
    }
    else if(symbol == 'J')
    {
        this->symbol = 9;
    }
    else if(symbol == 'K')
    {
        this->symbol = 10;
    }
    else
    {
        this->symbol = (symbol & 0x000F);
    }
    this->naipe = naipe;
}

Card::Card(const Card &card)
{
    this->symbol = card.symbol;
    this->naipe = card.naipe;
}

void Card::clear()
{
    this->symbol = -1;
    this->naipe = PAUS;
}

Card &Card::operator=(const Card &c)
{
    if(this == &c)
    {
        return *this;
    }
    symbol = c.symbol;
    naipe = c.naipe;
    return *this;
}

char Card::print_symbol()
{
    char tmp_symbol = 0x00;
    if(this->symbol == 1)
    {
        tmp_symbol = 'A';
    }
    else if(this->symbol == 8)
    {
        tmp_symbol = 'Q';
    }
    else if(this->symbol == 9)
    {
        tmp_symbol = 'J';
    }
    else if(this->symbol == 10)
    {
        tmp_symbol = 'K';
    }
    else
    {
        tmp_symbol = (this->symbol | 0x0030);
    }
    return tmp_symbol;
}

Card::Naipe Card::get_naipe()
{
    return this->naipe;
}

char Card::print_naipe()
{
    char s;
    switch(this->naipe)
    {
        case PAUS:
            s = 'p';
            break;

        case COPAS:
            s = 'c';
            break;

        case ESPADA:
            s = 'e';
            break;

        case OUROS:
            s = 'o';
            break;
    }
    return s;
}

short int Card::get_symbol()
{
    return this->symbol;
}

Card::~Card()
{
    this->clear();
}
