#include "inc/user_interface.hpp"
#include <iomanip>
#include <cstdlib>

#define CENTER 30
#define LEFT 10
#define RIGHT 60

UserInterface::UserInterface() { }

void UserInterface::title_bar(const string title)
{
    cout << setfill(' ') << setw(CENTER) << "+" << setfill('-') << setw(title.length() + 5) << "+" << endl;
    cout << setfill(' ') << setw(CENTER) << "|" << setw(title.length() + 5) << "|" << endl;
    cout << setw(CENTER + 2) << "|  " << title << "  |" << endl;
    cout << setw(CENTER) << "|" << setfill(' ') << setw(title.length() + 5) << "|" << endl;
    cout << setw(CENTER) << "+" << setfill('-') << setw(title.length() + 5) << "+" << endl << endl;
}

void UserInterface::text_box(string text)
{
    int i = 0;
    string::iterator it = text.begin();
    while(it < text.end())
    {
        if((i * RIGHT) < text.length())
        {
            cout << setfill(' ') << setw(CENTER + text.substr((i * RIGHT), RIGHT).length() - 1) << text.substr((i * RIGHT), RIGHT) << endl;
        }
        it += (i * RIGHT);
        i++;
    }
    cout << endl;
}

int UserInterface::menu_box(unsigned int items, string *content)
{
    int choice = -1;
    for(int i = 0; i < items; i++)
    {
        cout << setfill(' ') << setw(CENTER) << "[" << i << "] " << content[i] << endl;
    }
    cout << endl << setw(CENTER + 17) << "Enter the choice: ";
    cin >> choice;
    return choice;
}

void UserInterface::menu_choose_card(string cards)
{
    int pos = 0, qt_cards = 0, i = 0;
    while(pos < cards.length())
    {
        pos = cards.find(";", pos) + 1;
        qt_cards++;
    }
    pos = 0;
    cout << setfill(' ') << setw(CENTER + 3) << "[0] " << cards.substr(pos, 2) << endl;
    for(i = 1; i < qt_cards; i++)
    {
        pos = cards.find(";", pos) + 1;
        cout << setfill(' ') << setw(CENTER) << "[" << i << "] " << cards.substr(pos, 2) << endl;
    }
}

void UserInterface::clear_screen()
{
    #ifdef _WIN32
        system("cls");
    #endif

    #ifdef __linux__
        system("clear");
    #endif
}
