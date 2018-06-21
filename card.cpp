#include "inc/card.hpp"

Card::Card()
{
    this->symbol = '0';
    this->naipe = '0';
}

Card::Card(char symbol, char naipe)
{
    this->symbol = symbol;
    this->naipe = naipe;
}

Card::Card(const Card &card)
{
    this->symbol = card.symbol;
    this->naipe = card.naipe;
}

char Card::get_symbol()
{
    return this->symbol;
}

char Card::get_naipe()
{
    return this->naipe;
}

Card::~Card()
{

}
