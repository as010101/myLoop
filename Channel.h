#pragma once

#include "noncopyable.h"
#include <functional>

class EventLoop;

/// A selectable I/0 channel .
//
// This class doesn't own the file descriptor ¡£
/// The file descriptor could be a socket,
/// an eventfd, a timerfd, or a signalfd
class Channel :noncopyable
{
public:
	typedef   std::function<void()>  EventCallback;
	Channel(EventLoop* loop, int fd);
	void handleEvent();
	void setReadCallback(const EventCallback& cb)
	{
		readCallback_ = cb;
	}
	void setWriteCallback(const EventCallback& cb)
	{
		writeCallback_ = cb;
	}
	void setErrorCallback(const EventCallback& cb)
	{
		errorCallback_ = cb;
	}
	int fd() const { return fd_; }
	int events() const { return events_; }
	void set_revents(int revt) { revents_ = revt; }
	bool isNoneEvent() const { return events_ == kNoneEvent; }
	void enableReading(){ events_ |= kReadEvent; update(); }
	/// 1 void enableWriting()) { events_ |= kwriteEvent; update(); ]
	/// 1 void disableWriting(){ events_ &= ~kWriteEvent; update();
	/// 1 void disableA1lO { events_ = kNoneEvent; updateO; }
	/// 1 for Poller
	int index() { return index_; }
	void set_index(int idx) { index_ = idx; }
	EventLoop* ownerLoop() { return loop_; }



private:
	void update();
	static const int kNoneEvent;
	static const int kReadEvent;
	static const int kWriteEvent;
	EventLoop* loop_;
	const int	fd_;
	int	events_;
	int	revents_;
	int	index_; // used by Poller. .
	EventCallback readCallback_;
	EventCallback writeCallback_;
	EventCallback errorCallback_;

	};
