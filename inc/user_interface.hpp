#ifndef USER_INTERFACE_H
    #define USER_INTERFACE_H
        #include <iostream>
        #include <string>

        using namespace std;

        class UserInterface
        {
            public:
                UserInterface();
                void title_bar(const string title);
                void text_box(string text);
                int menu_box(unsigned int items, string *contents);
                void menu_choose_card(string cards);
                void clear_screen();
        };
#endif
