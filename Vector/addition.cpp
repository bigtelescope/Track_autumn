#include "Vector.h"

void Deep()
{
	try
	{
		MyVector<int> b(2);
		std::cin >> b;
		MyVector<int> a(2);
		a = b / (-1);
		MyVector<int> c(2);
		c = b - 2 * a;
		std::cout << c[3] << endl;;
	} 
	catch(YourEx * ex)
	{
		THROW(UNKNOWN_ERROR, "something wrong:(", ex);
	}
	return;
}

void pew()
{
	try
	{
		std::cout << "First attempt\n";
		Deep();
		std::cout << "Second attempt\n";
	}
	catch(YourEx * ex)
	{
		THROW(UNKNOWN_ERROR, "subscribe to @bigtelescope", ex);
	}
	return;
}
