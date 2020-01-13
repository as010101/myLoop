#pragma once


#include "Thread.h"
#include <assert.h>
#include "CurrentThread.h"
#include <vector>

class Channel;
class Poller;

class EventLoop {
 public:
  EventLoop();
  ~EventLoop();

  void loop();

  void assertInLoopThread() {
			if (!isInLoopThread()) {
			  abortNotInLoopThread();
			}
    }

  //EventLoop* getEventLoopOfCurrentThread();



    bool isInLoopThread() const { return threadId_ == CurrentThread::tid(); }

   private:
    void abortNotInLoopThread();
    bool looping_;   
    const pid_t    threadId_;
	typedef std::vector<Channel*> ChannelList;

	bool looping_; /* atomic */
	bool quit_; /* atomic */
	const pid_t threadId_;
	std::unique_ptr<Poller> poller_;
	ChannelList activeChannels_;



 private:
};

