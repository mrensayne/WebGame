#include "stdafx.h"
#include "Board.h"

Board::Board(int row, int col)
{
	rows = row;
	cols = col;
	std::vector<Square> temp;
	for (int y = 0; y < row; y++)
	{
		for (int x = 0; x < col; x++)
		{
			temp.push_back(Square());
		}
		squares.push_back(temp);
		temp.clear();
	}
}

Coord Board::getWrappedCoord(Coord start, Coord offset)
{
	int x = start.x;
	int y = start.y;
	int dist = std::abs(start.x - offset.x);
	if (start.x - offset.x > 0)
	{// We are moving to the left by dist
		for (int z = 0; z < dist; z++)
		{// Doing distance many times
			if (x > 0)
			{// if we aren't going over the edge of the map
				x--;
			}
			else
			{// we are going to go over the edge of the map so we wrap around
				x = cols - 1;
			}
		}
	}
	else
	{// we are not moving or moving to the right by dist
		for (int z = 0; z < dist; z++)
		{// Doing distance many times
			if (x < cols - 1)
			{// if we aren't going over the edge of the map
				x++;
			}
			else
			{// we are going to go over the edge of the map so we wrap around
				x = 0;
			}
		}
	}
	dist = std::abs(start.y - offset.y);
	if (start.y - offset.y > 0)
	{// We are moving up by dist
		for (int z = 0; z < dist; z++)
		{// Doing distance many times
			if (y > 0)
			{// if we aren't going over the edge of the map
				y--;
			}
			else
			{// we are going to go over the edge of the map so we wrap around
				y = rows - 1;
			}
		}
	}
	else
	{// we are not moving or moving down by dist
		for (int z = 0; z < dist; z++)
		{// Doing distance many times
			if (y < rows - 1)
			{// if we aren't going over the edge of the map
				y++;
			}
			else
			{// we are going to go over the edge of the map so we wrap around
				y = 0;
			}
		}
	}
	return Coord(x, y);
}

Coord Board::findLocOfEntity(Entity& entity)
{
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			if (squares[y][x].getEntity()->getID() == entity.getID())
			{
				return Coord(y, x);
			}
		}
	}
}

void Board::moveEntity(Entity& entity, Coord offset)
{
	auto itr = std::find(entities.begin(), entities.end(), entity);
	if (itr != entities.end())
	{//We found the entity on the board		
		Coord EntityLocation = findLocOfEntity(entity);
		Coord NewEntityLocation = getWrappedCoord(EntityLocation, NewEntityLocation);
		squares[EntityLocation.y][EntityLocation.x].removeEntity();
		squares[NewEntityLocation.y][NewEntityLocation.x].setEntity(entity);
	}
}