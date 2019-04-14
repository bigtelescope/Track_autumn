#include "heads.h"
#include <iostream>

int main()
{
	Game_Object Obj;
	Obj.ShowObj();

	Man John(0, 0, 14, "rectangle", 65);
	John.ShowObj();

	Man Bob(15, 92, 14, "circle", 23);
	Bob.ShowObj();

	return 0;
}