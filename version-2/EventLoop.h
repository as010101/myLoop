#pragma once


#include "Thread.h"
#include <assert.h>
#include "CurrentThread.h"
#include <vector>
#include "Callbacks.h"
#include "TimerId.h"
#include <memory>

class Channel;
class Poller;

class EventLoop {
 public:
  EventLoop();
  ~EventLoop();
  typedef  std::function<void()> Functor;
  void loop();
  void updateChannel(Channel* channel);///这个要加上去嘛
  void quit();
  void assertInLoopThread() {
			if (!isInLoopThread()) {
			  abortNotInLoopThread();
			}
    }

  //EventLoop* getEventLoopOfCurrentThread();



    bool isInLoopThread() const { return threadId_ == CurrentThread::tid(); }


	Timestamp pollReturnTime() const { return pollReturnTime_; }

	/// Runs callback immediately in the loop thread.
	/// It wakes up the loop, and run the cb.
	/// If in the same loop thread, cb is run within the function.
	/// Safe to call from other threads.
	void runInLoop(const Functor& cb);
	/// Queues callback in the loop thread.
	/// Runs after finish pooling.
	/// Safe to call from other threads.
	void queueInLoop(const Functor& cb);

	// timers

	///
	/// Runs callback at 'time'.
	/// Safe to call from other threads.
	///
	TimerId runAt(const Timestamp& time, const TimerCallback& cb);
	///
	/// Runs callback after @c delay seconds.
	/// Safe to call from other threads.
	///
	TimerId runAfter(double delay, const TimerCallback& cb);
	///
	/// Runs callback every @c interval seconds.
	/// Safe to call from other threads.
	///
	TimerId runEvery(double interval, const TimerCallback& cb);

	// void cancel(TimerId timerId);

	// internal use only
	void wakeup();


   private:
	   void handleRead();  // waked up
	   void doPendingFunctors();

    void abortNotInLoopThread();

    const pid_t    threadId_;
	typedef std::vector<Channel*> ChannelList;
	bool looping_; /* atomic */
	bool quit_; /* atomic */

	bool callingPendingFunctors_; /* atomic */
	Timestamp pollReturnTime_;
	std::unique_ptr<Poller> poller_;
	std::unique_ptr<TimerQueue> timerQueue_;
	int wakeupFd_;
	// unlike in TimerQueue, which is an internal class,
	// we don't expose Channel to client.
	std::unique_ptr<Channel> wakeupChannel_;
	ChannelList activeChannels_;
	MutexLock mutex_;
	std::vector<Functor> pendingFunctors_; // @GuardedBy mutex_



 private:
};

