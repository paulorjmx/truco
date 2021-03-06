#ifndef TABLE_HPP
    #define TABLE_HPP
        #include <iostream>
        #include <string>
        #include "team.hpp"
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
                Card get_vira();
                void clear();
                void display_cards(Team *t);
                string display_vira();
                unsigned int get_cards_on();
                int calculate_round_winner();
                int decide_draw(Card strong_card1, Card strong_card2);
                ~Table();
        };
#endif
