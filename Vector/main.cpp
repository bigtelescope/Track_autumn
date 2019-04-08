#include "Vector.h"
#include "addition.cpp"

using namespace std;

void pew();	 // One calls Deep()
void Deep(); // Here is a mistake

int main()
{
	try
	{
		pew();
	}
	catch(YourEx * ex)
	{
		ex->WriteLog();
	}
	return 0;
}
