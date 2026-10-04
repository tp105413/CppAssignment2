#include "Game.h"

void Game::CreatePool() {

	// create drink pool
	for (int i = 0; i < 2;i++) {
		drinkPool.Add(Drink(DrinkType::Americano));
		drinkPool.Add(Drink(DrinkType::Espresso));
		drinkPool.Add(Drink(DrinkType::Latte));
		drinkPool.Add(Drink(DrinkType::Mocha));
	}
}

void Game::StartGame() {
	CreatePool();
	sequenceGen.Generate(drinkPool);
}