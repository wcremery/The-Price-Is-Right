#pragma once

#include <iostream>     /* cout, cin, endl */
#include <array>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "constants.h"
#include "enums.h"
#include "Player.h"

using scoreBoard = std::array<int, SCORE_NUMBER>;

void gameStatus(int pRightPrice, int pProposal, int *ptrTries);

void priceGeneration(int *ptrRightPrice);

// If it's a new high score insert it in the scoreBoard
void bestThreeGames(scoreBoard &aScores, int *pTries);

void printScores(scoreBoard &aScores);

// Sort scoreBoard from smaller to bigger
void sort(scoreBoard &aScores);