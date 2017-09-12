#include <iostream>
#include <string>

using namespace std;

void PrintIntro();

int main() 
{
	PrintIntro();

	// get a guess from the player
	string guess = "";
	cout << "Enter your guess: ";
	getline(cin, guess);

	// repeat the guess back to them
	cout << "Your guess was " << guess << endl;

	return 0;
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

