#ifndef USER_INTERFACE_H
    #define USER_INTERFACE_H
        #include <iostream>
        #include <string>

        using namespace std;

        class UserInterface
        {
            public:
                UserInterface();
                void menu_title_bar(const string title);
                void text_box(string text);
                void ui_container(const string content);
        };
#endif
