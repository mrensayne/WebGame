#pragma once
#ifndef COORD_HPP
#define COORD_HPP

struct Coord {
	int y{ 0 };
	int x{ 0 };
	Coord() {};
	Coord(int row, int col)
	{
		this->y = row;
		this->x = col;
	}
};

#endif // !COORD_HPP
