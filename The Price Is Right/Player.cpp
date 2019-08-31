#include "Player.h"

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

}

DifficultyChoices playerDifficulty()
{
	auto choiceDifficulty{ 1 };

	cout << endl << "EASY (1)" << endl << "HARDER (2)" << endl << "HARDEST (3)" << endl;
	cin >> choiceDifficulty;
	switch (choiceDifficulty) {
	case 1:
		return DifficultyChoices::EASY;
		break;
	case 2:
		return DifficultyChoices::HARDER;
		break;
	case 3:
		return DifficultyChoices::HARDEST;
		break;
	default:
		playerDifficulty();
	}
}