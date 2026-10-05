#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

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

	history.clear();
	int attempts = 0;
	GuessResult r = { 0, 0 };
	
	// check answer for debugging
	// std::cout << "DEBUG answer: " << GetAnswer() << "\n";

	while (r.a != 4) {
		system("cls");
		PrintRules();
		PrintHistory();

		std::string guess = AskGuess();
		r = CalculateResult(guess);
		attempts++;

		history.push_back({ guess, r });
	}

	std::cout << "\nCongutulations! You got 4A4B!\n";
	std::cout << "It took you " << attempts << " guesses.\n\n";
	system("pause");
}

void Game::PrintRules() const {
	std::cout << std::string(60, '=');
	std::cout << "\nWelcome to 1A2B Coffee Version\n\n";
	std::cout << "A-Americano\tE-Espresso\n";
	std::cout << "L-Latte\t\tM-Mocha\n\n";
	std::cout << "You have to guess the sequence of 4 drinks.\n";
	std::cout << "A: The drink is correct and in the correct position.\n";
	std::cout << "B: Correct drinks in total amount, not included position.\n";
	std::cout << "Each type of drink can appear a maximum of 2 times.\n";
	std::cout << "\nUse fewest attempts to get all drinks, GOOD LUCK!\n";
	std::cout << std::string(60, '=');
	std::cout << "\n";
}

std::string Game::AskGuess() const {
	std::string guess;

	for (int i = 0; i < 4; i++) {
		
		while (true) {
			std::cout << "Drink " << (i + 1) << "/4 (A/E/L/M): ";
			std::string input;
			std::cin >> input;
			std::cin.ignore(1000, '\n');

			// check only 1 character can be entered
			if (input.size() != 1) {
				std::cout << "Enter only 1 letter.\n";
				continue;
			}

			// convert lowercase to uppercase
			char c = std::toupper(input[0]);

			// Check only correct alphabet
			if (std::string("AELM").find(c) == std::string::npos) {
				std::cout << "Invalid! Use A, E, L or M.\n";
				continue;
			}

			// Each drink maximum appear twice
			if (std::count(guess.begin(), guess.end(), c) >= 2) {
				std::cout << "Each drink appears at most twice. Pick another.\n";
				continue;
			}

			guess += c;
			break;
		}
	}
	return guess;
}

std::string Game::GetAnswer() const {
	std::string answer;
	
	for (const Drink& d : sequenceGen.GetSequence()) {
		answer += d.GetSymbol();
	}
	return answer;
}

GuessResult Game::CalculateResult(const std::string& guess) const {
	std::string answer = GetAnswer();
	GuessResult result = { 0, 0 };

	// check a (correct drink & correct position)
	for (size_t i = 0; i < answer.size(); i++) {
		if (guess[i] == answer[i]) {
			result.a++;
		}
	}

	// check b (correct drink in total amount)
	std::string types = "AELM";
	for (char t : types) {
		int inAnswer = std::count(answer.begin(), answer.end(), t);
		int inGuess = std::count(guess.begin(), guess.end(), t);
		result.b += std::min(inAnswer, inGuess);
	}
	return result;
}

void Game::PrintHistory() const {
	std::cout << "\n--- Your guesses ---\n";

	for (size_t i = 0; i < history.size(); i++) {
		std::cout << (i + 1) << ". " << history[i].guess << " -> " << history[i].result.a << "A" << history[i].result.b << "B\n";
	}

	std::cout << "--------------------\n\n";
}