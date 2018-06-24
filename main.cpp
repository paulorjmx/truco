#include "inc/user_interface.hpp"
#include "inc/card.hpp"
#include "inc/deck.hpp"
#include "inc/player.hpp"
#include "inc/team.hpp"
#include "inc/table.hpp"
#include <iostream>
#include <thread>
#include <random>
#include <chrono>

using namespace std;

int main(int argc, char const *argv[])
{
    UserInterface ui;
    Deck baralho;
    Table m;
    Team teams[2]; // Team[0] e o time do jogador humano
    random_device rd;
    bool game_over = false, round_over = false, trucado = false;
    int cpu_choice = 0, menu_choice = -1, player_choose = -1, max_matches = 1, begin_play = 0, next_player = 0, total_cards = 0, points = 0, rises = 0;
    int partial_t1 = 0, partial_t2 = 0; // Variaveis para guardar os resultados parciais da rodada
    string *menu_content = NULL, *option_content = NULL, *what_do = NULL;
    menu_content = new string[3];
    option_content = new string[3];
    what_do = new string[3];

    menu_content[0] = "Play Truco++";
    menu_content[1] = "Options";
    menu_content[2] = "Exit";

    option_content[0] = "Edit name of the players";
    option_content[1] = "No. max. matches";
    option_content[2] = "Back";

    what_do[0] = "Accept";
    what_do[1] = "Rises";
    what_do[2] = "Give Up!";
    while(game_over != true)
    {
        ui.clear_screen();
        ui.title_bar("Welcome to Truco++");
        ui.text_box("The best brazilian card game ever!");
        menu_choice = ui.menu_box(3, menu_content);
        if(menu_choice == 0)
        {
            // while(max_matches > 0)
            // {
                while(teams[0].get_points() < 12 && teams[1].get_points() < 12)
                {
                    trucado = false;
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
                    m.set_vira(baralho.get_card_top());
                    this_thread::sleep_for(chrono::seconds(1));
                    points = 1;
                    while(round_over != true && partial_t1 < 2 && partial_t2 < 2)
                    {
                        if(m.get_cards_on() < 4)
                        {
                            if((next_player % 4) == 0)
                            {
                                ui.clear_screen();
                                ui.title_bar("Truco++");
                                ui.text_box("Cards in the table:");
                                // ui.text_box(m.display_table());
                                ui.text_box("Choose one card below");
                                ui.menu_choose_card(teams[0].display_player_card(0));
                                if(trucado != true)
                                {
                                    ui.text_box("[4] Truco!");
                                }
                                ui.text_box("Your choose: ");
                                cin >> player_choose;
                                if(player_choose >= 0 && player_choose <= 2)
                                {
                                    m.set_card(teams[0].get_card(0, player_choose), 0);
                                    next_player++;
                                }
                                else if(player_choose == 4 && trucado != true)
                                {
                                    trucado = true;
                                    rises++;
                                    while((rises * 3) < 12) // Enquanto aumentar os pontos
                                    {
                                        cpu_choice = rd() % 3;
                                        if(cpu_choice == 1)
                                        {
                                            ui.clear_screen();
                                            ui.title_bar("Truco++");
                                            ui.text_box("The oppponent accpeted the truco!");
                                            this_thread::sleep_for(chrono::seconds(2));
                                            break;
                                        }
                                        else if(cpu_choice == 2)
                                        {
                                            rises++;
                                            ui.clear_screen();
                                            ui.title_bar("Truco++");
                                            ui.text_box("The opponent rises truco. What you do?");
                                            player_choose = ui.menu_box(3, what_do);
                                            if(player_choose == 1)
                                            {
                                                rises++;
                                                break;
                                            }
                                            else if(player_choose == 2)
                                            {
                                                rises++;
                                            }
                                            else
                                            {
                                                rises--;
                                                round_over = true;
                                                break;
                                            }
                                        }
                                        else
                                        {
                                            rises--;
                                            round_over = true;
                                            break;
                                        }
                                    }
                                }
                                else
                                {
                                    ui.clear_screen();
                                    ui.title_bar("Truco++");
                                    ui.text_box("Choose an valid option!");
                                    next_player = 0;
                                    this_thread::sleep_for(chrono::seconds(2));
                                }

                            }
                            else if((next_player % 4) == 1)
                            {
                                if(teams[1].remaining_cards(0) > 0)
                                {
                                    cpu_choice = rd() % teams[1].remaining_cards(0);
                                    if(cpu_choice < 3)
                                    {
                                        m.set_card(teams[1].get_card(0, cpu_choice), 1);
                                        next_player++;
                                    }
                                }
                                else
                                {
                                    m.set_card(teams[1].get_card(0, 0), 2);
                                }
                            }
                            else if((next_player % 4) == 2) // Vez do parceiro de player
                            {
                                if(teams[0].remaining_cards(1) > 0)
                                {
                                    cpu_choice = rd() % teams[0].remaining_cards(1);
                                    if(cpu_choice < 3)
                                    {
                                        m.set_card(teams[0].get_card(1, cpu_choice), 2);
                                        next_player++;
                                    }
                                }
                                else
                                {
                                    m.set_card(teams[0].get_card(1, 0), 2);
                                }
                            }
                            else
                            {
                                if(teams[1].remaining_cards(1) > 0)
                                {
                                    cpu_choice = rd() % teams[1].remaining_cards(1);
                                    if(cpu_choice < 3)
                                    {
                                        m.set_card(teams[1].get_card(1, cpu_choice), 3);
                                        next_player++;
                                    }
                                }
                                else
                                {
                                    m.set_card(teams[1].get_card(1, 0), 2);
                                }
                            }
                        }
                        else // Calcula o resultado da rodada
                        {
                            if(trucado != false)
                            {
                                points = (rises * 3);
                            }
                            ui.text_box(m.display_table());
                            next_player = m.calculate_round_winner();
                            if(next_player != -1)
                            {
                                if((next_player % 2) == 0)
                                {
                                    teams[0].set_points(points);
                                    partial_t1++;
                                    cout << "You TEAM WIN TH TURN";
                                }
                                else
                                {
                                    teams[1].set_points(points);
                                    partial_t2++;
                                    cout << "AWAY TEAM WIN TH TURN";
                                }
                            }
                            else
                            {
                                cout << "DRAW" << endl;
                            }
                            cin >> partial_t1;
                        }
                    }
                    break;
                }
                baralho.create();
                baralho.random_shuffle();
                begin_play++;
                max_matches--;
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
            delete[] what_do;
            game_over = true;
        }
    }
    return 0;
}
