#pragma once
#include "Piece.h"

namespace Chess::Pieces {
	class King : public Piece {
	public:
		King(PieceColor colorP);
		void printPiece() const;
		std::list<std::pair<int, int>> legalMoves(const Board&, const std::pair<int, int>&) const;
		bool isMoveLegal(const Board&, const Move&) const;
	};
}

