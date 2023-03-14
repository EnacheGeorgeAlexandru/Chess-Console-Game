#pragma once
#include <windows.h>
#include "Tile.h"
#include "Move.h"
#include "Player.h"


namespace Chess {
	class Player;
	class Board {
		std::vector<std::vector<Tile*>> board;
		std::pair<int, int> whiteKingPosition;
		std::pair<int, int> blackKingPosition;
		std::vector<Move*> whiteLegalMoves;
		std::vector<Move*> blackLegalMoves;
	public:
		Board();
		Tile* getTileFromCoordinates(const std::pair<int, int>&) const;
		Pieces::Piece* getPieceFromCoordinates(const std::pair<int, int>&) const;
		std::vector<std::vector<Tile*>> getBoard() const;
		void printTile(const Tile&, const int&) const;
		void printEmpty(const int&) const;
		void printBoard() const;
		bool validCoordinates(const int&, const int&) const;
		bool isCheckOnSquare(const std::pair<int, int>&, PieceColor color) const;
		bool isKingInCheck(PieceColor color) const;
		void updateKingPosition(const Move&, PieceColor color);
		void takeMoveBack(const Move&, Pieces::Piece*);
		bool isCheckmate();
		bool takeNextMove(const Player&);
		bool makeMoveIfLegal(const Move&, PieceColor);
		void setWhiteLegalMoves();
		void setBlackLegalMoves();
		~Board() {
			for (auto& move : whiteLegalMoves)
				delete move;
			for (auto& move : blackLegalMoves)
				delete move;
			for (auto& line : board)
				for (auto& tile : line)
					delete tile;
		}
	};
}

