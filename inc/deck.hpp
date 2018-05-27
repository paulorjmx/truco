#ifndef DECK_HPP
    #define DECK_HPP
        #include "card.hpp"
        #include <iostream>
        #include <vector>

        using namespace std;

        class Deck
        {
            private:
                 vector<Card> deck;

            public:
                Deck();
                ~Deck();
                // void shuffle();
                void print_deck();
                Card get_random_card();
        };
#endif
