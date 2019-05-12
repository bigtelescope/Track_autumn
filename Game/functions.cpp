#include "head.h"

int trashMove(Trash & trash, sf::Time & time)
{
	if(abs(trash.getCircleX() + TRASH_RADIUS - EARTH_X) < EARTH_RADIUS &&
	   abs(trash.getCircleY() + TRASH_RADIUS - EARTH_Y) < EARTH_RADIUS)
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

void storeCreate(std::vector<Trash> & vector)
{
	for(int i = 0; i < STORE_SIZE / 4; i++)
	{
		Trash trash_one(rand()%SCREEN_WIDTH, ZERO		  		);
		Trash trash_two(rand()%SCREEN_WIDTH, SCREEN_HEIGHT 		);

		Trash trash_three(ZERO,				 rand()%SCREEN_HEIGHT);
		Trash trash_four (SCREEN_WIDTH,		 rand()%SCREEN_HEIGHT);

		vector.push_back(trash_one);
		vector.push_back(trash_two);
		vector.push_back(trash_three);
		vector.push_back(trash_four);
	}
}