#pragma once
#include <windows.h>
#include "Tile.h"
#include "Move.h"
#include "Player.h"

class Player;

class Board {
	std::vector<std::vector<Tile*>> board;
	std::pair<int, int> whiteKingPosition;
	std::pair<int, int> blackKingPosition;
	std::vector<Move*> whiteLegalMoves;
	std::vector<Move*> blackLegalMoves;
public:
	Board();
	//void setInitialBoardState();
	//bool makeMove(const Move&, const std::string&, const std::vector <std::pair<int, int>>&);
	Tile* getTileFromCoordinates(const std::pair<int, int>&) const;
	Piece* getPieceFromCoordinates(const std::pair<int, int>&) const;
	std::vector<std::vector<Tile*>> getBoard() const;
	void printTile(const Tile&, const int&) const;
	void printEmpty(const int&) const;
	void printBoard() const;
	bool validCoordinates(const int&, const int&) const;
	bool isCheckOnSquare(const std::pair<int, int>&, const std::string&) const;
	bool isKingInCheck(const std::string&) const;
	void updateKingPosition(const Move&, const std::string&);
	void takeMoveBack(const Move&, Piece*);
	bool isCheckmate();
	bool takeNextMove(const Player&);
	bool makeMoveIfLegal(const Move&, const std::string&);
	void setWhiteLegalMoves();
	void setBlackLegalMoves();
};

