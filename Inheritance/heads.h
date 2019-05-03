#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>

class Game_Object
{
	private :
		int 		x;
		int 		y;
		double 		speed;
		std::string 	figure;

	public :
		Game_Object():
			x 	(0),
			y 	(0),
			speed 	(0),
			figure 	("\n")
		{}

		Game_Object(int x_, int y_, double vel, std::string shape):
			x 	(x_),
			y 	(y_),
			speed	(vel),
			figure	(shape)
		{std::cout << "Game_Object constructor" << std::endl;}

		virtual void ShowObj()
		{
			std::cout << "X = " << x << ", Y = " << y << std::endl;
			std::cout << "Speed = " << speed << std::endl;
			std::cout << "Figure = " << figure << std::endl;
		}		
};


class Man : Game_Object
{
	private :
		int 	health;

	public :
		Man(int x_, int y_, double vel, std::string shape, int health_):
			Game_Object	(x_, y_, vel, shape),
			health 		(health_)
		{std::cout << "A Man constructor" << std::endl << std::endl;}

		void ShowObj() override
		{
			Game_Object::ShowObj();
			std::cout << "A man's health is " << health;
			std::cout << std::endl << std::endl;
		}		
};

class Horse : Game_Object
{
	private :
		std::string color;

	public :
		Horse(int x_, int y_, double vel, std::string shape, std::string color_):
			Game_Object	(x_, y_, vel, shape),
			color 		(color_)
		{std::cout << "A Horse constructor" << std::endl << std::endl;}

		void ShowObj() override
		{
			Game_Object::ShowObj();
			std::cout << "A horse's color is " << color;
			std::cout << std::endl << std::endl;
		}	
};


#endif
