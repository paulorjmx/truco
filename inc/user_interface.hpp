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
                void menu_box(unsigned int items, string *contents);

        };
#endif
