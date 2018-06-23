#ifndef CARD_HPP
    #define CARD_HPP

        class Card
        {
            public:
                enum Naipe
                {
                    PAUS = 4,
                    COPAS = 3,
                    ESPADA = 2,
                    OUROS = 1
                };
                Card();
                Card(char symbol, Naipe naipe);
                Card(const Card &card);
                void clear();
                char print_symbol();
                short int get_symbol();
                Naipe get_naipe();
                char print_naipe();
                bool operator==(const Card &c) const;
                ~Card();
                
            private:
                short int symbol;
                Naipe naipe;

        };
#endif
