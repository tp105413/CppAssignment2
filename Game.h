#pragma once

#include <vector>
#include <string>

#include "Drink.h"
#include "ObjectPool.h"
#include "SequenceGen.h"

struct GuessResult {
	int a; int b;
};

struct GuessRecord {
	std::string guess;
	GuessResult result;
};

class Game {
private:
	ObjectPool<Drink> drinkPool;
	SequenceGen sequenceGen;
	std::vector<GuessRecord> history;

	void CreatePool();

public:
	void StartGame();
	void PrintRules() const;
	std::string AskGuess() const;
	std::string GetAnswer() const;
	GuessResult CalculateResult(const std::string& guess) const;
	void PrintHistory() const;
};