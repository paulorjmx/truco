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
    Team teams[2]; // Team[0] is the team of the player
    bool game_over = false;
    int menu_choice = -1;
    string *menu_content = NULL, *option_content = NULL;
    menu_content = new string[3];
    option_content = new string[2];

    menu_content[0] = "Play Truco++";
    menu_content[1] = "Options";
    menu_content[2] = "Exit";

    option_content[0] = "Edit name of the players";
    option_content[1] = "Back";
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
            ui.clear_screen();
            ui.title_bar("Options - Truco++");
            ui.text_box("In this menu you can change some settings or back to the main menu.");
            menu_choice = ui.menu_box(2, option_content);
            if(menu_choice == 0)
            {
                ui.clear_screen();
                ui.title_bar("Options - Edit name of players");
                ui.text_box("Type the name that you and your partner like to have");
                cin >> teams[0];
                ui.clear_screen();
                ui.title_bar("Options - Edit name of players");
                ui.text_box("Type the name that you want the other players to have");
                cin >> teams[1];

            }
        }
        else // Free resources
        {
            delete[] menu_content;
            delete[] option_content;
            game_over = true;
        }
    }
    return 0;
}
