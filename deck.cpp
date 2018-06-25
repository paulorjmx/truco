#include "inc/deck.hpp"

Deck::Deck()
{
    this->shuffled = false;
    this->deck.reserve(40);
    char symbols[10] = { 'A', '2', '3', '4', '5', '6', '7', 'Q', 'J', 'K' };
    Card::Naipe naipes[4] = { Card::COPAS, Card::ESPADA, Card::OUROS, Card::PAUS}; // Copa, Espada, Ouros e Paus
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            this->deck.push_back(Card(symbols[i], naipes[j]));
        }
    }
}

void Deck::create()
{
    this->shuffled = false;
    this->deck.clear();
    char symbols[10] = { 'A', '2', '3', '4', '5', '6', '7', 'Q', 'J', 'K' };
    Card::Naipe naipes[4] = { Card::COPAS, Card::ESPADA, Card::OUROS, Card::PAUS}; // Copa, Espada, Ouros e Paus
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            this->deck.push_back(Card(symbols[i], naipes[j]));
        }
    }
}

void Deck::print_deck()
{
    for(vector<Card>::iterator it = this->deck.begin(); it < this->deck.end(); it++)
    {
        cout << (*it).print_symbol() << " " << (*it).print_naipe() << endl;
    }
}

void Deck::random_shuffle()
{
    random_device rd;
    mt19937 marsenne(rd());
    shuffle(this->deck.begin(), this->deck.end(), marsenne);
}

Card Deck::get_card_top()
{
    Card c = this->deck.back();
    this->deck.pop_back();
    return c;
}

Card Deck::get_card_bottom()
{
    Card c = this->deck.front();
    this->deck.erase(this->deck.begin());
    return c;
}

bool Deck::had_shuffled()
{
    return this->shuffled;
}

unsigned int Deck::get_total_quatity()
{
    return this->deck.size();
}

Deck::~Deck()
{
    this->deck.clear();
}
