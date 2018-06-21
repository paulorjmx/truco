#ifndef TEAM_HPP
    #define TEAM_HPP
    
        #include "player.hpp"

        class Team
        {
            private:
                Player players[2];
                unsigned int points;

            public:
                Team(string player1_name, string player2_name);
                void set_points(const unsigned int points);
                unsigned int get_points();
                ~Team();
        };
#endif
