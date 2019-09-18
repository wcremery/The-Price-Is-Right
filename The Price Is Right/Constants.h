#pragma once
#include<chrono>

const auto PRICE_MIN{ 1 };
const auto EASY_PRICE_MAX{ 100 };
const auto HARDER_PRICE_MAX{ 1'000 };
const auto HARDEST_PRICE_MAX{ 10'000 };
const auto SCORE_NUMBER{ 3 };
const auto GAME_DURATION{ std::chrono::duration<double, std::ratio<1>>{10s} };
