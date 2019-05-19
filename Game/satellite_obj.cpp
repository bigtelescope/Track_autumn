#ifndef SATELLITE_METHODS_H
#define SATELLITE_METHODS_H

#include "satellite.h"
#include "game_obj.h"

Satellite::Satellite(int x, int y) :
	GameObject	(x, y),
	orbit 		(START_ORBIT),
	delta 		(START_DELTA),
	beta 		(START_BETA)

{
	circle = sf::CircleShape(SATELLITE_RADIUS);
	circle.setFillColor(sf::Color::Blue);
	circle.setPosition(x_null - SATELLITE_RADIUS, y_null - SATELLITE_RADIUS);
}

sf::CircleShape & Satellite::getCircle()
{
	return circle;
}

const int Satellite::getCircleX() const
{
	return circle.getPosition().x;
}

const int Satellite::getCircleY() const
{
	return circle.getPosition().y;
}

const float Satellite::showOrbit() const
{
	return orbit;
}

float & Satellite::getOrbit()
{
	return orbit;
}

const float Satellite::showDelta() const
{
	return 	delta;
}

float & Satellite::getDelta()
{
	return delta;
}

const float Satellite::showBeta() const
{
	return 	beta;
}

float & Satellite::getBeta()
{
	return beta;
}

Satellite::~Satellite()
{
	//What should we do here?
}

#endif