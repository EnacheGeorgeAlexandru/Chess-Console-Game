#include "Queen.h"
#include "Board.h"

using namespace Chess::Pieces;

Queen::Queen(PieceColor colorP) : Piece(colorP) {}

void Queen::printPiece() const{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (color == PieceColor::eWhite)
		SetConsoleTextAttribute(hConsole, 159);
	if (color == PieceColor::eBlack)
		SetConsoleTextAttribute(hConsole, 80);
	std::cout << " Q ";
}

std::list<std::pair<int, int>> Queen::legalMoves(const Chess::Board& board, const std::pair<int, int>& startSquare) const {
	std::list<std::pair<int, int>> legalMoves;
	Rook rook(color);
	Bishop bishop(color);
	for (const auto& it : rook.legalMoves(board, startSquare))
		legalMoves.push_back(it);
	for (const auto& it : bishop.legalMoves(board, startSquare))
		legalMoves.push_back(it);
	return legalMoves;
}

bool Queen::isMoveLegal(const Chess::Board& board, const Chess::Move& move) const {
	std::list<std::pair<int, int>> legalMovesList = legalMoves(board, move.getStartSquare());
	if (std::find(legalMovesList.begin(), legalMovesList.end(), move.getEndSquare()) == legalMovesList.end())
		return false;
	return true;
}