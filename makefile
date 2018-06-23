all:
	@g++ main.cpp player.cpp deck.cpp card.cpp user_interface.cpp team.cpp table.cpp -I. -o main
