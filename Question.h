#pragma once
#include <string>


class Question {
public:
	std::string question;//holds question
	typedef bool (*funcptr)(int input, int answer);
	funcptr testAnswer;//holds pointer to applicable test function
	Question();
	Question(std::string question, std::string answer);
	Question(std::string question, std::string answer, funcptr ptr);
	std::string getAnswer();
private:
	std::string answer;

};