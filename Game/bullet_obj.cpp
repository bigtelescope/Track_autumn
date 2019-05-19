#ifndef BULLET_METHODS_H
#define BULLET_METHODS_H

#include "bullet.h"
#include "game_obj.h"

sf::Sprite & Bullet::getCircle ()
{
	return circle;
}

Bullet::Bullet(int x, int y) : 
	GameObject 		(x, y)
{
	//sf::Texture texture;
	//texture.loadFromFile("qiwi.png");
	//circle.setTexture(texture, false);
	circle.setPosition(x, y);
}

Bullet::~Bullet()
{
	//What should we do here?
}

#endif