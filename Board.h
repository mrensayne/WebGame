#pragma once
#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Square.h"
#include "Entity.hpp"
#include <memory>
#include "Coord.hpp"

class Board
{
private:
	Coord findLocOfEntity(Entity& entity);

public:
	int rows{ 0 };
	int cols{ 0 };
	std::vector<std::vector<Square>> squares;
	std::vector<std::shared_ptr<Entity>> entities;
	Board(int row, int col);
	Coord getWrappedCoord(Coord start, Coord offset);
	void moveEntity(Entity& EntityToMove, Coord offset);
};

#endif // !BOARD_H
