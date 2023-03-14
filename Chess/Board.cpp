#include "Board.h"

using namespace Chess;
using namespace Chess::Pieces;

Board::Board() {
	board.resize(8, std::vector<Tile*>(8));
	for(int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j) {
			board[i][j] = new Tile;
			board[i][j]->setPosition(std::make_pair(i, j));
		}
	for (auto& i : board[1])
		i->setPieceOnTile(new Pawn(PieceColor::eBlack));            
	board[0][0]->setPieceOnTile(new Rook(PieceColor::eBlack)); 		
	board[0][7]->setPieceOnTile(new Rook(PieceColor::eBlack)); 		
	board[0][1]->setPieceOnTile(new Knight(PieceColor::eBlack)); 		
	board[0][6]->setPieceOnTile(new Knight(PieceColor::eBlack)); 
	board[0][2]->setPieceOnTile(new Bishop(PieceColor::eBlack)); 		
	board[0][5]->setPieceOnTile(new Bishop(PieceColor::eBlack)); 		
	board[0][3]->setPieceOnTile(new Queen(PieceColor::eBlack)); 		
	board[0][4]->setPieceOnTile(new King(PieceColor::eBlack)); 		
	blackKingPosition = std::make_pair(0, 4);


	for (auto& i : board[6])
		i->setPieceOnTile(new Pawn(PieceColor::eWhite));		
	board[7][0]->setPieceOnTile(new Rook(PieceColor::eWhite));		
	board[7][7]->setPieceOnTile(new Rook(PieceColor::eWhite));		
	board[7][1]->setPieceOnTile(new Knight(PieceColor::eWhite));		
	board[7][6]->setPieceOnTile(new Knight(PieceColor::eWhite));		
	board[7][2]->setPieceOnTile(new Bishop(PieceColor::eWhite));	
	board[7][5]->setPieceOnTile(new Bishop(PieceColor::eWhite));		
	board[7][3]->setPieceOnTile(new Queen(PieceColor::eWhite));		
	board[7][4]->setPieceOnTile(new King(PieceColor::eWhite));	
	whiteKingPosition = std::make_pair(7, 4);
}

Tile* Board::getTileFromCoordinates(const std::pair<int, int>& square) const {
	return board[square.first][square.second];
}

Piece* Board::getPieceFromCoordinates(const std::pair<int, int>& square) const {
	return board[square.first][square.second]->getPieceOnTile();
}

void Board::printTile(const Tile& tile, const int& count)const {
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (count % 2)
		SetConsoleTextAttribute(hConsole, 15);
	else SetConsoleTextAttribute(hConsole, 240);
	if (tile.isTileEmpty() == false) {
		std::cout << "  ";
		tile.getPieceOnTile()->printPiece();
		if (count % 2)
			SetConsoleTextAttribute(hConsole, 15);
		else SetConsoleTextAttribute(hConsole, 240);
		std::cout << "  ";
	}
	else
		std::cout << "       ";
}

void Board::printEmpty(const int& count) const{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (count % 2)
		SetConsoleTextAttribute(hConsole, 15);
	else SetConsoleTextAttribute(hConsole, 240);
	std::cout << "       ";
}

void Board::printBoard() const{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int countLines = 0;
	std::cout << "\n";
	for (auto& i : board)
	{
		int countSquares = countLines;
		std::cout << "    ";
		for (int i = countSquares; i < countSquares + 8; ++i)
			printEmpty(i);
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "\n" << " " << 8 - countLines <<"  ";
		for (auto j : i) {
			printTile(*j,countSquares);
			countSquares++;
		}
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "\n    ";
		for (int i = countSquares; i < countSquares + 8; ++i)
			printEmpty(i);
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "\n";
		countLines++;
	}
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "\n       A      B      C      D      E      F      G      H\n";
}

std::vector<std::vector<Tile*>> Board::getBoard() const {
	return board;
}

bool Board::validCoordinates(const int& line, const int& column) const {
	if (line < 0 || column < 0)
		return false;
	if (line > 7 || column > 7)
		return false;
	return true;
}

bool Board::isCheckOnSquare(const std::pair<int, int>& square, PieceColor color) const{
	std::vector <std::pair<int, int>> opposideSideLegalSquares;
	if (color == PieceColor::eWhite)
		for (const auto& move : blackLegalMoves)
			opposideSideLegalSquares.push_back(move->getEndSquare());
	if (color == PieceColor::eBlack)
		for (const auto& move : whiteLegalMoves)
			opposideSideLegalSquares.push_back(move->getEndSquare());
	auto found = std::find(opposideSideLegalSquares.begin(), opposideSideLegalSquares.end(), square);
	if (found != opposideSideLegalSquares.end()) 
		return true;
	return false;
}

bool Board::isKingInCheck(PieceColor color) const{
	if (color == PieceColor::eWhite)
		return isCheckOnSquare(whiteKingPosition, color);
	else if (color == PieceColor::eBlack)
		return isCheckOnSquare(blackKingPosition, color);
	return false;
}

