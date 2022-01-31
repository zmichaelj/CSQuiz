#include "HardGame.h"
#include "Question.h"//create questions
#include "TestAnswers.h"// test user answers
#include <iostream>//write to consol

HardGame::HardGame() {
}
//initialize Questions
void HardGame::initQuestions(){
	questions.push_back(Question(
		"\nint ptrQuiz(int b){\n"
		"\n\tint i = b;\n"
		"\tint j = 7\n"
		"\tint* ptr = &i;\n"
		"\tint& k = j;\n"
		"\tk += i;\n"
		"\t*ptr += j;\n"
		"\treturn i;\n"
		"\n}\n"
		"Choose a value of b for which you'd like to solve this problem.\n", "NA", &TestAnswers::referencesAndPointerTest));
	questions.push_back(Question(
		"\nnamespace first {\n"
		"\tint modNum(int in) {\n"
		"	\treturn 2 * in;\n"
		"\t}\n"
		"}\n"
		"namespace second {\n"
		"\tint modNum(int in) {\n"
		"\t\treturn 3 * in;\n"
		"\t}\n"
		"}\n"
		"int main(int input){\n"
		"\tusing namespace second;\n"//put this here to trick the user on the 'test'
		"\t return first::modNum(input)\n"
		"}\n"
		"Pick a value for 'input' with which you'd like to solve this problem.\n", "NA", &TestAnswers::namespacesTest));
	questions.push_back(Question(
		"\nstd::unordered_map<std::string, int> candidateMap;\n"
		"candidateMap[\"Michael\"] = 100;\n"
		"candidateMap[\"Lucy\"] = 7;\n"
		"candidateMap[\"Elon Musk\"] = i;\n"
		"auto mystery = &candidateMap[\"Elon Musk\"];\n"
		"candidateMap[\"Elon Musk\"] *= 4;\n"
		"candidateMap[\"Michael\"] = *mystery;\n"
		"return candidateMap[\"Michael\"];\n"
		"\nPick a value for i with which you'd like to solve this problem.\n", "NA", &TestAnswers::mapTest));
};

//Controls Gameplay.
void HardGame::startGame() {
	while (currentQuestion <= questions.size()) { //check to see if answered last question
		displayNextQuestion();
		int input;//get the first input for function
		std::cin >> input;
		print("Now enter the return value for your given input value");
		int answer;//get second input for function
		std::cin >> answer;
		if (isCorrect(input, answer)) { //check to see if response is correct
			score++; //increment score
			std::cout << "Correct! Your new score is: " << score << std::endl;
		}
		else {
			score--;
			std::cout << "Incorrect! Your new score is: " << score << std::endl;
		}
		currentQuestion++; //go to next question
	}
	endGame();
}
bool HardGame::isCorrect(int input, int answer) { //overloaded function from inhereted method isCorrect()
	auto test = questions[currentQuestion-1].testAnswer;//get applicable function pointer
	return test(input, answer);
}