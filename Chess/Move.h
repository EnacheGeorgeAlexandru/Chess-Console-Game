#pragma once
#include<iostream>

namespace Chess {
	class Move
	{
		std::pair<int8_t, int8_t> startSquare;
		std::pair<int8_t, int8_t> endSquare;
	public:
		explicit Move(const int&, const int&, const int&, const int&);
		explicit Move(const std::pair<int, int>&, const std::pair<int, int>&);
		std::pair<int, int> getStartSquare() const;
		std::pair<int, int> getEndSquare() const;
	};
}

