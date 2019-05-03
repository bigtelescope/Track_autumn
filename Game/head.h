#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "objects.h"

#define SCREEN_WIDTH 1340
#define SCREEN_HIGHT 720

#define FAST_TIME(ARG) (ARG).asSeconds() * 100

#define EARTH_RADIUS 70
#define EARTH_X 670
#define EARTH_Y 360

int trashMove(Trash &, sf::Time &);

#endif
