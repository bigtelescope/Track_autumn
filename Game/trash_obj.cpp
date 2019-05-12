#ifndef TRASH_METHODS_H
#define TRASH_METHODS_H

#include "trash.h"
#include "game_obj.h"

sf::CircleShape & Trash::getCircle()
{
	return circle;
}

const int Trash::getCircleX()
{
	return circle.getPosition().x;
}

const int Trash::getCircleY()
{
	return circle.getPosition().y;
}

Trash::Trash(int x, int y) :
	GameObject(x, y)
{
	circle = sf::CircleShape(TRASH_RADIUS);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(x_null - TRASH_RADIUS, y_null - TRASH_RADIUS);
}

Trash::~Trash()
{
	//What should we do here?
}

#endif