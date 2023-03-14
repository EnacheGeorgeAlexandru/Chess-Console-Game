#include "King.h"
#include "Board.h"

using namespace Chess::Pieces;

King::King(PieceColor colorP) :Piece(colorP) {}

void King::printPiece() const{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (color == PieceColor::eWhite)
		SetConsoleTextAttribute(hConsole, 159);
	if (color == PieceColor::eBlack)
		SetConsoleTextAttribute(hConsole, 80);
	std::cout << " K ";
}

std::list<std::pair<int, int>> King::legalMoves(const Chess::Board& board, const std::pair<int, int>& startSquare) const {
	std::list<std::pair<int, int>> legalMoves;
	std::list<std::pair<int, int>> pseudoLegalMoves;
	for (int column = startSquare.second - 1; column < startSquare.second + 2; ++column) {
		if (board.validCoordinates(startSquare.first - 1, column)) {
			if (board.getBoard()[startSquare.first - 1][column]->isTileEmpty())						//3 squares in front of the king
				pseudoLegalMoves.push_back(std::make_pair(startSquare.first - 1, column));
			else 
				if(board.getBoard()[startSquare.first - 1][column]->getPieceOnTile()->getColor() != color)
					pseudoLegalMoves.push_back(std::make_pair(startSquare.first - 1, column));
		}
		if (board.validCoordinates(startSquare.first, column)) {
			if (board.getBoard()[startSquare.first][column]->isTileEmpty())						
				pseudoLegalMoves.push_back(std::make_pair(startSquare.first, column));
			else
				if (board.getBoard()[startSquare.first][column]->getPieceOnTile()->getColor() != color)
					pseudoLegalMoves.push_back(std::make_pair(startSquare.first, column));
		}
		if (board.validCoordinates(startSquare.first + 1, column)) {
			if (board.getBoard()[startSquare.first + 1][column]->isTileEmpty())
				pseudoLegalMoves.push_back(std::make_pair(startSquare.first + 1, column));
			else
				if (board.getBoard()[startSquare.first + 1][column]->getPieceOnTile()->getColor() != color)
					pseudoLegalMoves.push_back(std::make_pair(startSquare.first + 1, column));
		}
	}
	return pseudoLegalMoves;
}

bool King::isMoveLegal(const Chess::Board& board, const Chess::Move& move) const {
	std::list<std::pair<int, int>> legalMovesList = legalMoves(board, move.getStartSquare());
	if (std::find(legalMovesList.begin(), legalMovesList.end(), move.getEndSquare()) == legalMovesList.end())
		return false;
	return true;
}