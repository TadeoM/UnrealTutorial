/*
Tadeo Menichelli

Console executable that makes use of the BullCow class.
Acts as view in MVC pattern
Responsible for all user interaction
For game lobic see the FBullCowGame class
*/
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int32;

void PrintIntro();
void PrintGameSummary();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

/* Tadeo Menichelli
	Bull and Cow game, guess the word
*/

// instantiate game
FBullCowGame BCGame;

/// Beginning of Bulls and Cows
int32 main() 
{
	PlayGame();

	std::cout << std::endl;

	return 0;
}


void PlayGame()
{
	BCGame.Reset();
	// start game from start
	int32 maxTries = BCGame.GetMaxTries();
	PrintIntro();


	std::cout << "You can guess " << BCGame.GetMaxTries() << " times this game." << std::endl;

	// loop asking for guesses while the game is NOT won
	// and there are astill guess remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= maxTries)
	{
		FText outGuess = GetValidGuess();

		// submit valid guess to the game
		FBullCowCount bullCowCount = BCGame.SubmitValidGuess(outGuess);

		std::cout << "Bulls = " << bullCowCount.Bulls;
		std::cout << ". Cow = " << bullCowCount.Cows << "\n\n";
	}

	AskToPlayAgain();

	PrintGameSummary();

	// TODO summarise game
	return;
}

// Intro to game
void PrintIntro()
{
	// introduce the game
	std::cout << "Welcome to Balls and Cows" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n" << std::endl;
	return;
}

// loop continually until the user gives a valid guess
FText GetValidGuess()
{
	EGuessStatus status = EGuessStatus::Invalid_Status;
	FText guess = "";
	do
	{
		// get a guess from the player
		int32 currentTry = BCGame.GetCurrentTry();
		std::cout << std::endl << "Guess #" << currentTry << ": ";
		std::getline(std::cin, guess);

		status = BCGame.CheckInput(guess);

		switch (status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please eneter a valid isogram (word with no repeating letters)";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter an isogram with all lowercase!";
			break;
		default:
			return guess;
		}
		std::cout << "\n";
	} while (status != EGuessStatus::OK);

	return guess;
}

bool AskToPlayAgain()
{
	bool correctInput = true;
	std::cout << "Do you want to play again with the same word? (y/n) ";
	FText response = "";
	std::getline(std::cin, response);

	do {
		// if player says yes, then clear screen and play again
		if (response[0] == 'y' || response[0] == 'Y') {
			system("cls");
			PlayGame();
			return true;
		}
		// if play says no, end the game
		else if (response[0] == 'n' || response[0] == 'N') {
			return false;
		}
		// make the do/while loop repeat until player inputs yes or no
		else {
			std::cout << "Please type yes/no: ";
			correctInput = false;
			std::getline(std::cin, response);
		}
	} while (correctInput == false);

	return false;
}

void PrintGameSummary() 
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Well done - You won!\n";
	}
	else 
	{
		std::cout << "Sorry, you lost!\n";
	}
}
