#pragma once

#include <iostream>     /* cout, cin, endl */
#include <array>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "constants.h"
#include "enums.h"
#include "Player.h"

void gameStatus(int pRightPrice, int pProposal, int *ptrTries);

void priceGeneration(int *ptrRightPrice);

void bestThreeGames(std::array<int, SCORE_NUMBER> *ptrArrayScores, int *tries);
