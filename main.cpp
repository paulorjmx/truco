#include "inc/user_interface.hpp"
#include "inc/card.hpp"
#include "inc/deck.hpp"
#include "inc/player.hpp"
#include "inc/team.hpp"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main(int argc, char const *argv[])
{
    UserInterface ui;
    Deck baralho;
    Card mesa[4], vira;
    Team teams[2]; // Team[0] is the team of the player
    bool game_over = false, round_over = false;
    int menu_choice = -1, max_matches = 1, match = 0, begin_play = 0, next_player = 0;
    string *menu_content = NULL, *option_content = NULL;
    menu_content = new string[3];
    option_content = new string[3];

    menu_content[0] = "Play Truco++";
    menu_content[1] = "Options";
    menu_content[2] = "Exit";

    option_content[0] = "Edit name of the players";
    option_content[1] = "No. max. matches";
    option_content[2] = "Back";
    while(game_over != true)
    {
        ui.clear_screen();
        ui.title_bar("Welcome to Truco++");
        ui.text_box("The best brazilian card game ever!");
        menu_choice = ui.menu_box(3, menu_content);
        if(menu_choice == 0)
        {
            // while(match < max_matches)
            // {
                while(teams[0].get_points() < 12 && teams[1].get_points() < 12)
                {
                    round_over = false;
                    next_player = begin_play;
                    ui.clear_screen();
                    ui.title_bar("Truco++");
                    ui.text_box("Shuffling the deck...");
                    baralho.random_shuffle();
                    this_thread::sleep_for(chrono::seconds(1));
                    ui.clear_screen();
                    ui.title_bar("Truco++");
                    ui.text_box("Distributing cards...");
                    teams[0].set_card(0, baralho.get_card_top());
                    teams[0].set_card(0, baralho.get_card_top());
                    teams[0].set_card(0, baralho.get_card_top());
                    teams[1].set_card(0, baralho.get_card_top());
                    teams[1].set_card(0, baralho.get_card_top());
                    teams[1].set_card(0, baralho.get_card_top());
                    teams[0].set_card(1, baralho.get_card_top());
                    teams[0].set_card(1, baralho.get_card_top());
                    teams[0].set_card(1, baralho.get_card_top());
                    teams[1].set_card(1, baralho.get_card_top());
                    teams[1].set_card(1, baralho.get_card_top());
                    teams[1].set_card(1, baralho.get_card_top());
                    vira = baralho.get_card_top();
                    this_thread::sleep_for(chrono::seconds(1));
                    while(round_over != true)
                    {
                        if(next_player == 0) 
                        {

                        }
                    }
                    break;
                }
            //     match++
            // }
        }
        else if(menu_choice == 1)
        {
            ui.clear_screen();
            ui.title_bar("Options - Truco++");
            ui.text_box("In this menu you can change some settings or back to the main menu.");
            menu_choice = ui.menu_box(3, option_content);
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
            else if(menu_choice == 1)
            {
                ui.clear_screen();
                ui.title_bar("Options - Change the number of max. matches");
                ui.text_box("Type the number: ");
                cin >> max_matches;
                if(max_matches <= 0)
                {
                    max_matches = 1;
                }
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
