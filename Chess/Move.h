#pragma once
#include<iostream>

class Move
{
	std::pair<int, int> startSquare;
	std::pair<int, int> endSquare;
	std::pair<std::pair<int, int>, std::pair<int, int>> fullMove;
public:
	explicit Move(const int&, const int&, const int&, const int&);
	explicit Move(const std::pair<int, int>&, const std::pair<int, int>&);
	std::pair<int, int> getStartSquare() const;
	std::pair<int, int> getEndSquare() const;
	std::pair<std::pair<int, int>, std::pair<int, int>> getFullMove() const;
};

