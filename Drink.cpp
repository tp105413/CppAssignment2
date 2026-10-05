#include "Drink.h"

Drink::Drink(DrinkType t) {
	type = t;
}

DrinkType Drink::GetType() const {
	return type;
}

char Drink::GetSymbol() const {
	switch (type) {
	case DrinkType::Americano:
		return 'A';
		break;
	case DrinkType::Espresso:
		return 'E';
		break;
	case DrinkType::Latte:
		return 'L';
		break;
	case DrinkType::Mocha:
		return 'M';
		break;
	}
	return '?';
}