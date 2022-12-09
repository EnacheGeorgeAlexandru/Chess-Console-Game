#include "Board.h"

using namespace Chess;
using namespace Chess::Pieces;

Board::Board() {
	board.resize(8, std::vector<Tile*>(8));
	/*for (auto& i : board)
		for (auto& j : i)
			j = new Tile(nullptr);*/
	for(int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j) {
			board[i][j] = new Tile;
			board[i][j]->setPosition(std::make_pair(i, j));
		}
	for (auto& i : board[1])
		i->setPieceOnTile(new Pawn("black"));
	board[0][0]->setPieceOnTile(new Rook("black"));
	board[0][7]->setPieceOnTile(new Rook("black"));
	board[0][1]->setPieceOnTile(new Knight("black"));
	board[0][6]->setPieceOnTile(new Knight("black"));
	board[0][2]->setPieceOnTile(new Bishop("black"));
	board[0][5]->setPieceOnTile(new Bishop("black"));
	board[0][3]->setPieceOnTile(new Queen("black"));
	board[0][4]->setPieceOnTile(new King("black"));
	blackKingPosition = std::make_pair(0, 4);


	for (auto& i : board[6])
		i->setPieceOnTile(new Pawn("white"));
	board[7][0]->setPieceOnTile(new Rook("white"));
	board[7][7]->setPieceOnTile(new Rook("white"));
	board[7][1]->setPieceOnTile(new Knight("white"));
	board[7][6]->setPieceOnTile(new Knight("white"));
	board[7][2]->setPieceOnTile(new Bishop("white"));
	board[7][5]->setPieceOnTile(new Bishop("white"));
	board[7][3]->setPieceOnTile(new Queen("white"));
	board[7][4]->setPieceOnTile(new King("white"));
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
	//for (int i = 0; i < 300; ++i) {
	//	SetConsoleTextAttribute(hConsole, i);      //15 si 240 alb
	//	std::cout << i<<"///////\n";
	//}
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

bool Board::isCheckOnSquare(const std::pair<int, int>& square, const std::string& color) const{
	std::vector <std::pair<int, int>> opposideSideLegalSquares;
	if (color == "white")
		for (const auto& move : blackLegalMoves)
			opposideSideLegalSquares.push_back(move->getEndSquare());
	if (color == "black") 
		for (const auto& move : whiteLegalMoves)
			opposideSideLegalSquares.push_back(move->getEndSquare());
	auto found = std::find(opposideSideLegalSquares.begin(), opposideSideLegalSquares.end(), square);
	if (found != opposideSideLegalSquares.end()) 
		return true;
	return false;
}

bool Board::isKingInCheck(const std::string& color) const{
	if (color == "white")
		return isCheckOnSquare(whiteKingPosition, color);
	else if (color == "black")
		return isCheckOnSquare(blackKingPosition, color);
}

void Board::updateKingPosition(const Move& move, const std::string& color) {
	if (color == "white" && move.getStartSquare() == whiteKingPosition)
		whiteKingPosition = move.getEndSquare();
	if (color == "black" && move.getStartSquare() == blackKingPosition)
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
	if (isKingInCheck("white")) {
		checkmate = 1;
		for (const auto& move : legalMoves) {
			Piece* onEndTile = getPieceFromCoordinates(move->getEndSquare());
			makeMoveIfLegal(*move, "white");
			setBlackLegalMoves();
			if (!isKingInCheck("white")) {
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
	if (isKingInCheck("black")) {
		checkmate = 1;
		for (const auto& move : legalMoves) {
			Piece* onEndTile = getPieceFromCoordinates(move->getEndSquare());
			makeMoveIfLegal(*move, "black");
			setWhiteLegalMoves();
			if (!isKingInCheck("black")) {
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
	std::string color = player.getColor();
	Move move = player.getCurrentMoveObj();
	Piece* onEndTile = getPieceFromCoordinates(move.getEndSquare());	//remember piece in case of take back
	bool madeMove = makeMoveIfLegal(move, color);		
	if (color == "white")			
		setBlackLegalMoves();
	if (color == "black")
		setWhiteLegalMoves();
	if (madeMove && isKingInCheck(color)) {
		takeMoveBack(move, onEndTile);
		madeMove = 0;
	}
	setWhiteLegalMoves();
	setBlackLegalMoves();
	return madeMove;
}

bool Board::makeMoveIfLegal(const Move& move, const std::string& color) {
	Piece* pieceToMove = getPieceFromCoordinates(move.getStartSquare());
	if(pieceToMove && pieceToMove->getColor() == color)
		if (pieceToMove->isMoveLegal(*this, move)) {
			Tile* startTile = getTileFromCoordinates(move.getStartSquare());
			Tile* endTile = getTileFromCoordinates(move.getEndSquare());
			endTile->setPieceOnTile(pieceToMove);
			startTile->setPieceOnTile(nullptr);
			updateKingPosition(move, color);
			return true;
		}
	return false;
}

void Board::setWhiteLegalMoves() {
	whiteLegalMoves.clear();
	for(const auto& line : board)
		for(const auto& tile : line)
			if (tile->getPieceOnTile() != nullptr && tile->getPieceOnTile()->getColor() == "white")
				for (const auto& legalSquare : tile->getPieceOnTile()->legalMoves(*this, tile->getPosition())) {
					Move* move = new Move(tile->getPosition(), legalSquare);
					whiteLegalMoves.push_back(move);
				}
}

void Board::setBlackLegalMoves() {
	blackLegalMoves.clear();
	for (const auto& line : board)
		for (const auto& tile : line)
			if (tile->getPieceOnTile() != nullptr && tile->getPieceOnTile()->getColor() == "black")
				for (const auto& legalSquare : tile->getPieceOnTile()->legalMoves(*this, tile->getPosition())) {
					Move* move = new Move(tile->getPosition(), legalSquare);
					blackLegalMoves.push_back(move);
				}
}