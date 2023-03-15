#include "Player.h"

using namespace Chess;

Player::Player(PieceColor color) {
	this->color = color;
	currentMovePtr = new Move;
}

void Player::setColor(PieceColor colorP) {
	color = colorP;
}

PieceColor Player::getColor() const{
	return color;
}

void Player::convertNotationsToCoordinates(const std::string& start, const std::string& end) {
	int startLine, startColumn, endLine, endColumn;									//converts a3 to <5,0>  because
	startLine = 8 - (start[1] - '0');												//1.user gives column first, line second
	startColumn = start[0] - 97;													//2.user's first line is board's last
	endLine = 8 - (end[1] - '0');													// '3' to 5 '2' to 6 etc.
	endColumn = end[0] - 97;														// a to 0, b to 1 etc.
	currentMovePtr->setStartSquare(startLine, startColumn);
	currentMovePtr->setEndSquare(endLine, endColumn);
}
void Player::inputMove() {
	std::string start, end;
	std::cout << "from: ";
	std::cin >> start;
	std::cout << "to: ";
	std::cin >> end;
	convertNotationsToCoordinates(start, end);
}

Move* Player::getCurrentMoveObj() const {
	return currentMovePtr;
}

Player::~Player() {
	delete currentMovePtr;
}