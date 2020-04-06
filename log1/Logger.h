#pragma once

#include <string>
#include "LogStream.h"

//class FixedBuffer
using namespace std;

// 1写Logger和Imp的构造和析构

//  写LoggStream类

class Logger
{


public:
	Logger(const char *,int);  //传入执行处的代码信息
	~Logger();

	
private:
	class Imp
	{
	public:
		Imp(const char*, int);

	private:

		int line_;
		string fileName_;
		
	};

	Imp impl;
	FixedBuffer<4000> pdata;

};


#define Log  Logger(__FILE__,__LINE__)