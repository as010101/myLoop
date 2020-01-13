

#include "EventLoop.h"
#include <poll.h>
#include <iostream>
#include "CurrentThread.h"
#include "Channel.h"
#include "Poller.h"

#include <assert.h>

__thread  EventLoop*  t_loopInThisThread = 0;    //预先申请的内存变量



const int kPollTimeMs = 10000;

EventLoop::EventLoop()
	: looping_(false),
	quit_(false),
	threadId_(CurrentThread::tid()),
	poller_(new Poller(this))
{
	std::cout<< "EventLoop created " << this << " in thread " << threadId_;
	if (t_loopInThisThread)
	{
		std::cout << "Another EventLoop " << t_loopInThisThread
			<< " exists in this thread " << threadId_;
	}
	else
	{
		t_loopInThisThread = this;
	}
}

EventLoop::~EventLoop()
{
	assert(!looping_);
	t_loopInThisThread = NULL;
}

void EventLoop::loop()
{
	assert(!looping_);
	assertInLoopThread();
	looping_ = true;
	quit_ = false;

	while (!quit_)
	{
		activeChannels_.clear();
		poller_->poll(kPollTimeMs, &activeChannels_);
		for (ChannelList::iterator it = activeChannels_.begin();
			it != activeChannels_.end(); ++it)
		{
			(*it)->handleEvent();
		}
	}

	std::cout << "EventLoop " << this << " stop looping";
	looping_ = false;
}

void EventLoop::quit()
{
	quit_ = true;
	// wakeup();
}

void EventLoop::updateChannel(Channel* channel)
{
	assert(channel->ownerLoop() == this);
	assertInLoopThread();
	poller_->updateChannel(channel);
}

void EventLoop::abortNotInLoopThread()
{
	std::cout << "EventLoop::abortNotInLoopThread - EventLoop " << this
		<< " was created in threadId_ = " << threadId_
		<< ", current thread id = " << CurrentThread::tid();
}