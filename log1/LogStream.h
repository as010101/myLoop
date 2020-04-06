#pragma once


//定义一个FixedBuffer类，该类的初始化过程为通过初始化一个数组，再初始化一个指针，该指针是指向该数组的，注意定义类时要随手写下析构

//定义append，向数组中添加数据

template<int SIZE>
class FixedBuffer
{

public:
	
	FixedBuffer():cur_(data_)                   //此处一定要保证data_比cur_先初始化
	{}
	~FixedBuffer()
	{}

	void append(const char * buf,int len)  //为什么是将传入的const buf复制给cur
	{ 
		//安全检查 待做
		memcpy(cur_, buf, len);
		cur_ += len;
	}
	
private:

	char data_[SIZE];
	char *cur_;
};
