#ifndef TRASH_H
#define TRASH_H

#include "game_obj.h"

#define TRASH_RADIUS 20

class Trash : public GameObject
{
	private :
		sf::CircleShape circle;
		sf::Texture 	texture;
		sf::Sprite		sprite;

	public :

		Trash 	(int x, int y);
		~Trash 	();

		sf::CircleShape & 	getCircle 	();
		
		const int 			getCircleX 	();
		const int 			getCircleY 	();
};

#endif
