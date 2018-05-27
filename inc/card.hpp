#ifndef CARD_HPP
    #define CARD_HPP

        class Card
        {
            private:
                char symbol, naipe;

            public:
                Card(char symbol, char naipe);
                Card(const Card &card);
                char get_symbol();
                char get_naipe();
                ~Card();
        };
#endif
