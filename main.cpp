#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Game.h"

using namespace std;

int main() {
	// seed random once
	srand(static_cast<unsigned>(time(nullptr)));

	int choice;

	do {
		system("cls");
		cout << "1. Start Game\n";
		cout << "2. Quit\n\n";
		cout << "Choose: ";
		cin >> choice;
		cin.ignore(1000, '\n');

		if (choice == 1) {
			Game game;
			game.StartGame();
		}
	} while (choice != 2);

	exit(0);

	return 0;
}