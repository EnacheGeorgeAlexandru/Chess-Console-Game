#pragma once
#include "Board.h"
#include "Move.h"

namespace Chess {
	class Player
	{
		std::string name;
		PieceColor color;
		std::pair<std::pair<int, int>, std::pair<int, int>> currentMove;
		Move* currentMovePtr;
	public:
		void setColor(PieceColor color);
	    PieceColor getColor() const;
		void convertNotationsToCoordinates(const std::string&, const std::string&);
		void inputMove();
		std::pair<std::pair<int, int>, std::pair<int, int>> getCurrentMove() const;
		Move* getCurrentMoveObj() const;
		~Player() {
			delete currentMovePtr;
		}
	};
}

