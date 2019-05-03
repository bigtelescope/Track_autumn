#include "heads.h"
#include <iostream>
#include <vector>

int main()
{
	Man John(0, 0, 14, "rectangle", 65);

	Man Bob(15, 92, 14, "circle", 23);

	Horse mr_horse(10, 20, 99, "lol", "slozhno");

	std::vector<Man> source;
	source.push_back(John);
	source.push_back(Bob);

	for(int i(0); i < source.size(); i++)
		source[i].ShowObj();

	return 0;
}