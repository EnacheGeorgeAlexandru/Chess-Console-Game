#include "Tile.h"

Tile::Tile(Piece* PieceOnTileP) {
	PieceOnTile = PieceOnTileP;
}

void Tile::setPieceOnTile(Piece* PieceOnTileP){
	PieceOnTile = PieceOnTileP;
}

Piece* Tile::getPieceOnTile() const{
	return PieceOnTile;
}

bool Tile::isTileEmpty() const{
	return nullptr == PieceOnTile;
}

std::pair<int, int> Tile::getPosition() const {
	return position;
}

void Tile::setPosition(const std::pair<int, int>& positionP) {
	position = positionP;
}