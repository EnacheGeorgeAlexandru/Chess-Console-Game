#pragma once
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Util.hpp"

namespace Chess {
	class Board;
	class Move;
	namespace Pieces {
		class Piece {
		protected:
			PieceColor color;
		public:
			explicit Piece(PieceColor color);
			PieceColor getColor() const;
			virtual void printPiece() const = 0;
			virtual std::list<std::pair<int, int>> legalMoves(const Board&, const std::pair<int, int>&) const = 0;
			virtual bool isMoveLegal(const Board&, const Move&) const = 0;
		};
	}
}

