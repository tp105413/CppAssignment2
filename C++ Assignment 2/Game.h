#pragma once

#include <vector>

#include "Drink.h"
#include "ObjectPool.h"
#include "SequenceGen.h"

class Game {
private:
	ObjectPool<Drink> drinkPool;
	SequenceGen sequenceGen;

	void CreatePool();

public:
	void StartGame();
};