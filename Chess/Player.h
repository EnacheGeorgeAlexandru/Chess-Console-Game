#pragma once
#include "Board.h"
#include "Move.h"

namespace Chess {
	class Player
	{
		std::string name;
		PieceColor color;
		Move* currentMovePtr;
	public:
		explicit Player(PieceColor color);
		void setColor(PieceColor color);
	    PieceColor getColor() const;
		void convertNotationsToCoordinates(const std::string&, const std::string&);
		void inputMove();
		Move* getCurrentMoveObj() const;
		~Player();
	};
}

