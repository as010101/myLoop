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
  void updateChannel(Channel* channel);///这个要加上去嘛

  void assertInLoopThread() {
			if (!isInLoopThread()) {
			  abortNotInLoopThread();
			}
    }

  //EventLoop* getEventLoopOfCurrentThread();



    bool isInLoopThread() const { return threadId_ == CurrentThread::tid(); }

   private:
    void abortNotInLoopThread();

    const pid_t    threadId_;
	typedef std::vector<Channel*> ChannelList;
	bool looping_; /* atomic */
	bool quit_; /* atomic */

	std::unique_ptr<Poller> poller_;
	ChannelList activeChannels_;



 private:
};

