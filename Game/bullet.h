#ifndef BULLET_H
#define BULLET_H

#include "game_obj.h"

#define BULLET_RADIUS 10

class Bullet : public GameObject
{
	private :

		sf::Sprite circle;
		
	public :

		sf::Sprite & getCircle ();
		Bullet 	(int x, int y);
		~Bullet 	();
};

#endif