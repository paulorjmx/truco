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

void set_name(string name)
{
    this->name = name;
}

string get_name()
{
    return this->name;
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
