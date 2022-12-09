#pragma once
#include "Piece.h"

namespace Chess::Pieces {
	class Knight : public Piece {
	public:
		Knight(const std::string& colorP);
		void printPiece() const;
		std::list<std::pair<int, int>> legalMoves(const Board&, const std::pair<int, int>&) const;
		bool isMoveLegal(const Board&, const Move&) const;
	};
}

