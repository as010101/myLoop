#include <iostream>
#include "Logger.h"

using namespace std;

Logger::Logger(const char * fileName,int line):impl(fileName,line) //Logger的构造  会对impl初始化，该初始化需要进一步调用imp的构造函数
{}
 
Logger::Imp::Imp(const char * fileName,int line) :line_(line),fileName_(fileName)//imp的构造函数
{
}

int main()
{
	const char *p = "ssssssss";
	Logger log(p,5);

	cout << __FILE__ << __LINE__;
}


Logger::~Logger()
{}

