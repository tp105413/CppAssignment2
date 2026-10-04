#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Game.h"

using namespace std;

int main() {
	// seed random once
	srand(static_cast<unsigned>(time(nullptr)));

	Game game;
	game.StartGame();

	return 0;
}