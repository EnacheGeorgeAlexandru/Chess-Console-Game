#pragma once
#include "Piece.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

namespace Chess {
	class Tile
	{
		Pieces::Piece* PieceOnTile;
		std::pair<int8_t, int8_t> position;
	public:
		explicit Tile(Pieces::Piece* PieceOnTileP = nullptr);
		void setPieceOnTile(Pieces::Piece* PieceOnTileP);
		Pieces::Piece* getPieceOnTile() const;
		bool isTileEmpty() const;
		std::pair<int, int> getPosition()const;
		void setPosition(const std::pair<int, int>&);
		~Tile() {
			delete PieceOnTile;
		}
	};
}
