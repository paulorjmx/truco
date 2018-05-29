#ifndef DECK_HPP
    #define DECK_HPP
        #include "card.hpp"
        #include <iostream>
        #include <algorithm>
        #include <random>
        #include <vector>

        using namespace std;

        class Deck
        {
            private:
                 vector<Card> deck;
                 bool shuffled;

            public:
                Deck();
                ~Deck();
                void random_shuffle();
                void print_deck();
                unsigned int get_total_quatity();
                bool had_shuffled()
                Card get_card_top();
                Card get_card_bottom();
        };
#endif
