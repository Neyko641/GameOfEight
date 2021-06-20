#include <iostream>
#include <cmath>
#include <cctype>
#include <stdlib.h>
#include <ctime>
/*
The Game of Eight

The game of 8 is played by 2 players.
The game starts with the initial number 8
(from here on refered to as the initial number).
The first player will choose a number from 1 to 3
(from here on refered to as the chosen number).
If the player inputs something outside of the 1 to 3 range
it should be an error and the player must choose again.
The initial number is subtracted by the chosen number.
Then the next player's turn happens.
The next player cannot choose the number that the last player chose.
If the initial number goes to 0 on your turn, then you win.
Otherwise if the number goes below 0, your opponent wins.
The player should always see what choices are available to him when prompted to enter his choice.
After the game is over, the user should be prompted whether they want to play again.
 */

void PlayGame();
bool WantToPlayAgain();
int PlayerInput();
bool IsGameOver();
void DisplayResult(int number);
const int IGNORE_CHARS = 256;
int PreviousInput = 0;
int Player = 1;
int result;
int main() {

	do {

		PlayGame();

	} while (WantToPlayAgain());

}

int PlayerInput() {
	do {
		int Input;
		std::cin >> Input;
		if (Input > 3 || Input < 1 || std::cin.fail() || Input == PreviousInput) {
			std::cin.clear();
			std::cin.ignore(IGNORE_CHARS, '\n');
			Input = 0;
		}
		if (Input <= 3 || Input >= 1) {
			PreviousInput = Input;
		}
		return Input;
	} while (!IsGameOver());
}
void PlayGame() {
	std::cout << "Welcome to the Game of Eight, Player " << Player << " Please Enter a number between 1 and 3" << std::endl;
	const int initialNumber = 8;
	result = initialNumber;
	do {
		int chosenNumber = PlayerInput();
		DisplayResult(chosenNumber);
		result -= chosenNumber;
		if (result <= 0) {
			std::cout << "Player " << Player << " wins!" << std::endl;
		}
		if (Player == 1 && chosenNumber <= 3 || chosenNumber <= 1) {
			Player++;
		}
		else if (Player == 2 && chosenNumber <= 3 || chosenNumber <= 1) {
			Player--;
		}
	} while (!IsGameOver());

}

bool WantToPlayAgain() {
	std::cout << "Do you want to play again? (y/n): " << std::endl;
	do {
		char input;
		std::cin >> input;
		if (tolower(input) == 'y') {
			PreviousInput = 0;
			Player = 1;
			return true;
		}
		else if (tolower(input) == 'n') {
			return false;
		}
		else {
			std::cin.clear();
			std::cin.ignore(IGNORE_CHARS, '\n');
			WantToPlayAgain();
		}

	} while (IsGameOver);
}
bool IsGameOver() {
	return result == 0;
}
void DisplayResult(int number) {
	if (number > 3 || number < 1) {
		std::cout << "Invalid Input or the current number is equal to the previous number, please try again. " << std::endl;
	}
	else {
		std::cout << "Player " << Player
			<< " You input " << number
			<< " the number " << PreviousInput
			<< " can't be input by the next player"
			<< std::endl;
	}
}
