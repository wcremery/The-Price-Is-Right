#include "Game.h"

using namespace std;

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

void bestThreeGames(std::array<int, SCORE_NUMBER> *ptrArrayScores, int *tries)
{

	auto scoreMin{ (*ptrArrayScores)[0] }, cursor{ 0 };

	for (auto i{ 1 }; i < ptrArrayScores->size(); i++) {
		if ((*ptrArrayScores)[i] < scoreMin) {
			scoreMin = (*ptrArrayScores)[i]; 
			cursor = i;
		}
	}

	(*ptrArrayScores)[cursor] = *tries;
}

void rank(std::array<int, SCORE_NUMBER> *ptrArrayScore)
{
	auto scoreMin{0};
	for (auto i{ 0 }; i < ptrArrayScore->size - 1; i++) {
		auto currentScore{ (*ptrArrayScore)[i] };
		auto nextScore{ (*ptrArrayScore)[i+1] };
		if (nextScore < currentScore) {
			scoreMin = nextScore;
			nextScore = currentScore;
			currentScore = scoreMin;
		}
	}
}