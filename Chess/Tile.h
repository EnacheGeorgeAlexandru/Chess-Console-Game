#pragma once
#include "Piece.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

//#include<vector>
//class Piece;
//class Pawn;
//class Knight;
//class Bishop;
//class Rook;
//class Queen;
//class King;

class Tile
{
	Piece* PieceOnTile;
	std::pair<int, int> position;
public:
	explicit Tile(Piece* PieceOnTileP = nullptr);
	void setPieceOnTile(Piece* PieceOnTileP);
	Piece* getPieceOnTile() const;
	bool isTileEmpty() const;
	std::pair<int, int> getPosition()const;
	void setPosition(const std::pair<int, int>&);

};

