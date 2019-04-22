#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>

#define NO_ELEM 0

template <typename ObjT>
class proxy
{
	private :
		ObjT*		object;
		static int 	counter;

	public :
		proxy	();
		proxy	(ObjT* obj);
		proxy	(const proxy<ObjT> &);
		~proxy	();

		proxy<ObjT>& 		operator = (const proxy<ObjT> &);
		const ObjT& 		operator * () const;
		ObjT& 				operator * ();
		const ObjT*			operator -> () const;
		ObjT*				operator -> ();

		int 				amount();
};

template <typename ObjT>
int proxy<ObjT>::counter = NO_ELEM;

template <typename ObjT>
proxy<ObjT>::proxy(const proxy<ObjT>& arg)
{
	object = arg.object;
	counter++;
}

template <typename ObjT>
proxy<ObjT>::proxy()
{
	object = nullptr;
}

template <typename ObjT>
proxy<ObjT>::proxy(ObjT* obj)
{
	counter++;
	object = obj;
}

template <typename ObjT>
proxy<ObjT>::~proxy()
{
	if(!counter)
		delete object;
	else
		counter--;
}

template <typename ObjT>
proxy<ObjT>& proxy<ObjT>::operator = (const proxy<ObjT> & rvalue)
{
	this->object = rvalue.object;
	counter++;

	return *this;
}

template <typename ObjT>
const ObjT& proxy<ObjT>::operator * () const
{
	std::cout << std::endl << "i'm about to follow the link [const *]" << std::endl;

	return *object;
}

template <typename ObjT>
ObjT& proxy<ObjT>::operator * ()
{
	std::cout << std::endl << "i'm about to follow the link [*]" << std::endl;

	return *object;
}

template <typename ObjT>
const ObjT* proxy<ObjT>::operator -> () const
{
	std::cout << std::endl << "i'm about to follow the pointer [const ->]" << std::endl;

	return object;
}

template <typename ObjT>
ObjT* proxy<ObjT>::operator -> ()
{
	std::cout << std::endl << "i'm about to follow the pointer [->]" << std::endl;

	return object;
}

template <typename ObjT>
int proxy<ObjT>::amount()
{
	return counter;
}

#endif
