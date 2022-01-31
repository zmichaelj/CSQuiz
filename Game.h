#pragma once
#include "Question.h"
#include <string>
#include <vector>
#include <iostream>

class Game {
public:
	Game();
	virtual void startGame();//starts game and handles game operation
	static std::string removeSpacesToLower(std::string input);
	virtual void initQuestions();//sets questions for given quiz
	template<typename T>
	static void print(T message) {//template to allow quick printing of ints or strings
		std::cout << message << std::endl;
	}
protected:
	std::vector<Question> questions;
	int score;
	int currentQuestion;
	void displayNextQuestion();
	bool isCorrect(std::string response);
	void endGame();
};