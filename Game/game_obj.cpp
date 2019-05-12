#ifndef GAME_OBJ_METHODS_H
#define GAME_OBJ_METHODS_H

#include "game_obj.h"

GameObject::GameObject(int x, int y) :
	x_null		(x),
	y_null 		(y),
	is_alive	(ALIVE)
{}

GameObject::~GameObject()
{
	x_null 		= DEAD;
	x_null		= DEAD;
	is_alive 	= DEAD;
}

const int GameObject::getX()
{
	return x_null;
}

const int GameObject::getY()
{
	return y_null;
}

const int GameObject::isAlive()
{
	return is_alive;
}

void GameObject::killObject()
{
	is_alive = DEAD;
}

#endif