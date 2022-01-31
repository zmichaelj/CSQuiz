
#include <string>
#include <iostream>
#include "Game.h"
#include "HardGame.h"
#include "TestAnswers.h"

using namespace std;
int main(int argc, char* argv[]) {
	enum GameType { NONE, MINIGAME, FULL_GAME};
	GameType type = NONE;

	//first determine if it is an Easy Game or Hard Game
	std::string game_type = "";
	std::cout << "Hello, welcome fellow CS enthusiast. Come to test your skills? \n";
	
	 
	while ((game_type != "easygame") && (game_type != "hardgame")) {//wait until user enters which game they want
		game_type = "";
		std::cout << "Would you like to play an easy game, or a hard game? (type ' easy game' or 'hard game')" << endl;
		getline(cin, game_type);
		game_type = Game::removeSpacesToLower(game_type); //neutralize input to lowerspace without spaces
	}

	if (game_type == "easygame") {//decipher user input
		Game* game = new Game();
		game->initQuestions();//initializes questions
		game->startGame();//handles playing game
		delete game;
	}
	else {
		HardGame* game = new HardGame();
		game->initQuestions();
		game->startGame();
		delete game;
	}
	


	return 0;

}