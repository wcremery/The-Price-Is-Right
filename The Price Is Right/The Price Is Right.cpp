#include <iostream>     /* cout, cin, endl */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

enum class MenuChoices {
	PLAY = 0,
	QUIT = 1
};

MenuChoices playerChoice()
{
	auto choice{ 0 };

	cin >> choice;

	if (choice == static_cast<int>(MenuChoices::PLAY)) {
		return MenuChoices::PLAY;
	}
	else {
		return MenuChoices::QUIT;
	}

}

enum class DifficultyChoices
{
	EASY = 1,
	HARDER = 2,
	HARDEST = 3
};

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

void gameStatus(int rightPrice, int proposal, int tries)
{
	if (proposal >= 0) {

		if (proposal == rightPrice) {
			cout << "You win !" << endl;
		}
		else if (proposal < rightPrice) {
			cout << "It's more !" << endl;
		}
		else {
			cout << "It's less !" << endl;
		}

		tries++;
	}
	else {
		cout << "Come on ! The right price can not be negative !" << endl;
	}
}

int main()
{
	const auto PRICE_MAX{ 1000 };
	const auto PRICE_MIN{ 1 };

	auto rightPrice{ 0 }, proposal{ 0 }, tries{ 0 }, games{ 0 };

	auto selection{ MenuChoices::PLAY };


	do {

		playerDifficulty();

		srand(time_t(NULL));

		rightPrice = rand() % PRICE_MAX + PRICE_MIN;

		do {
			cout << "What is the right price ? " << endl;

			cin >> proposal;

			gameStatus(rightPrice, proposal, tries);

		} while (proposal != rightPrice);

		cout << "Tries : " << tries << endl;

		games++;

		selection = playerChoice();

	} while (selection == MenuChoices::PLAY);

	cout << "You have played " << games << " games !" << endl << "Thank you for playing !" << endl;

	return EXIT_SUCCESS;
}
