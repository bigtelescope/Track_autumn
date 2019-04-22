#include <iostream>
#include <memory>
#include <vector>

#include "proxy.h"

using namespace std;

class Yo
{
	public :
	int field;

	Yo(int arg)
	{
		field = arg;
	}

	void Show()
	{
		cout << "field = " << field << endl;
	}
};

int main()
{
	proxy<Yo> obj(new Yo(1));
	{
		//creating of two addition objects referring to Yo object
		proxy<Yo> one(obj);
		proxy<Yo> two = one;

		//displaying of links number
		cout << "1) counter = " << obj.amount() << endl;
	}
	//displaying of links number
	cout << "2) counter = " << obj.amount() << endl;

	//testing of * operator
	Yo value = *obj;
	cout << "dereference = " << value.field << endl;

	//one more test
	(*obj).Show();

	//creating one more referring object who edits data of Yo
	proxy<Yo> three;
	three = obj;
	(three->field)++;

	cout << "updated field = " << three->field << endl;
	cout << "old field = " << obj->field << endl;

	return 0;
}
