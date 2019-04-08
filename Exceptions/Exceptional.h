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
		YourEx*		prev;
		fstream		log;


	public:
		YourEx();
		~YourEx();
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
	{	log.open("Log file.txt", fstream::app);
		log << "----From function : [" << prev->function << "] : ";
		log << "string [" << prev->line << "] : ";
		log << "file [" << prev->file << "]----" << endl;
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
