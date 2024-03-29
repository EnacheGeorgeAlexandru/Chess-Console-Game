#include "Move.h"

using namespace Chess;

Move::Move() {
	startSquare = { 0, 0 };
	endSquare = { 0, 0 };
}

Move::Move(const int& startSquareLine, const int& startSquareColumn, const int& endSquareLine, const int& endSquareColumn) {
	startSquare.first = startSquareLine;
	startSquare.second = startSquareColumn;

	endSquare.first = endSquareLine;
	endSquare.second = endSquareColumn;
}

Move::Move(const std::pair<int, int>& startSquareP, const std::pair<int, int>& endSquareP) {
	startSquare = startSquareP;
	endSquare = endSquareP;
}

std::pair<int, int> Move::getStartSquare() const {
	return startSquare;
}

std::pair<int, int> Move::getEndSquare() const {
	return endSquare;
}

void Move::setStartSquare(const int& line, const int& column) {
	startSquare = { line, column };
}

void Move::setEndSquare(const int& line, const int& column) {
	endSquare = { line, column };
}