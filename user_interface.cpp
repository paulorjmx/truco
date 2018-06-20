#include "inc/user_interface.hpp"
#include <iomanip>

#define CENTER 30
#define LEFT 10
#define RIGHT 60

UserInterface::UserInterface() { }

void UserInterface::title_bar(const string title)
{
    cout << setw(CENTER) << "+" << setfill('-') << setw(title.length() + 5) << "+" << endl;
    cout << setfill(' ') << setw(CENTER) << "|" << setw(title.length() + 5) << "|" << endl;
    cout << setw(CENTER + 2) << "|  " << title << "  |" << endl;
    cout << setw(CENTER) << "|" << setfill(' ') << setw(title.length() + 5) << "|" << endl;
    cout << setw(CENTER) << "+" << setfill('-') << setw(title.length() + 5) << "+" << endl;
}

void UserInterface::text_box(string text)
{
    int i = 0;
    string::iterator it = text.begin();
    while(it < text.end())
    {
        if((i * RIGHT) < text.length())
        {
            cout << setw(LEFT + text.substr((i * RIGHT), RIGHT).length()) << text.substr((i * RIGHT), RIGHT) << endl;
        }
        it += (i * RIGHT);
        i++;
    }
}

void UserInterface::menu_box(unsigned int items, string *content)
{
    for(int i = 0; i < items; i++)
    {
        cout << "[" << i << "] " << content[i] << endl;
    }
}
