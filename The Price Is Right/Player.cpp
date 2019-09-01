#include "Player.h"

using namespace std;

MenuChoices playerChoice()
{
	auto choice{ 0 };

	cout << endl << "press 0 to continue" << endl;
	cout << "press ANYTHING ELSE to quit" << endl;

	cin >> choice;

	if (choice == static_cast<int>(MenuChoices::PLAY)) {
		return MenuChoices::PLAY;
	}
	else {
		return MenuChoices::QUIT;
	}
	switch (choice) {
	case static_cast<int>(MenuChoices::PLAY) :
		return MenuChoices::PLAY;
		break;
	case static_cast<int>(MenuChoices::SCORES) :
		return MenuChoices::SCORES;
		break;
	default:
		return MenuChoices::QUIT;
		break;
	}

}

DifficultyChoices playerDifficulty()
{
	auto choiceDifficulty{ 1 };

	cout << endl << "EASY (1)" << endl << "HARDER (2)" << endl << "HARDEST (3)" << endl;
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
		break;
	}
}