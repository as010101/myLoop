

#include "EventLoop.h"


__thread  EventLoop* t_loopInThisThread = 0;    //Ԥ��������ڴ����

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






EventLoop::EventLoop()
    : looping_(false),
      threadId_(CurrentThread::tid()){std::cout << " EventLoop created "
                                                << "in thread " << threadId_}

EventLoop::~EventLoop() {}