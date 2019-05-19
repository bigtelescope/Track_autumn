#include "head.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Work mf");
	sf::Clock clock, clock_sat, clock_bullet;
	sf::Time time;
	sf::Vector2i mousePosition;

	//creating vector of trash
	std::vector<Trash> trash_vector;
	storeCreate(trash_vector);

	//creating vector of bullets
	//std::vector<Bullet> bullet_vector;
	//bullet_storeCreate(bullet_vector);


	int alive_numb = 0;

	//earth creating
	sf::CircleShape earth(EARTH_RADIUS);
	earth.setFillColor(sf::Color::Green);
	earth.setPosition(EARTH_X - EARTH_RADIUS, EARTH_Y - EARTH_RADIUS);

	//satellite creating
	Satellite satellite(SATELLITE_START_X, SATELLITE_START_Y);

	sf::Event main_event;

	while(window.isOpen())
	{

		time = clock.getElapsedTime();
		//time_bullet = clock_bullet.getElapsedTime();

		while(window.pollEvent(main_event))
			switch(main_event.type)
			{
				case sf::Event::Closed :
					window.close();
					break;

				case sf::Event::KeyPressed :
				{
					if(main_event.key.code == sf::Keyboard::Up)
					{
						INCREASE_DELTA(satellite.getDelta());
						INCREASE_ORBIT(satellite.getOrbit());
					}

					if(main_event.key.code == sf::Keyboard::Down)
					{
						DECREASE_DELTA(satellite.getDelta());
						DECREASE_ORBIT(satellite.getOrbit());
					}

					break;
				}
			}

		trashMove(trash_vector[alive_numb], time);
		satelliteMove(satellite, clock_sat);

		window.clear(sf::Color::White);
		

		if(trash_vector[alive_numb].isAlive())
			window.draw(trash_vector[alive_numb].getCircle());
		else
		{
			alive_numb = (alive_numb + 1) % STORE_SIZE;//move to the beginning
			clock.restart();
		}
		window.draw(earth);
		window.draw(satellite.getCircle());
		window.display();
	}
	return 0;
}