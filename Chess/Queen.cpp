#include "Queen.h"
#include "Board.h"

Queen::Queen(const std::string& colorP) {
	color = colorP;
}

void Queen::printPiece() const{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (color == "white")
		SetConsoleTextAttribute(hConsole, 159);
	if (color == "black")
		SetConsoleTextAttribute(hConsole, 80);
	std::cout << " Q ";
	/*if (color == "white")
		std::cout << " Q ";
	if (color == "black")
		std::cout << " q ";*/
}

std::list<std::pair<int, int>> Queen::legalMoves(const Board& board, const std::pair<int, int>& startSquare) const {
	std::list<std::pair<int, int>> legalMoves;
	Rook rook(color);
	Bishop bishop(color);
	for (const auto& it : rook.legalMoves(board, startSquare))
		legalMoves.push_back(it);
	for (const auto& it : bishop.legalMoves(board, startSquare))
		legalMoves.push_back(it);
	return legalMoves;
}

bool Queen::isMoveLegal(const Board& board, const Move& move) const {
	std::list<std::pair<int, int>> legalMovesList = legalMoves(board, move.getStartSquare());
	if (std::find(legalMovesList.begin(), legalMovesList.end(), move.getEndSquare()) == legalMovesList.end())
		return false;
	return true;
}