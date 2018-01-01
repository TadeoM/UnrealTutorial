#include "FBullCowGame.h"
#include <map>
#define TMap std::map

// notice me senpai

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return maxTries; }
int32 FBullCowGame::GetCurrentTry() const { return currentTry; }
int32 FBullCowGame::GetHiddenWordLength() const{	return hiddenWord.length(); }
bool FBullCowGame::IsGuessCorrect() const { return false; }
bool FBullCowGame::IsGameWon() const { return bGameWon; }

bool FBullCowGame::IsIsogram(FString word) const
{
	// treat 0 and 1 leter words as isograms
	if (word.length() <= 1) { return true; }

	TMap<char, bool> letterSeen;	// setup our map
	for (auto letter : word)		// for all letters of the word
	{
		letter = tolower(letter);		// handle mixed case
		if (letterSeen[letter]) { return false; }	// if the letter is in the map return false
		else 
		{
			letterSeen[letter] = true;		// add the letter to the map as seens
		}
	}


	return true;		// if it gets here, it would be in cases where /0 is entered
}

bool FBullCowGame::IsLowerCase(FString word) const
{
	for (auto letter : word)
	{
		if(!islower(letter)) { return false; }
	}

	return true;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";
	
	maxTries = MAX_TRIES;
	hiddenWord = HIDDEN_WORD;
	currentTry = 1;
	bGameWon = false;
	return;
}


EGuessStatus FBullCowGame::CheckInput(FString guess) const
{
	if (!IsIsogram(guess))		// if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;		// TODO write function
	}
	else if (!IsLowerCase(guess))			// if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;		// TODO write function
	}
	else if (guess.length() != GetHiddenWordLength())			// if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;		
	}	
}


/// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString guess)
{
	currentTry++;
	FBullCowCount bullCowCount;
	int32 wordLength = hiddenWord.length();		// assuming same length as guess

	// loop through all letters in the hidden word
	int32 hiddenWordLength = hiddenWord.length();
	for (int32 hwChar = 0; hwChar < hiddenWordLength; hwChar++) 
	{
		// compare letters against the guess
		for (int32 gChar = 0; gChar < hiddenWordLength; gChar++)
		{
			// if they match then
			
			if (guess.length() == hiddenWordLength)
			{
				if (guess[gChar] == hiddenWord[hwChar])		// if they're in the same place
				{
					if (hwChar == gChar)
					{
						bullCowCount.Bulls++;	// increments bulls
					}
					else
					{
						bullCowCount.Cows++;		// must be a cow
					}
				}
			}
		}
	}

	if (bullCowCount.Bulls == wordLength)
	{
		bGameWon = true;
	}
	else
	{
		bGameWon = false;
	}
		
	return bullCowCount;
}



