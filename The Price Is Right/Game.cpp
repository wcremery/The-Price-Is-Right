#include "Game.h"

using namespace std;

void gameStatus(int pRightPrice, int pProposal, int *ptrTries)
{
	if (pProposal >= 0) 
	{

		if (pProposal > pRightPrice) 
		{
			cout << "It's less !" << endl;
		}
		else if (pProposal < pRightPrice) {
			cout << "It's more !" << endl;
		}

		(*ptrTries)++;
	}
	else 
	{
		cout << "Come on ! The right price can not be negative !" << endl;
	}
}

void priceGeneration(int *ptrRightPrice)
{
	DifficultyChoices difficulty = playerDifficulty();

	random_device randomGenerator;
	auto generator = mt19937{randomGenerator()};
	uniform_int_distribution<int> distribution;

	switch (difficulty) {
	case DifficultyChoices::EASY:
		distribution = uniform_int_distribution<int>(PRICE_MIN, EASY_PRICE_MAX);
		break;
	case DifficultyChoices::HARDER:
		distribution = uniform_int_distribution<int>(PRICE_MIN, HARDER_PRICE_MAX);
		break;
	case DifficultyChoices::HARDEST:
		distribution = uniform_int_distribution<int>(PRICE_MIN, HARDEST_PRICE_MAX);
		break;
	default:
		EXIT_FAILURE;
	}

	*ptrRightPrice = distribution(generator);
}

void bestThreeGames(scoreBoard &aScores, int *tries)
{
	auto newHighScore{ false };
	
	sort(aScores);

	for (auto i{ 0 }; !newHighScore && i < SCORE_NUMBER; i++) 
	{
		if (aScores[i] == 0 || aScores[i] > *tries) 
		{
			for (auto j{ SCORE_NUMBER - 1}; j > i; j--) 
			{
				aScores[j] = aScores[j--];
			}
			aScores[i] = *tries;
			newHighScore = true;
		}
	}
}

void sort(scoreBoard &aScores)
{
	auto scoreMin{0};
	for (auto i{ 0 }; i < SCORE_NUMBER - 1; i++) 
	{
		auto currentScore{ aScores[i] };
		auto nextScore{ aScores[i++] };

		if (nextScore < currentScore) 
		{
			scoreMin = nextScore;
			nextScore = currentScore;
			currentScore = scoreMin;
		}
	}
}

void printScores(scoreBoard &aScores)
{
	for (auto i{ 0 }; i < SCORE_NUMBER; i++) 
	{
		if (aScores[i] == 0) 
		{
			cout << "-" << endl;
		}
		else 
		{
			cout << aScores[i] << endl;
		}
	}
}