#include "TestAnswers.h"
#include <unordered_map>
#include <string>

TestAnswers::TestAnswers(){}

//tests knowledge of references and pointers
bool TestAnswers::referencesAndPointerTest(int input, int answer) {
		int b = input;
		int a = 7;
		int &k = a;
		int *ptr = &b;
		k += b;
		*ptr += a;
	return b == answer;
}

//test knowledge of unordered maps
bool TestAnswers::mapTest(int i, int answer) {
	std::unordered_map<std::string, int> candidateMap;
	candidateMap["Michael"] = 100;
	candidateMap["Lucy"] = 7;
	candidateMap["Elon Musk"] = i;
	auto mystery = &candidateMap["Elon Musk"];
	candidateMap["Elon Musk"] *= 4;
	candidateMap["Michael"] = *mystery;
	return candidateMap["Michael"] == answer;
}

//tests knowledge of namespaces
namespace first {
	int modNum(int in) {
		return 2 * in;
	}
}
namespace second {
	int modNum(int in) {
		return 3 * in;
	}

}
bool TestAnswers::namespacesTest(int input, int answer) {
	using namespace second;//put this here to trick the user on the test
	return first::modNum(input) == answer;//will use the first namespace of 'modNum' as specified
}