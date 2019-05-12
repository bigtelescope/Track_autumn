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

#define SPEED 			100

#define EARTH_RADIUS 	70
#define EARTH_X 		670
#define EARTH_Y 		360

#define STORE_SIZE 		64

#define FAST_TIME(ARG) (ARG).asSeconds() * SPEED

int trashMove		(Trash &, sf::Time &);
void storeCreate	(std::vector<Trash> &);

#endif
