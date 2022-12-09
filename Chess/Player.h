#pragma once
#include "Board.h"
#include "Move.h"

class Player
{
	std::string name;
	std::string color;
	std::pair<std::pair<int, int>, std::pair<int, int>> currentMove;
	Move* currentMovePtr;
	//std::vector<std::pair<int, int>> allLegalSquares;
public:
	void setColor(const std::string&);
	std::string getColor() const;
	void convertNotationsToCoordinates(const std::string&, const std::string&);
	void inputMove();
	std::pair<std::pair<int, int>, std::pair<int, int>> getCurrentMove() const;
	Move getCurrentMoveObj() const;
	//void setAllLegalSquares(const Board&);
	//std::vector<std::pair<int, int>> getAllLegalSquares() const;
};

