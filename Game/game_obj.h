#ifndef GAME_OBJ_H
#define GAME_OBJ_H

#include <iostream>
#include <SFML/Graphics.hpp>

#define ALIVE 1
#define DEAD  0

class GameObject
{
	protected :

		int x_null;
		int y_null;
		int is_alive;

	public :

		GameObject(int x, int y);
		~GameObject();

		const int 	getX();
		const int 	getY();

		const int 	isAlive();
		void 		killObject();
};

#endif