

#include "EventLoop.h"

#include <iostream>


__thread  EventLoop*  t_loopInThisThread = 0;    //预先申请的内存变量

//
//EventLoop : : EventLoop()
//    : looping_(false),             //初始化为false
//      threadId_(CurrentThread
//                :
//                : tid()) {
//  LOG_ TRACE << "EventLoop created ”<< this <<”in thread ”<< threadId_ ;
//      if (t_ loopInThisThread) {
//    LOG_ FATAL << "Another EventLoop ”<< t_ loopInThisThread
//               <<”exists in this thread ”<< threadId,
//        ;
//    else {
//      t_ 1oopInThisThread = this;
//    EventLoop: :~EventLoop()
//{
//        assert(!looping_);
//        t_loopInThisThread = NULL;
//






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
		t_loopInThisThread = this;//this为何能赋给 t_loopInThisThread
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