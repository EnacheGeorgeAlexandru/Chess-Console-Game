#pragma once
#include "Board.h"
#include "Player.h"

namespace Chess {
	class Game
	{
		Board board;
		Player player1, player2;
		int moveCount = 0;
	public:
		void nextMove(Player&);
		bool gameEnded();
		void playGame();
	};
}
