#include "FBullCowGame.h"

// notice me senpai

FBullCowGame::FBullCowGame() { Reset(); }

int FBullCowGame::GetMaxTries() const { return maxTries; }
int FBullCowGame::GetCurrentTry() const { return currentTry; }
bool FBullCowGame::IsGuessCorrect() const { return false; }


void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	int maxTries = MAX_TRIES;

	currentTry = 1;
	return;
}


void FBullCowGame::GetInput(std::string)
{
}

