#include "Question.h"


Question::Question():question("No Question!"), answer("No Answer!") {}
Question::Question(std::string question, std::string answer):question(question), answer(answer) {}


Question::Question(std::string question, std::string answer, funcptr ptr):
question(question), answer(answer),testAnswer(ptr) {};

std::string Question::getAnswer() {
	return answer;
}
