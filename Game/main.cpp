#include "head.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Work mf");
	sf::Clock clock;
	sf::Time time;

	std::vector<Trash> trash_vector;
	storeCreate(trash_vector);

	int alive_numb = 0;

	sf::CircleShape earth(EARTH_RADIUS);
	earth.setFillColor(sf::Color::Green);
	earth.setPosition(EARTH_X - EARTH_RADIUS, EARTH_Y - EARTH_RADIUS);

	while(window.isOpen())
	{
		sf::Event main_event;

		while(window.pollEvent(main_event))
		{
			if(main_event.type == sf::Event::Closed)
				window.close();
		}

		time = clock.getElapsedTime();

		trashMove(trash_vector[alive_numb], time);

		window.clear(sf::Color::White);
		window.draw(earth);

		if(trash_vector[alive_numb].isAlive())
			window.draw(trash_vector[alive_numb].getCircle());
		else
		{
			alive_numb = (alive_numb + 1) % STORE_SIZE;
			clock.restart();
		}

		window.display();
	}
	return 0;
}