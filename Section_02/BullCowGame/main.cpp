#include <iostream>
#include <string>
#include "FBullCowGame.h"


void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

/* Tadeo Menichelli
	Bull and Cow game, guess the word
*/

// instantiate game
FBullCowGame BCGame;

/// Beginning of Bulls and Cows
int main() 
{
	PlayGame();

	std::cout << std::endl;

	return 0;
}


void PlayGame()
{
	BCGame.Reset();
	// start game from start
	int maxTries = BCGame.GetMaxTries();
	PrintIntro();


	// loop for the number of turns the player has
	for (int count = 1; count <= maxTries; count++) {
		std::string outGuess = GetGuess();

		// print guess back
		std::cout << "Your guess was: " << outGuess << std::endl;
	}

	AskToPlayAgain();
}

/// Intro to game
void PrintIntro()
{
	constexpr int WORLD_LENGTH = 9;

	// introduce the game
	std::cout << "Welcome to Balls and Cows" << std::endl;
	std:: cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n" << std::endl;
	return;
}

///
std::string GetGuess() {
	// get a guess from the player
	std::string guess = "";
	std::cout << std::endl<< "Guess #" << BCGame.GetCurrentTry() <<": ";
	std::getline(std::cin, guess);

	// return player's guess
	return guess;
}

bool AskToPlayAgain()
{
	bool correctInput = true;
	std::cout << "Do you want to play again? ";
	std::string response = "";
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
