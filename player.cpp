#include "inc/player.hpp"

Player::Player(string name)
{
    this->name = name;
    this->mao.reserve(3);
}

Player::Player()
{
    this->name = "Unknown";
    this->mao.reserve(3);
}

void Player::set_name(string name)
{
    this->name = name;
}

string Player::get_name()
{
    return this->name;
}

string Player::display_card(unsigned int position)
{
    string output;
    output.push_back(this->mao[position].print_symbol());
    output.push_back(this->mao[position].print_naipe());
    return output;
}

unsigned int Player::card_quantity()
{
    return this->mao.size();
}

istream &operator>>(istream &is, Player &obj)
{
    cin >> obj.name;
    return is;
}

void Player::set_cards(Card c)
{
    if(this->mao.size() < 3)
    {
        this->mao.push_back(c);
    }
}

Card Player::get_card(unsigned int position)
{
    Card c;
    if(this->mao.size() > 0)
    {
        if(position >= 0 && position < 3)
        {
            c = this->mao[position];
            this->mao.erase(this->mao.begin() + position);
        }
    }
    return c;
}

Player::~Player()
{
    this->mao.clear();
}
