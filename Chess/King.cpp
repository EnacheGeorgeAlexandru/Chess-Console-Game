#include "King.h"
#include "Board.h"

King::King(const std::string& colorP) {
	color = colorP;
}

void King::printPiece() const{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (color == "white")
		SetConsoleTextAttribute(hConsole, 159);
	if (color == "black")
		SetConsoleTextAttribute(hConsole, 80);
	std::cout << " K ";
	/*if (color == "white")
		std::cout << " K ";
	if (color == "black")
		std::cout << " k ";*/
}

std::list<std::pair<int, int>> King::legalMoves(const Board& board, const std::pair<int, int>& startSquare) const {
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
	/*for (const auto& square : pseudoLegalMoves) {
		if (!board.isCheckOnSquare(square, color))
			legalMoves.push_back(square);
	}*/
	return pseudoLegalMoves;
}

bool King::isMoveLegal(const Board& board, const Move& move) const {
	std::list<std::pair<int, int>> legalMovesList = legalMoves(board, move.getStartSquare());
	if (std::find(legalMovesList.begin(), legalMovesList.end(), move.getEndSquare()) == legalMovesList.end())
		return false;
	return true;
}