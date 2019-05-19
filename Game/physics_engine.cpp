#include "head.h"

int satelliteMove(Satellite & satellite, sf::Clock & clock)
{
	if(clock.getElapsedTime().asMilliseconds() > DELAY)
	{
		float angle = asin(satellite.showDelta() / satellite.showOrbit());
		
		float jump = EXTEND_JUMP * satellite.showDelta() * cos(angle);

		float delta_x = - jump * sin(angle + satellite.showBeta());
		float delta_y = - jump * cos(angle + satellite.showBeta());

		satellite.getBeta() += DOUBLE_ANGLE(angle);

		satellite.getCircle().setPosition(satellite.getX_Null() + delta_x,
										  satellite.getY_Null() + delta_y);

		clock.restart();
	}

	return 0;
}

int trashMove(Trash & trash, sf::Time & time)
{
	if(abs(trash.getCircleX() + TRASH_RADIUS - EARTH_X) < EARTH_RADIUS &&
	   abs(trash.getCircleY() + TRASH_RADIUS - EARTH_Y) < EARTH_RADIUS)
	{
		trash.killObject();
		return 0;
	}

	int delta_x = EARTH_X - trash.getX_Null();
	int delta_y = EARTH_Y - trash.getY_Null();

	float radius = sqrt(delta_x * delta_x + delta_y * delta_y);

	trash.getCircle().setPosition(trash.getX_Null() + (delta_x / radius) * FAST_TIME(time),
								  trash.getY_Null() + (delta_y / radius) * FAST_TIME(time));

	return 0;
}

void bullet_move (std::vector<Bullet> & bullet_vector, sf::Vector2i & mousePosition, 
				  Satellite & satellite, sf::Time & time_bullet)
{

}