void Board::updateKingPosition(const Move& move, PieceColor color) {
	if (color == PieceColor::eWhite && move.getStartSquare() == whiteKingPosition)
		whiteKingPosition = move.getEndSquare();
	if (color == PieceColor::eBlack && move.getStartSquare() == blackKingPosition)
		blackKingPosition = move.getEndSquare();
}

void Board::takeMoveBack(const Move& move, Piece* onEndTile) {
	Tile* startTile = getTileFromCoordinates(move.getStartSquare());
	Tile* endTile = getTileFromCoordinates(move.getEndSquare());
	Piece* pieceMoved = getPieceFromCoordinates(move.getEndSquare());
	startTile->setPieceOnTile(pieceMoved);
	endTile->setPieceOnTile(onEndTile);
	if (whiteKingPosition == move.getEndSquare())
		whiteKingPosition = move.getStartSquare();
	if (blackKingPosition == move.getEndSquare())
		blackKingPosition = move.getStartSquare();
}

bool Board::isCheckmate() {
	std::pair<int, int> kingPosition = whiteKingPosition;
	std::vector<Move*> legalMoves = whiteLegalMoves;
	bool checkmate = 0;
	if (isKingInCheck(PieceColor::eWhite)) {
		checkmate = 1;
		for (const auto& move : legalMoves) {
			Piece* onEndTile = getPieceFromCoordinates(move->getEndSquare());
			makeMoveIfLegal(*move, PieceColor::eWhite);
			setBlackLegalMoves();
			if (!isKingInCheck(PieceColor::eWhite)) {
				checkmate = 0;
				takeMoveBack(*move, onEndTile);
				break;
			}
			takeMoveBack(*move, onEndTile);
		}
	}
	kingPosition = blackKingPosition;
	setBlackLegalMoves();
	legalMoves = blackLegalMoves;
	if (isKingInCheck(PieceColor::eBlack)) {
		checkmate = 1;
		for (const auto& move : legalMoves) {
			Piece* onEndTile = getPieceFromCoordinates(move->getEndSquare());
			makeMoveIfLegal(*move, PieceColor::eBlack);
			setWhiteLegalMoves();
			if (!isKingInCheck(PieceColor::eBlack)) {
				checkmate = 0;
				takeMoveBack(*move, onEndTile);
				break;
			}
			takeMoveBack(*move, onEndTile);
		}
	}
	return checkmate;
}

bool Board::takeNextMove(const Player& player) {
	PieceColor color = player.getColor();
	Move* move = player.getCurrentMoveObj();
	Piece* onEndTile = getPieceFromCoordinates(move->getEndSquare());	//remember piece in case of take back
	bool madeMove = makeMoveIfLegal(*move, color);		
	if (color == PieceColor::eWhite)
		setBlackLegalMoves();
	if (color == PieceColor::eBlack)
		setWhiteLegalMoves();
	if (madeMove && isKingInCheck(color)) {
		takeMoveBack(*move, onEndTile);
		madeMove = 0;
	}
	setWhiteLegalMoves();
	setBlackLegalMoves();
	delete move;
	return madeMove;
}

bool Board::makeMoveIfLegal(const Move& move,PieceColor color) {
	Piece* pieceToMove = getPieceFromCoordinates(move.getStartSquare());
	if(pieceToMove && pieceToMove->getColor() == color)
		if (pieceToMove->isMoveLegal(*this, move)) {
			Tile* startTile = getTileFromCoordinates(move.getStartSquare());
			Tile* endTile = getTileFromCoordinates(move.getEndSquare());
			endTile->setPieceOnTile(pieceToMove);
			//delete startTile->getPieceOnTile();
			startTile->setPieceOnTile(nullptr);
			updateKingPosition(move, color);
			return true;
		}
	return false;
}

void Board::setWhiteLegalMoves() {
	for (auto& move : whiteLegalMoves)
		delete move;
	whiteLegalMoves.clear();
	for(const auto& line : board)
		for(const auto& tile : line)
			if (tile->getPieceOnTile() != nullptr && tile->getPieceOnTile()->getColor() == PieceColor::eWhite)
				for (const auto& legalSquare : tile->getPieceOnTile()->legalMoves(*this, tile->getPosition())) {
					Move* move = new Move(tile->getPosition(), legalSquare);
					whiteLegalMoves.push_back(move);
				}
}

void Board::setBlackLegalMoves() {
	for (auto& move : blackLegalMoves)
		delete move;
	blackLegalMoves.clear();
	for (const auto& line : board)
		for (const auto& tile : line)
			if (tile->getPieceOnTile() != nullptr && tile->getPieceOnTile()->getColor() == PieceColor::eBlack)
				for (const auto& legalSquare : tile->getPieceOnTile()->legalMoves(*this, tile->getPosition())) {
					Move* move = new Move(tile->getPosition(), legalSquare);
					blackLegalMoves.push_back(move);
				}
}