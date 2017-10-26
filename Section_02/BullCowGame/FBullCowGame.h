#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame();									// constructor
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGuessCorrect() const;	

	void Reset();									// TODO make a more rich return value
	void GetInput(std::string);						// TODO make a more rich return value


private:
	int currentTry;			// constructor for initialization
	int maxTries;			// ^^
};