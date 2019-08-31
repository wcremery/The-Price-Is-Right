#include "Game.h"

void gameStatus(int pRightPrice, int pProposal, int* ptrTries)
{
	if (pProposal >= 0) {

		if (pProposal == pRightPrice) {
			cout << "You win !" << endl;
		}
		else if (pProposal < pRightPrice) {
			cout << "It's more !" << endl;
		}
		else {
			cout << "It's less !" << endl;
		}

		(*ptrTries)++;
	}
	else {
		cout << "Come on ! The right price can not be negative !" << endl;
	}
}

void priceGeneration(int* ptrRightPrice)
{
	DifficultyChoices difficulty;

	srand(time(NULL));

	difficulty = playerDifficulty();

	switch (difficulty) {
	case DifficultyChoices::EASY:
		*ptrRightPrice = rand() % EASY_PRICE_MAX + PRICE_MIN;
		break;
	case DifficultyChoices::HARDER:
		*ptrRightPrice = rand() % HARDER_PRICE_MAX + PRICE_MIN;
		break;
	case DifficultyChoices::HARDEST:
		*ptrRightPrice = rand() % HARDEST_PRICE_MAX + PRICE_MIN;
		break;
	default:
		*ptrRightPrice = rand() % EASY_PRICE_MAX + PRICE_MIN;
	}
}