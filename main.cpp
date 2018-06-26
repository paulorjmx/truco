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
    Card sc1, sc2; // Cartas mais fortes dos times 1 e 2, respectivamente, para a condicao de empate
    random_device rd;
    bool game_over = false, trucado = false, t1_first_blood = false, t1_give = false, t2_give = false, draw = false;
    int cpu_choice = 0, menu_choice = -1, player_choose = -1, max_matches = 1, begin_play = 0, next_player = 0, total_cards = 0, points = 0, rises = 0;
    int round_number = 0, partial_t1 = 0, partial_t2 = 0, it = 0; // Variaveis para guardar os resultados parciais da rodada
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
        ui.text_box("An another card game!");
        menu_choice = ui.menu_box(3, menu_content);
        if(menu_choice == 0)
        {
            // while(max_matches > 0)
            // {
                begin_play = 0;
                while(teams[0].get_points() < 12 && teams[1].get_points() < 12)
                {
                    trucado = false;
                    t1_first_blood = false;
                    t1_give = false;
                    t2_give = false;
                    draw = false;
                    round_number = 0;
                    rises = 0;
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
                    m.clear();
                    m.set_vira(baralho.get_card_top());
                    this_thread::sleep_for(chrono::seconds(1));
                    points = 1;
                    partial_t1 = 0;
                    partial_t2 = 0;
                    while(round_number < 3 && partial_t1 != 2 && partial_t2 != 2 && t1_give != true && t2_give != true)
                    {
                        if(m.get_cards_on() < 4)
                        {
                            if((next_player % 4) == 0)
                            {
                                ui.clear_screen();
                                ui.title_bar("Truco++");
                                ui.text_box(m.display_vira());
                                ui.text_box("Cards in the table:");
                                ui.text_box(m.display_cards());
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
                                    round_number--;
                                    it = 0;
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
                                            if((rises * 3) < 12)
                                            {
                                                ui.clear_screen();
                                                ui.title_bar("Truco++");
                                                ui.text_box("The opponent rises truco. What you do?");
                                                player_choose = ui.menu_box(3, what_do);
                                                if(player_choose == 0)
                                                {
                                                    break;
                                                }
                                                else if(player_choose == 1)
                                                {
                                                    rises++;
                                                }
                                                else
                                                {
                                                    rises--;
                                                    round_number = 3;
                                                    t1_give = true;
                                                    break;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            rises--;
                                            round_number = 3;
                                            t2_give = true;
                                            if(it == 0)
                                            {
                                                trucado = false;
                                            }
                                            break;
                                        }
                                        it++;
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
                            ui.clear_screen();
                            ui.title_bar("Truco++");
                            ui.text_box(m.display_vira());
                            ui.text_box("Results:");
                            ui.text_box(m.display_cards());
                            this_thread::sleep_for(chrono::seconds(3));
                            next_player = m.calculate_round_winner();
                            if(next_player != -1)
                            {
                                if((next_player % 2) == 0)
                                {
                                    if(round_number == 0) t1_first_blood = true;
                                    partial_t1++;
                                }
                                else
                                {
                                    partial_t2++;
                                }
                            }
                            else
                            {
                                ui.clear_screen();
                                ui.title_bar("Truco++ - Draw");
                                ui.text_box("This round draw. Let choose the strongest card of each player...");
                                if(round_number == 0)
                                {
                                    partial_t1++;
                                    partial_t2++;
                                    sc1 = teams[0].get_strongest_card(m.get_vira());
                                    sc2 = teams[1].get_strongest_card(m.get_vira());
                                    this_thread::sleep_for(chrono::seconds(6));
                                    it = m.decide_draw(sc1, sc2);
                                    if(it != -1) // se não empatou novamente
                                    {
                                        if(it != 2) // Time 1 ganhou
                                        {
                                            partial_t1++;
                                        }
                                        else // Time 2 ganhou
                                        {
                                            partial_t2++;
                                        }
                                    }
                                    else
                                    {
                                        ui.clear_screen();
                                        ui.title_bar("Truco++ - Draw");
                                        ui.text_box("This round draw again. Let choose the strongest card of each player...");
                                        sc1 = teams[0].get_strongest_card(m.get_vira());
                                        sc2 = teams[1].get_strongest_card(m.get_vira());
                                        this_thread::sleep_for(chrono::seconds(6));
                                        it = m.decide_draw(sc1, sc2);
                                        if(it != -1) // se não empatou novamente
                                        {
                                            if(it != 2) // Time 1 ganhou
                                            {
                                                partial_t1++;
                                            }
                                            else // Time 2 ganhou
                                            {
                                                partial_t2++;
                                            }
                                        }
                                        else
                                        {
                                            ui.clear_screen();
                                            ui.title_bar("Truco++ - Result");
                                            ui.text_box("This round draw again. Neither teams get points.");
                                            this_thread::sleep_for(chrono::seconds(4));
                                            draw = true;
                                        }
                                    }
                                    round_number = 3;
                                }
                                else if(round_number == 1)
                                {
                                    if(t1_first_blood != true)
                                    {
                                        partial_t2++;
                                    }
                                    else
                                    {
                                        partial_t1++;
                                    }
                                    round_number = 3;
                                }
                                if(round_number == 2 && (partial_t1 == partial_t2))
                                {
                                    if(t1_first_blood != true)
                                    {
                                        partial_t2++;
                                    }
                                    else
                                    {
                                        partial_t1++;
                                    }
                                }
                            }
                            round_number++;
                        }
                    }
                    if(draw != true)
                    {
                        if(trucado != false)
                        {
                            points = (rises * 3);
                        }
                        if(partial_t1 > partial_t2 || t2_give != false)
                        {
                            teams[0].set_points(teams[0].get_points() + points);
                        }
                        else
                        {
                            teams[1].set_points(teams[1].get_points() + points);
                        }
                    }
                    ui.clear_screen();
                    ui.title_bar("Truco++ - Partial Score");
                    ui.text_box("Your team: " +to_string(teams[0].get_points())+ " points");
                    ui.text_box("Away team: " +to_string(teams[1].get_points())+ " points");
                    this_thread::sleep_for(chrono::seconds(4));
                    begin_play++;
                    baralho.create();
                } // Quando um dos dois times obtiverem 12 pontos
                max_matches--;
                teams[0].set_points(0);
                teams[1].set_points(0);
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
