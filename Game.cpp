#include "Game.h"
#include <string>
#include <iostream>

Game::Game():
	score(0), 
	currentQuestion(1) {}
void Game::initQuestions() {
	questions.push_back(Question("\nbool isNumEven(int i);\n"
		"bool isNumEven(double i);\n"
		"This is an example of what concept?\n"
		"A. Polymorphism\n"
		"B. Overloading\n"
		"C. Inheritance\n"
		"\n(Type A, B, or C)\n", "b"));
	questions.push_back(Question(
		"True or False, one of the primary purposes of\n"
		"namespaces is to prevent name collisions in your code.\n"
		"\n(Type T or F)\n", "t"));
	questions.push_back(Question(
		"std::set<std::string> companyCandidates;\n"
		"companyCandidates.insert(\"Michael\");\n"
		"companyCandidates.insert(\"Jane\");\n"
		"companyCandidates.insert(\"Elon\");\n"
		"companyCandidates.insert(\"Michael\");\n"
		"What is companyCandidates.size() after the above lines?\n"
		"\n(Type 1, 2, 3, or 4)\n", "3"));
}


void Game::startGame() {
	while (currentQuestion <= questions.size()) {//see if more questions left 
		displayNextQuestion();
		std::string response;
		getline(std::cin, response);
		if (isCorrect(response)) { //check to see if response is correct
			score++; //increment score
			print("Correct! Your new score is " + std::to_string(score));
		}
		else {
			score--;
			print("Incorrect! Your new score is: " + std::to_string(score));
		}
		currentQuestion++; //go to next question
	}
	endGame();
}


void Game::endGame() {
	if (score >= 1)
		print("Good Work! Your final score was " + std::to_string(score) + "!");
	else
		print("Study up before your interviews! Your final score was " + std::to_string(score) + "!");
}

bool Game::isCorrect(std::string response) {
	return questions[currentQuestion-1].getAnswer()[0] == tolower(response[0]);//currentQuestion-1 because it starts at 1
}
void Game::displayNextQuestion() {
	print(currentQuestion);
	print(questions[currentQuestion-1].question);//currentQuestion-1 because it starts at 1
}

//removes spaces and converts to lower case
std::string Game::removeSpacesToLower(std::string input) {
	int count = 0;//count non white spaces
	for (int i = 0; input[i]; i++) {
		if (input[i] != ' ') {
			input[count++] = tolower(input[i]);
		}
	}
	input.erase(count);
	return input;
}