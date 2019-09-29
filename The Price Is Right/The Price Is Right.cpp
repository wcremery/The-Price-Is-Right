#include <iostream>     /* cout, cin, endl */
#include <array>
#include <chrono>
#include "Constants.h"
#include "Enums.h"
#include "Game.h"

using namespace std;

using durations = chrono::duration<double, ratio<1>>;

const auto GAME_DURATION{ durations{10s} };

int main()
{	
	auto rightPrice{ 0 }, proposal{ 0 }, tries{ 0 }, games{ 0 };
	auto selection{ MenuChoices::PLAY };
	auto scores = scoreBoard{0, 0, 0};

	cout << "Welcome to The Price Is Right !" << endl;

	do {		

		priceGeneration(&rightPrice);
		auto startChrono = chrono::system_clock::now();

		do {
			cout << "What is the right price ? " << endl;
			cin >> proposal;
			gameStatus(rightPrice, proposal, &tries);

		} while (proposal != rightPrice);

		auto finishChrono = chrono::system_clock::now();

		auto timeElapsed = chrono::duration_cast<durations>(finishChrono - startChrono);

		system("CLS"); // clear console

		if (timeElapsed < GAME_DURATION) {
			cout << "You win !" << endl;
			cout << "Tries : " << tries << endl;
			bestThreeGames(scores, &tries);
		}
		else {
			cout << "You lose !" << endl;
			cout << "Time out... You only have " << GAME_DURATION.count() << " seconds to found out The Right Price." << endl << "Time passed : " << timeElapsed.count();
		}
				
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
