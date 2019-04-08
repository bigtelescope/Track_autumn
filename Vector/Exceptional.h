#ifndef STRANGE_EXEPT_H
#define STRANGE_EXEPT_H

#include <iostream>
#include <fstream>

using namespace std;

/*! Throwing exception in a case of a primary error*/
#define FTHROW(ERR, MESSAGE)		\
		throw new YourEx(ERR, MESSAGE, nullptr, __LINE__, __FILE__, __FUNCTION__)

/*! Throwing exception in a case of catched exception*/
#define THROW(ERR, MESSAGE, PTR1)	\
		(PTR1)->WriteLog();			\
		throw new YourEx(ERR, MESSAGE, PTR1, __LINE__, __FILE__, __FUNCTION__)

enum ERRORS
{
	FILE_IS_NOT_OPENED,
	DIFFERENT_TYPES,
	INVALID_ARGUMENT,
	MEM_ALLOC_ERROR,
	ZERO_DIVIDING,
	UNKNOWN_ERROR
};


class YourEx
{
	private:
		int		 	error;		// Number
		int 		line;		// Line of an error
		string		file;		// File of an error
		string		function;	// Function with an error
		string		problem;	// Your description of an error
		YourEx*		prev;		// Previous YourEx object
		fstream		log;		// File for writing


	public:
		YourEx();
		~YourEx();

		//This one is used in throwing
		YourEx(int err, string message, YourEx * ptr,\
					int lin, string doc, string func);

		void WriteLog();
};

YourEx::YourEx() :
	error 		(0),
	line		(0),
	file		(""),
	function 	(""),
	problem 	(""),
	prev		(nullptr)
{}

YourEx::~YourEx()
{}

YourEx::YourEx(int err, string message, YourEx * ptr,\
					int lin, string doc, string func) :
	error 		(err),
	line		(lin),
	file		(doc),
	function 	(func),
	problem 	(message),
	prev		(ptr)
{}

void YourEx::WriteLog()
{
	if(prev != nullptr)
	{
		log.open("Log file.txt", fstream::app);
		log << "----From function : [" 	<< prev->function 	<< "] : ";
		log << "string [" 				<< prev->line 		<< "] : ";
		log << "file [" 				<< prev->file 		<< "]----" << endl;
	}
	else
	{
		log.open("Log file.txt", fstream::out);
		log << "The last trouble was at : [" << __TIME__ << "]" << endl << endl;
	}

	log << "File 	 : 	 [" 	<< file 	<< "]" 	<< endl;
	log << "Function : 	 [" 	<< function << "]" 	<< endl;
	log << "Line 	 :	 [" 	<< line 	<< "]"	<< endl;
	log << "Problem  :	 [" 	<< error 	<< "]" 	<< endl;
	log << "Description :	 [" << problem 	<< "]" 	<< endl << endl;
	log.close();

	return;
}

#endif
