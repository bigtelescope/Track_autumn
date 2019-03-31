#include "Vector.h"

int main()
{
	MyVector<int> b(2);
	std::cin >> b;
	MyVector<int> a(2);
	a = b / (-1);
	MyVector<int> c(2);
	c = 3 * b + a;
	std::cout << c;
	return 0;
}