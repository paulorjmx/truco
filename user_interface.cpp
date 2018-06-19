#include "inc/user_interface.hpp"
#include <iomanip>

#define CENTER 30
#define LEFT 10
#define RIGHT 60

UserInterface::UserInterface() { }

void UserInterface::menu_title_bar(const string title)
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
            if(text.substr((i * RIGHT), RIGHT).length() >= RIGHT)
            {
                cout << setw(LEFT + RIGHT) << text.substr((i * RIGHT), RIGHT) << endl;
            }
            else
            {
                cout << setw(LEFT + text.substr((i * RIGHT), RIGHT).length()) << text.substr((i * RIGHT), RIGHT) << endl;
            }
        }
        it += (i * RIGHT);
        i++;
    }
}

void UserInterface::ui_container(const string content)
{

}
