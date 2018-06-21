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
                void set_points(const unsigned int points);
                unsigned int get_points();
                void display_player_name(unsigned int player_num);
                friend istream &operator>>(istream &is, Team &obj);
                ~Team();
        };
#endif
