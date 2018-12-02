#pragma once
#ifndef SQUARE_H
#define SQUARE_H
#include "Entity.hpp"
#include <memory>

class Square
{
public:
	bool isEmpty{ true };
	std::shared_ptr<Entity> entity;
	Square() {};
	void removeEntity() {
		isEmpty = true;
		entity = nullptr;
	}
	void setEntity(Entity& entity)
	{
		this->entity = std::make_shared<Entity> (entity);
	}
	std::shared_ptr<Entity> getEntity() { return entity; }
	bool isEmpty() { return isEmpty; }
};

#endif // !SQUARE_H
