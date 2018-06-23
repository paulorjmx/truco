#ifndef TABLE_HPP
    #define TABLE_HPP
        #include <iostream>
        #include <string>
        #include "card.hpp"

        using namespace std;

        class Table
        {
            private:
                Card cards[4], vira;
                unsigned int cards_on;

            public:
                Table();
                void set_card(Card c, unsigned int position);
                void set_vira(Card c);
                void clear();
                string display_table();
                unsigned int get_cards_on();
                int calculate_round_winner();
                ~Table();
        };
#endif