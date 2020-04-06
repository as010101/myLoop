#pragma once

#include <string>
#include "LogStream.h"

//class FixedBuffer
using namespace std;

// 1дLogger��Imp�Ĺ��������

//  дLoggStream��

class Logger
{


public:
	Logger(const char *,int);  //����ִ�д��Ĵ�����Ϣ
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