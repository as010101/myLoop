#pragma once


//����һ��FixedBuffer�࣬����ĳ�ʼ������Ϊͨ����ʼ��һ�����飬�ٳ�ʼ��һ��ָ�룬��ָ����ָ�������ģ�ע�ⶨ����ʱҪ����д������

//����append�����������������

template<int SIZE>
class FixedBuffer
{

public:
	
	FixedBuffer():cur_(data_)                   //�˴�һ��Ҫ��֤data_��cur_�ȳ�ʼ��
	{}
	~FixedBuffer()
	{}

	void append(const char * buf,int len)  //Ϊʲô�ǽ������const buf���Ƹ�cur
	{ 
		//��ȫ��� ����
		memcpy(cur_, buf, len);
		cur_ += len;
	}
	
private:

	char data_[SIZE];
	char *cur_;
};
