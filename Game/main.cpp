#include "head.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HIGHT), "Work mf");
	sf::Clock clock;
	sf::Time time;

	std::vector<Trash> trash_vector;

	Trash trash1(1340,590);
	Trash trash2(0, 0);
	Trash trash3(1340, 90);
	Trash trash4(310, 10);

	trash_vector.push_back(trash1);
	trash_vector.push_back(trash2);
	trash_vector.push_back(trash3);
	trash_vector.push_back(trash4);

	sf::CircleShape earth(EARTH_RADIUS);
	earth.setFillColor(sf::Color::Green);
	earth.setPosition(EARTH_X - EARTH_RADIUS, EARTH_Y - EARTH_RADIUS);

	while(window.isOpen())
	{
		sf::Event main_event;

		time = clock.getElapsedTime();

		for(int i(0); i < trash_vector.size(); i++)
			trashMove(trash_vector[i], time);
		
		while(window.pollEvent(main_event))
		{
			if(main_event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		window.draw(earth);

		//	its acceptably to delete 31 and 32 strings and change "&& trash_vector[i].isAlive()"
		//	to "trashMove(trash_vector[i], time)"
		//
		//  some kind of optimization:)
		for(int i(0); i < trash_vector.size() && trash_vector[i].isAlive(); i++)
				window.draw(trash_vector[i].getCircle());

		window.display();
	}
	return 0;
}