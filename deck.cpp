#include "inc/deck.hpp"

Deck::Deck()
{
    this->deck.reserve(40);
    char symbols[10] = { 'A', '2', '3', '4', '5', '6', '7', 'Q', 'J', 'K' };
    char naipes[4] = { 'c', 'e', 'o', 'p'}; // Copa, Espada, Ouros e Paus
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
        cout << (*it).get_symbol() << " " << (*it).get_naipe() << endl;
    }
}

Deck::~Deck()
{
    this->deck.clear();
}
