#include <iostream>
#include "Logger.h"

using namespace std;

Logger::Logger(const char * fileName,int line):impl(fileName,line) //Logger�Ĺ���  ���impl��ʼ�����ó�ʼ����Ҫ��һ������imp�Ĺ��캯��
{}
 
Logger::Imp::Imp(const char * fileName,int line) :line_(line),fileName_(fileName)//imp�Ĺ��캯��
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

