

#include "EventLoop.h"
#include <poll.h>
#include <iostream>
#include "CurrentThread.h"

__thread  EventLoop*  t_loopInThisThread = 0;    //Ԥ��������ڴ����

//
//EventLoop : : EventLoop()
//    : looping_(false),             //��ʼ��Ϊfalse
//      threadId_(CurrentThread
//                :
//                : tid()) {
//  LOG_ TRACE << "EventLoop created ��<< this <<��in thread ��<< threadId_ ;
//      if (t_ loopInThisThread) {
//    LOG_ FATAL << "Another EventLoop ��<< t_ loopInThisThread
//               <<��exists in this thread ��<< threadId,
//        ;
//    else {
//      t_ 1oopInThisThread = this;
//    EventLoop: :~EventLoop()
//{
//        assert(!looping_);
//        t_loopInThisThread = NULL;
//



void EventLoop::loop()
{
	assert(!looping_ );
	assertInLoopThread();
	looping_ = true;
	::poll(NULL,0,5 * 1000);
		std::cout<< "EventLoop ��<< this <<��stop looping";
	looping_ = false;

}


void EventLoop::abortNotInLoopThread()
{
}

EventLoop::EventLoop()
	: looping_(false),
	threadId_(CurrentThread::tid()) {
	std::cout << " EventLoop created "<< t_loopInThisThread
		<< "in thread " << threadId_;
	if (t_loopInThisThread)
	{
		std::cout << "Another EventLoop "<<t_loopInThisThread<< "appeared";
	}
	else
	{
		t_loopInThisThread = this;//thisΪ���ܸ��� t_loopInThisThread
	}
}
//
//EventLoop *  EventLoop::getEventLoopOfCurrentThread()
//{
//	return t_loopInThisThread;
//}


EventLoop::~EventLoop() {
	assert(!looping_);
	t_loopInThisThread = nullptr; //null

}
