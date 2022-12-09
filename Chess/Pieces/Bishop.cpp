#include "Bishop.h"
#include "Board.h"

using namespace Chess::Pieces;

Bishop::Bishop(const std::string& colorP) : Piece(colorP) {}

void Bishop::printPiece() const{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (color == "white")
		SetConsoleTextAttribute(hConsole, 159);
	if (color == "black")
		SetConsoleTextAttribute(hConsole, 80);
	std::cout << " B ";
	/*if (color == "white")
		std::cout << " B ";
	if (color == "black")
		std::cout << " b ";*/
}

std::list<std::pair<int, int>> Bishop::legalMoves(const Board& board, const std::pair<int, int>& startSquare) const {
	std::list<std::pair<int, int>> legalMoves;
	int line = startSquare.first, column = startSquare.second;
	for (line = startSquare.first + 1; line < 8; ++line) {
		column++;
		if(board.validCoordinates(line, column))
			if (board.getBoard()[line][column]->isTileEmpty())
				legalMoves.push_back(std::make_pair(line, column));
			else {
				if (board.getBoard()[line][column]->getPieceOnTile()->getColor() != color)
					legalMoves.push_back(std::make_pair(line, column));
				break;
			}
	}
	column = startSquare.second;
	for (line = startSquare.first - 1; line > - 1; --line) {
		column++;
		if (board.validCoordinates(line, column))
			if (board.getBoard()[line][column]->isTileEmpty())
				legalMoves.push_back(std::make_pair(line, column));
			else {
				if (board.getBoard()[line][column]->getPieceOnTile()->getColor() != color)
					legalMoves.push_back(std::make_pair(line, column));
				break;
			}
	}
	column = startSquare.second;
	for (line = startSquare.first + 1; line < 8; ++line) {
		column--;
		if (board.validCoordinates(line, column))
			if (board.getBoard()[line][column]->isTileEmpty())
				legalMoves.push_back(std::make_pair(line, column));
			else {
				if (board.getBoard()[line][column]->getPieceOnTile()->getColor() != color)
					legalMoves.push_back(std::make_pair(line, column));
				break;
			}
	}
	column = startSquare.second;
	for (line = startSquare.first - 1; line > -1; --line) {
		column--;
		if (board.validCoordinates(line, column))
			if (board.getBoard()[line][column]->isTileEmpty())
				legalMoves.push_back(std::make_pair(line, column));
			else {
				if (board.getBoard()[line][column]->getPieceOnTile()->getColor() != color)
					legalMoves.push_back(std::make_pair(line, column));
				break;
			}
	}
	return legalMoves;
}

bool Bishop::isMoveLegal(const Board& board, const Move& move) const {
	std::list<std::pair<int, int>> legalMovesList = legalMoves(board, move.getStartSquare());
	if (std::find(legalMovesList.begin(), legalMovesList.end(), move.getEndSquare()) == legalMovesList.end())
		return false;
	return true;
}