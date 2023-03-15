#pragma once
#include "Board.h"
#include "Player.h"

namespace Chess {
	class Game
	{
		Board* board;
		Player* player1;
		Player* player2;
		int moveCount;
	public:
		explicit Game();
		void nextMove(Player&);
		bool gameEnded();
		void playGame();
		~Game();
	};
}
