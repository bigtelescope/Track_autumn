#include "head.h"

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

void bullet_storeCreate (std::vector<Bullet> & bullet_vector)
{
	for(int i = 0; i < STORE_SIZE; i++)
	{
		Bullet bullet(0, 0);
		bullet_vector.push_back(bullet);
	}
}