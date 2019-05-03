#ifndef OBJECTS_H
#define OBJECTS_H

#include <iostream>
#include <SFML/Graphics.hpp>

#define ALIVE 1
#define DEAD  0

#define TRASH_RADIUS 20

class GameObject
{
	protected :

		int x_null;
		int y_null;
		int is_alive;

	public :

		GameObject(int x, int y) :
			x_null		(x),
			y_null 		(y),
			is_alive	(ALIVE)
		{}

		const int getX()
		{
			return x_null;
		}

		const int getY()
		{
			return y_null;
		}

		const int isAlive()
		{
			return is_alive;
		}

		void killObject()
		{
			is_alive = DEAD;
		}
};

class Trash : public GameObject
{
	private :
		sf::CircleShape circle;

	public :

		Trash(int x, int y) :
			GameObject(x, y)
		{
			circle = sf::CircleShape(TRASH_RADIUS);
			circle.setFillColor(sf::Color::Red);
			circle.setPosition(x_null - TRASH_RADIUS, y_null - TRASH_RADIUS);
		}

		sf::CircleShape & getCircle()
		{
			return circle;
		}

		const int getCircleX()
		{
			return circle.getPosition().x;
		}

		const int getCircleY()
		{
			return circle.getPosition().y;
		}

};

//  its necessary to allow separated definition and 
//	declaration of class methods!!!
/*
Trash::Trash(int x, int y) :
	GameObject(x, y)
{
	circle = sf::CircleShape(TRASH_RADIUS);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(x_null - TRASH_RADIUS, y_null - TRASH_RADIUS);
}
*/

/*
sf::CircleShape & Trash::getCircle()
{
	return circle;
}
*/
#endif
