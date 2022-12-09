#include "Game.h"

using namespace Chess;

void Game::nextMove(Player& player) {
	std::cout << player.getColor() << " to move:\n";
	player.inputMove();
	while (!board.takeNextMove(player)) {
		std::cout << "\nNot Legal. Try Again:\n";
		player.inputMove();
	}
	board.printBoard();
}

bool Game::gameEnded() {
	if (board.isCheckmate()) {
		std::cout << "\n\nCHECKMATE\n\n";
		return true;
	}
	return false;
}

void Game::playGame() {
	board.printBoard();
	player1.setColor("white");
	player2.setColor("black");
	while (true) {
		moveCount++;
		std::cout << "Move " << moveCount << ":\n";
		nextMove(player1);
		if (gameEnded())
			break;
		nextMove(player2);
		if (gameEnded())
			break;
		std::cout << "\n";
	}
}