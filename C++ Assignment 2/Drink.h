#pragma once

enum class DrinkType {
	Americano, Espresso, Latte, Mocha
};

class Drink {
private:
	DrinkType type;

public:
	Drink(DrinkType type);

	DrinkType GetType() const;
	char GetSymbol() const;
};