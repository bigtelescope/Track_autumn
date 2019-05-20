#include "head.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Work mf");

	sf::Clock clock;
	sf::Clock clock_sat;
	sf::Clock clock_bullet;

	sf::Time time;

	sf::Event main_event;

	sf::Vector2i mousePosition;

	//temporary volatile
	int alive_numb = 0;

	sf::Texture texture;
	texture.loadFromFile("pictures/meteor.png");

	//creating vector of trash
	std::vector<Trash> trash_vector;
	storeCreate(trash_vector, texture);
/*
	for(int j = 0; j < trash_vector.size(); j++)
		trash_vector[j].getSprite().setTexture(texture);
*/

	//creating vector of bullets
	//std::vector<Bullet> bullet_vector;
	//bullet_storeCreate(bullet_vector);

	// Satellite creating
	Satellite satellite(SATELLITE_START_X, SATELLITE_START_Y, SCALE);

	// Earth creating
	Earth earth(EARTH_SPRITE_X, EARTH_SPRITE_Y, EARTH_SCALE);

	sf::Texture background_texture;
	sf::Sprite 	background;

	background_texture.loadFromFile("pictures/background.png");
  	
  	sf::Vector2u texture_size = background_texture.getSize(); //Get size of texture.
    sf::Vector2u window_size  = window.getSize();             //Get size of window.

    float scale_x = (float)window_size.x / texture_size.x;	  //Calculate scale.
    float scale_y = (float)window_size.y / texture_size.y;    //Calculate scale.

    background.setTexture(background_texture);
    background.setScale	 (scale_x, scale_y);

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
		window.draw(background);
		
		if(trash_vector[alive_numb].isAlive())
			window.draw(trash_vector[alive_numb].getSprite());
		else
		{
			alive_numb = (alive_numb + 1) % STORE_SIZE;//move to the beginning
			clock.restart();
		}

		window.draw(satellite.getSprite());
		window.draw(earth.getSprite());

		window.display();
	}
	return 0;
}