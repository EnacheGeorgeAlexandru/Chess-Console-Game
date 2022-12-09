#include "Rook.h"
#include "Board.h"

using namespace Chess::Pieces;

Rook::Rook(const std::string& colorP) : Piece(colorP) {}

void Rook::printPiece() const{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (color == "white")
		SetConsoleTextAttribute(hConsole, 159);
	if (color == "black")
		SetConsoleTextAttribute(hConsole, 80);
	std::cout << " R ";
	/*if (color == "white")
		std::cout << " R ";
	if (color == "black")
		std::cout << " r ";*/
}

void Rook::rookLogic(const Board& board, const std::pair<int, int>& startSquare, const int& line, const int& column) {

}

std::list<std::pair<int, int>> Rook::legalMoves(const Chess::Board& board, const std::pair<int, int>& startSquare) const {
	std::list<std::pair<int, int>> legalMoves;
	int line, column = startSquare.second;
	for (line = startSquare.first + 1; line < 8; ++line)
		if (board.getBoard()[line][column]->isTileEmpty())
			legalMoves.push_back(std::make_pair(line, column));
		else {
			if (board.getBoard()[line][column]->getPieceOnTile()->getColor() != color)
				legalMoves.push_back(std::make_pair(line, column));
			break;
		}
	for (line = startSquare.first - 1; line > -1; --line)
		if (board.getBoard()[line][column]->isTileEmpty())
			legalMoves.push_back(std::make_pair(line, column));
		else {
			if (board.getBoard()[line][column]->getPieceOnTile()->getColor() != color)
				legalMoves.push_back(std::make_pair(line, column));
			break;
		}
	line = startSquare.first;
	for (column = startSquare.second + 1; column < 8; ++column)
		if (board.getBoard()[line][column]->isTileEmpty())
			legalMoves.push_back(std::make_pair(line, column));
		else {
			if (board.getBoard()[line][column]->getPieceOnTile()->getColor() != color)
				legalMoves.push_back(std::make_pair(line, column));
			break;
		}
	for (column = startSquare.second - 1; column > -1; --column)
		if (board.getBoard()[line][column]->isTileEmpty())
			legalMoves.push_back(std::make_pair(line, column));
		else {
			if (board.getBoard()[line][column]->getPieceOnTile()->getColor() != color)
				legalMoves.push_back(std::make_pair(line, column));
			break;
		}	
	return legalMoves;
}

bool Rook::isMoveLegal( const Chess::Board& board, const Chess::Move& move) const {
	std::list<std::pair<int, int>> legalMovesList = legalMoves(board, move.getStartSquare());
	if (std::find(legalMovesList.begin(), legalMovesList.end(), move.getEndSquare()) == legalMovesList.end())
		return false;
	return true;
}