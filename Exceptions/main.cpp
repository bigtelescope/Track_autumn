#include <iostream>
#include "Exceptional.h"

using namespace std;

void Surface();
void Under_Surface();
void Deep();

int main()
{
	try
	{
		Surface();
	}
	catch(YourEx * ex)
	{
		ex->WriteLog();
	}

	return 0;
}

void Deep()
{
	cout << "Trying to do smth before throw in Deep()" << endl;

	//Trying to create a problem for myself:)
	#ifndef False
	#define False true
	if(False)
	{
		cout << "Jumping away from Deep() because of error" << endl;
		FTHROW(UNKNOWN_ERROR, "omg what the fuck, false is true");
	}
	#endif
	
	cout << "I'm trying to do smth after throw in Deep()" << endl;
}

void Under_Surface()
{
	cout << "Have come to Under_Surface()" << endl;
	try
	{
		Deep();
	}
	catch(YourEx * ex)
	{
		ex->WriteLog();
		cout << "Jumping away from Under_Surface() because of error" << endl;
		THROW(UNKNOWN_ERROR, "Deutschland, Deutschland über alles", ex);
	}
	cout << "Have come away from Under_Surface()" << endl;
}

void Surface()
{
	cout << "Have come to Surface()" << endl;
	try
	{
		Under_Surface();
	}
	catch(YourEx * ex)
	{
		ex->WriteLog();
		cout << "Jumping away from Surface() because of error" << endl;
		THROW(UNKNOWN_ERROR, "Нас вырастил Сталин — на верность народу", ex);
	}
	cout << "Have come away from Surface()" << endl;
}