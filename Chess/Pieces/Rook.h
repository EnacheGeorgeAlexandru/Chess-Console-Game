#pragma once
#include "Piece.h"

namespace Chess::Pieces {
	class Rook : public Piece {
	public:
		Rook(PieceColor colorP);
		void printPiece() const;
		void rookLogic(const Board& board, const std::pair<int, int>& startSquare, const int& line, const int& column);
		std::list<std::pair<int, int>> legalMoves(const Board&, const std::pair<int, int>&) const;
		bool isMoveLegal(const Board&, const Move&) const;
	};
}

