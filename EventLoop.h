#pragma once


#include "Thread.h"
#include <assert.h>

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



 private:
};

