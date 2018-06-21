#include "inc/user_interface.hpp"
#include "inc/deck.hpp"
#include "inc/player.hpp"
#include "inc/team.hpp"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    UserInterface ui;
    Deck baralho;
    Team players[4];
    bool game_over = false;
    int menu_choice = -1;
    string *menu_content = new string[3];
    menu_content[0] = "Play Truco++";
    menu_content[1] = "Options";
    menu_content[2] = "Exit";
    while(game_over == false)
    {
        ui.clear_screen();
        ui.title_bar("Welcome to Truco++");
        ui.text_box("The best brazilian card game ever!");
        menu_choice = ui.menu_box(3, menu_content);
        if(menu_choice == 0)
        {
            ui.clear_screen();

        }
        else if(menu_choice == 1)
        {

        }
        else // Free resources
        {
            delete[] menu_content;
            game_over = true;
        }
    }
    return 0;
}
