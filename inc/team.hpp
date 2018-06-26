#ifndef TEAM_HPP
    #define TEAM_HPP
        #include <iostream>
        #include "player.hpp"

        using namespace std;

        class Team
        {
            private:
                Player players[2];
                unsigned int points;

            public:
                Team();
                Team(string player1_name, string player2_name);
                void set_points(unsigned int points);
                void set_card(unsigned int player_num, Card c);
                Card get_card(unsigned int player_num, unsigned int card_position);
                unsigned int get_points();
                unsigned int remaining_cards(unsigned int player_num);
                string display_player_name(unsigned int player_num);
                string display_player_card(unsigned int player_num);
                Card get_strongest_card(Card vira);
                void clear();
                friend istream &operator>>(istream &is, Team &obj);
                ~Team();
        };
#endif
