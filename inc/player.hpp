#ifndef PLAYER_HPP
    #define PLAYER_HPP
        #include <iostream>
        #include <vector>
        #include <string>
        #include "card.hpp"
        #include "person.hpp"

        using namespace std;

        class Player: public Person
        {
            private:
                // string name;
                vector<Card> mao;

            public:
                Player();
                Player(string name);
                void set_name(string name);
                string get_name();
                void set_cards(Card c);
                Card get_card(unsigned int position);
                Card show_card(unsigned int position);
                string display_card(unsigned int position);
                unsigned int card_quantity();
                void clear();
                friend istream &operator>>(istream &is, Player &p);
                ~Player();
        };
#endif
