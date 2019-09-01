#include <iostream>     /* cout, cin, endl */
#include <array>
#include "Constants.h"
#include "Enums.h"
#include "Game.h"

using namespace std;

int main()
{	
	auto rightPrice{ 0 }, proposal{ 0 }, tries{ 0 }, games{ 0 };
	auto selection{ MenuChoices::PLAY };
	auto scores = array<int, SCORE_NUMBER>{0, 0, 0};

	cout << "Welcome to The Price Is Right !" << endl;

	do {		

		priceGeneration(&rightPrice);

		do {
			cout << "What is the right price ? " << endl;

			cin >> proposal;

			gameStatus(rightPrice, proposal, &tries);

		} while (proposal != rightPrice);

		cout << "Tries : " << tries << endl;	

		games++;

		selection = playerChoice();

		if (selection == MenuChoices::SCORES) {
			bestThreeGames(&scores, &tries);
		}

	} while (selection == MenuChoices::PLAY);

	cout << "You have played " << games << " games !" << endl << "Thank you for playing !" << endl;

	return EXIT_SUCCESS;
}
