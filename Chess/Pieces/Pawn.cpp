#include "Pawn.h"
#include "Board.h"

using namespace Chess::Pieces;

Pawn::Pawn(const std::string& colorP) : Piece(colorP) {}

void Pawn::printPiece() const{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (color == "white")
		SetConsoleTextAttribute(hConsole, 159);
	if (color == "black")
		SetConsoleTextAttribute(hConsole, 80);
	std::cout << " P ";
	/*if (color == "white")
		std::cout << " P ";
	if (color == "black")
		std::cout << " p ";*/
}

std::list<std::pair<int, int>> Pawn::legalMoves(const Board& board, const std::pair<int, int>& startSquare) const{
	std::list<std::pair<int, int>> legalMoves;
	if (color == "white") {
		if (board.getBoard()[startSquare.first - 1][startSquare.second]->isTileEmpty()) {
			legalMoves.push_back(std::make_pair(startSquare.first - 1, startSquare.second));							//add square in front of pawn if it s empty
		    if(startSquare.first == 6 && board.getBoard()[startSquare.first - 2][startSquare.second]->isTileEmpty())
				legalMoves.push_back(std::make_pair(startSquare.first - 2, startSquare.second));						//add 4th rank square if the pawn is on its initial position
		}
		if(startSquare.second - 1 > -1)																					// in case it s an A pawn, not to look outside the board
			if(board.getBoard()[startSquare.first - 1][startSquare.second - 1]->isTileEmpty() == 0)						//not to ckeck the color of a piece that s not there
				if (board.getBoard()[startSquare.first - 1][startSquare.second - 1]->getPieceOnTile()->getColor() == "black")
					legalMoves.push_back(std::make_pair(startSquare.first - 1, startSquare.second - 1));
		if(startSquare.second + 1 < 8)																					// in case of an H pawn
			if (board.getBoard()[startSquare.first - 1][startSquare.second + 1]->isTileEmpty() == 0)
				if (board.getBoard()[startSquare.first - 1][startSquare.second + 1]->getPieceOnTile()->getColor() == "black")
					legalMoves.push_back(std::make_pair(startSquare.first - 1, startSquare.second + 1));
	}

	if (color == "black") {
		if (board.getBoard()[startSquare.first + 1][startSquare.second]->isTileEmpty()) {
			legalMoves.push_back(std::make_pair(startSquare.first + 1, startSquare.second));
			if(startSquare.first == 1 && board.getBoard()[startSquare.first + 2][startSquare.second]->isTileEmpty())
				legalMoves.push_back(std::make_pair(startSquare.first + 2, startSquare.second));
		}
		if (startSquare.second - 1 > -1)																					// in case it s an A pawn, not to look outside the board
			if (board.getBoard()[startSquare.first + 1][startSquare.second - 1]->isTileEmpty() == 0)
				if (board.getBoard()[startSquare.first + 1][startSquare.second - 1]->getPieceOnTile()->getColor() == "white")
					legalMoves.push_back(std::make_pair(startSquare.first + 1, startSquare.second - 1));
		if (startSquare.second + 1 < 8)																					// in case of an H pawn
			if (board.getBoard()[startSquare.first + 1][startSquare.second + 1]->isTileEmpty() == 0)
				if (board.getBoard()[startSquare.first + 1][startSquare.second + 1]->getPieceOnTile()->getColor() == "white")
					legalMoves.push_back(std::make_pair(startSquare.first + 1, startSquare.second + 1));
	}
	return legalMoves;
}

bool Pawn::isMoveLegal(const Board& board, const Move& move) const {
	std::list<std::pair<int, int>> legalMovesList = legalMoves(board, move.getStartSquare());
	if (std::find(legalMovesList.begin(), legalMovesList.end(), move.getEndSquare()) == legalMovesList.end())
		return false;
	return true;
}