#include "Tile.h"

using namespace Chess;

Tile::Tile(Pieces::Piece* PieceOnTileP) {
	PieceOnTile = PieceOnTileP;
}

void Tile::setPieceOnTile(Pieces::Piece* PieceOnTileP){
	PieceOnTile = PieceOnTileP;
}

Pieces::Piece* Tile::getPieceOnTile() const{
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