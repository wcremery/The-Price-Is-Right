#pragma once

#include <iostream>     /* cout, cin, endl */
#include <array>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "constants.h"
#include "enums.h"
#include "Player.h"

using duration = std::chrono::system_clock;

void gameStatus(int pRightPrice, int pProposal, int *ptrTries, duration *ptrChrono);

void priceGeneration(int *ptrRightPrice);

void bestThreeGames(std::array<int, SCORE_NUMBER> &aScores, int *pTries);

void printScores(std::array<int, SCORE_NUMBER> scores);

void sort(std::array<int, SCORE_NUMBER> &aScores);