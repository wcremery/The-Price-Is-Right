#include <iostream>     /* cout, cin, endl */
#include <array>
#include "Constants.h"
#include "Enums.h"
#include "Game.h"

using namespace std;

using scoreBoard = array<int, SCORE_NUMBER>;

int main()
{	
	auto rightPrice{ 0 }, proposal{ 0 }, tries{ 0 }, games{ 0 };
	auto selection{ MenuChoices::PLAY };
	auto scores = scoreBoard{0, 0, 0};
	auto startChrono = chrono::system_clock::now;

	cout << "Welcome to The Price Is Right !" << endl;

	do {		

		priceGeneration(&rightPrice);

		do {
			cout << "What is the right price ? " << endl;

			cin >> proposal;

			gameStatus(rightPrice, proposal, &tries);

		} while (proposal != rightPrice);

		cout << "Tries : " << tries << endl;

		bestThreeGames(scores, &tries);

		tries = 0;

		games++;

		selection = playerChoice();

		if (selection == MenuChoices::SCORES) {
			printScores(scores);
		}

	} while (selection != MenuChoices::QUIT);

	cout << "You have played " << games << " games !" << endl << "Thank you for playing !" << endl;

	return EXIT_SUCCESS;
}
