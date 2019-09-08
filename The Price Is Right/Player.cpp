#include "Player.h"

using namespace std;

MenuChoices playerChoice()
{
	auto choice{ 0 };

	cout << endl << "1. CONTINUE" << endl;
	cout << "2. SCORES" << endl;
	cout << "3. QUIT" << endl;

	cin >> choice;

	switch (choice) {
		case static_cast<int>(MenuChoices::PLAY) :
			return MenuChoices::PLAY;
			break;
		case static_cast<int>(MenuChoices::SCORES) :
			return MenuChoices::SCORES;
			break;
		case static_cast<int>(MenuChoices::QUIT) :
			return MenuChoices::QUIT;
			break;
		default :
			playerChoice();
	}

}

DifficultyChoices playerDifficulty()
{
	auto choiceDifficulty{ 1 };

	cout << endl << "1. EASY" << endl << "2. HARDER" << endl << "3. HARDEST" << endl;
	cin >> choiceDifficulty;
	switch (choiceDifficulty) {
		case static_cast<int>(DifficultyChoices::EASY):
			return DifficultyChoices::EASY;
			break;
		case static_cast<int>(DifficultyChoices::HARDER) :
			return DifficultyChoices::HARDER;
			break;
		case static_cast<int>(DifficultyChoices::HARDEST) :
			return DifficultyChoices::HARDEST;
			break;
		default:
			playerDifficulty();
	}
}