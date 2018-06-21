#ifndef PLAYER_HPP
    #define PLAYER_HPP
        #include <iostream>
        #include <vector>
        #include "card.hpp"

        using namespace std;

        class Player
        {
            private:
                string name;
                vector<Card> mao;

            public:
                Player();
                Player(string name);
                void set_name(string name);
                string get_name();
                void set_cards(Card c);
                Card get_card(unsigned int position);
                friend istream &operator>>(istream &is, Player &p);
                ~Player();
        };
#endif
