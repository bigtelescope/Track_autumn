#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>

#include "objects.h"

#define SCREEN_WIDTH 	1340
#define SCREEN_HEIGHT 	720
#define ZERO			0

#define SPEED 			150

#define EARTH_RADIUS 	70
#define EARTH_X 		650
#define EARTH_Y 		350

#define STORE_SIZE 		64

#define FAST_TIME(ARG) (ARG).asSeconds() * SPEED

int satelliteMove			(Satellite &, sf::Clock &);
int trashMove				(Trash &, sf::Time &);
void bullet_move			(std::vector<Bullet> &, sf::Vector2i &, Satellite &, sf::Time &);

void storeCreate			(std::vector<Trash> &, sf::Texture &);
void bullet_storeCreate 	(std::vector<Bullet> &);

#endif
