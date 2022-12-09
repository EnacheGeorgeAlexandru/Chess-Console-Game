#include "Knight.h"
#include "Board.h"

using namespace Chess::Pieces;

Knight::Knight(const std::string& colorP) : Piece(colorP) {}

void Knight::printPiece() const{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (color == "white")
		SetConsoleTextAttribute(hConsole, 159);
	if (color == "black")
		SetConsoleTextAttribute(hConsole, 80);
	std::cout << " N ";
	/*if (color == "white")
		std::cout << " N ";
	if (color == "black")
		std::cout << " n ";*/
}

std::list<std::pair<int, int>> Knight::legalMoves(const Chess::Board& board, const std::pair<int, int>& startSquare) const {
	std::list<std::pair<int, int>> legalMoves;
	std::list<std::pair<int, int>> potentialMoves;
	int i = startSquare.first, j = startSquare.second;
	potentialMoves.push_back(std::make_pair(i - 1, j + 2));
	potentialMoves.push_back(std::make_pair(i - 1, j - 2));
	potentialMoves.push_back(std::make_pair(i + 1, j + 2));
	potentialMoves.push_back(std::make_pair(i + 1, j - 2));
	potentialMoves.push_back(std::make_pair(i - 2, j + 1));
	potentialMoves.push_back(std::make_pair(i - 2, j - 1));
	potentialMoves.push_back(std::make_pair(i + 2, j + 1));
	potentialMoves.push_back(std::make_pair(i + 2, j - 1));
	for (auto move : potentialMoves)
		if (board.validCoordinates(move.first, move.second))
			if (board.getBoard()[move.first][move.second]->isTileEmpty())
				legalMoves.push_back(move);
			else 
				if (board.getBoard()[move.first][move.second]->getPieceOnTile()->getColor() != color)
					legalMoves.push_back(move);
	return legalMoves;
}

bool Knight::isMoveLegal(const Chess::Board& board, const Chess::Move& move) const {
	std::list<std::pair<int, int>> legalMovesList = legalMoves(board, move.getStartSquare());
	if (std::find(legalMovesList.begin(), legalMovesList.end(), move.getEndSquare()) == legalMovesList.end())
		return false;
	return true;
}