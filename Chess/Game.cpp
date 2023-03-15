#include "Game.h"

using namespace Chess;

Game::Game() {
	board = new Board();
	player1 = new Player(PieceColor::eWhite);
	player2 = new Player(PieceColor::eBlack);
	moveCount = 0;
}

void Game::nextMove(Player& player) {
	if (player.getColor() == PieceColor::eBlack)
		std::cout << "black to move:\n";
	else if (player.getColor() == PieceColor::eWhite)
		std::cout << "white to move:\n";
	player.inputMove();
	while (!board->takeNextMove(player)) {
		std::cout << "\nNot Legal. Try Again:\n";
		player.inputMove();
	}
	board->printBoard();
}

bool Game::gameEnded() {
	if (board->isCheckmate()) {
		std::cout << "\n\nCHECKMATE\n\n";
		return true;
	}
	return false;
}

void Game::playGame() {
	board->printBoard();
	while (true) {
		moveCount++;
		std::cout << "Move " << moveCount << ":\n";
		nextMove(*player1);
		if (gameEnded())
			break;
		nextMove(*player2);
		if (gameEnded())
			break;
		std::cout << "\n";
	}
}

Game::~Game() {
	delete board;
	delete player1;
	delete player2;
}