#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetAndReturnGuess();


int main() 
{
	PrintIntro();

	PlayGame();

	cout << endl;

	return 0;
}

void PlayGame()
{
	constexpr int NUMBER_OF_TURNS = 5;

	// loop for the number of turns the player has
	for (int count = 1; count <= NUMBER_OF_TURNS; count++) {
		string outGuess = GetAndReturnGuess();

		cout << "Your guess was: " << outGuess << endl;
	}
}

void PrintIntro()
{
	constexpr int WORLD_LENGTH = 9;

	// introduce the game
	cout << "Welcome to Balls and Cows" << endl;
	cout << "Can you guess the " << WORLD_LENGTH;
	cout << " letter isogram I'm thinking of?\n" << endl;
	return;
}

string GetGuess() {
	// get a guess from the player
	string guess = "";

	cout << "Enter your guess: ";
	getline(cin, guess);

	// return player's guess
	return guess;
}