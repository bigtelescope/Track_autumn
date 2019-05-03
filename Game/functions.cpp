#include "head.h"

int trashMove(Trash & trash, sf::Time & time)
{
	if(abs(trash.getCircleX() - EARTH_X) < EARTH_RADIUS &&
	   abs(trash.getCircleY() - EARTH_Y) < EARTH_RADIUS)
	{
		trash.killObject();
		return 0;
	}

	int delta_x = EARTH_X - trash.getX();
	int delta_y = EARTH_Y - trash.getY();

	float radius = sqrt(delta_x * delta_x + delta_y * delta_y);

	trash.getCircle().setPosition(trash.getX() + (delta_x / radius) * FAST_TIME(time),
								  trash.getY() + (delta_y / radius) * FAST_TIME(time));
	
	return 0;
}