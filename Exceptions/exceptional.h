#include <iostream>
#include <fstream>

using namespace std;

#define FTHROW(ERR, MESSAGE)\
		throw new YourEx(ERR, MESSAGE, nullptr, __LINE__, __FILE__, __FUNCTION__)

#define THROW(ERR, MESSAGE, PTR1)\
		throw new YourEx(ERR, MESSAGE, PTR1, __LINE__, __FILE__, __FUNCTION__)

enum ERRORS
{
	FILE_IS_NOT_OPENED,
	INVALID_ARGUMENT,
	MEM_ALLOC_ERROR,
	ZERO_DIVIDING,
	SYNTAX_ERROR,
	ACCESS_ERROR,
	UNKNOWN_ERROR
};


class YourEx
{
	private:
		int		 	error;
		int 		line;
		string		file;
		string		function;
		string		problem;
		YourEx*		next;
		fstream		log;

	public:
		YourEx();
		~YourEx();
		YourEx(int error, string message, YourEx * ptr,\
				int lin, string doc, string func);

		void WriteLog();
};

YourEx::YourEx() :
	error 		(0),
	line		(17),
	file		(""),
	function 	(""),
	problem 	(""),
	next		(nullptr)
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
	next		(ptr)
{}

void YourEx::WriteLog()
{
	if(next != nullptr)
	{	log.open("Log file.txt", fstream::app);
		log << "----From function : [" << next->function << "] : ";
		log << "string [" << next->line << "] : ";
		log << "file [" << next->file << "]----" << endl;
	}
	else
	{
		log.open("Log file.txt", fstream::out);
		log << "The last trouble was at : [" << __TIME__ << "]" << endl << endl;
	}

	log << "File 	 : [" << file << "]" << endl;
	log << "Function : [" << function << "]" << endl;
	log << "Line 	 : [" << line << "]" << endl;
	log << "Problem  : [" << problem << "]" << endl << endl;
	log.close();

	return;
}