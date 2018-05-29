#ifndef PLAYER_HPP
    #define PLAYER_HPP
        #include "card.hpp"

        // enum Team { TeamOne, TeamTwo };
        class Player
        {
            private:
                string name;
                vector<Card> mao;
                // Team t;

            public:
                Player(string name);
                void set_cards(Card c);
                Card get_card(unsigned int position);
                ~Player();
        };
#endif
