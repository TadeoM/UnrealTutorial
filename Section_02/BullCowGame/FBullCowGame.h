#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// two integers, initialised to zero
struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};


class FBullCowGame 
{
public:
	FBullCowGame();									// constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGuessCorrect() const;	
	bool IsGameWon() const;

	void Reset();									// TODO make a more rich return value
	EGuessStatus CheckInput(FString) const;

	FBullCowCount SubmitValidGuess(FString);				// counts bulls & cows, and increases try # assuming valid guess

	
private:
	int32 currentTry = 1;		 	// constructor for initialization
	int32 maxTries = 5;			// ^^
	FString hiddenWord;
	bool bGameWon;

	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};