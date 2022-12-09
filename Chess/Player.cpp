#include "Player.h"

using namespace Chess;

void Player::setColor(const std::string&colorP) {
	color = colorP;
}

std::string Player::getColor() const{
	return color;
}

void Player::convertNotationsToCoordinates(const std::string& start, const std::string& end) {//converts a3 to <5,0>  because
	currentMove.first.first = 8 - (start[1] - '0');                             //1.user gives column first, line second
	currentMove.first.second = start[0] - 97;                                   //2.user's first line is board's last
	currentMove.second.first = 8 - (end[1] - '0');   // '3' to 5 '2' to 6 etc.
	currentMove.second.second = end[0] - 97;         // a to 0, b to 1 etc.
	currentMovePtr = new Move(currentMove.first.first, currentMove.first.second, currentMove.second.first, currentMove.second.second);
}
void Player::inputMove() {
	std::string start, end;
	std::cout << "from: ";
	std::cin >> start;
	std::cout << "to: ";
	std::cin >> end;
	convertNotationsToCoordinates(start, end);
}
std::pair<std::pair<int, int>, std::pair<int, int>> Player::getCurrentMove() const{
	return currentMove;
}

Move Player::getCurrentMoveObj() const {
	return *currentMovePtr;
}