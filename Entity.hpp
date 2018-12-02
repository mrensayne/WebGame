#pragma once
#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <string>
#include <vector>
#include "Square.h"
#include "Coord.hpp"

enum class EntityType { PLAYER1, PLAYER2, ENEMY };
class Entity
{
protected:
	int EntityID{ 0 };
	char sprite;
	Coord loc;
public:
	Entity() {

	}
	char getSprite() { return sprite; }
	int getID() { return EntityID; }
	const bool operator ==(Entity& ent)
	{
		if (this->EntityID == ent.EntityID)
			return true;
		return false;
	}
};
#endif // !ENTITY_H

class Player : public Entity
{
public:
	Player(int ID, char sprite, Coord loc) {
		this->EntityID = ID;
		this->loc = loc;
		this->sprite = sprite;
	};
};

class Enemy : public Entity
{
	Enemy(int ID, char sprite, Coord loc)
	{
		this->EntityID = ID;
		this->loc = loc;
		this->sprite = sprite;
	}
};
