#include "Game.h"
#pragma once
class HardGame : public Game {
public:
	HardGame();
	void initQuestions() override;
	void startGame() override;
private:
	bool isCorrect(int input, int answer); 
};