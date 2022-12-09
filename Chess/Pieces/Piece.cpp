#include "Piece.h"

using namespace Chess::Pieces;

Piece::Piece(const std::string& color) : color{color} {
}

std::string Piece::getColor() const {
	return color;
}
	
