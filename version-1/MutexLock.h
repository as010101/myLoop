
#pragma once
#include <pthread.h>
#include <cstdio>
#include "noncopyable.h"


//做两件事情  对象化mutex、并用封装的类实现mutexGuard,事实上c++11已有lock_guard的实现（<mutex>中）
//对象化mutex时   自己会初始化mutex，无必传入参数，   实现了lock unlock 函数 ，析构detroy时要先将mutex锁住再destroy
//封装LockGuard  初始化的时候将mutex锁住，析构的时候调用自己的析构函数，在自己的析构函数里面对mutex解锁后跳到MutexLock类执行析构函数(先加锁再destroy)

class MutexLock : noncopyable {
 public:
  MutexLock() { pthread_mutex_init(&mutex, NULL); }
  ~MutexLock() {
    pthread_mutex_lock(&mutex);
    pthread_mutex_destroy(&mutex);
  }
  void lock() { pthread_mutex_lock(&mutex); }
  void unlock() { pthread_mutex_unlock(&mutex); }
  pthread_mutex_t *get() { return &mutex; }

 private:
  pthread_mutex_t mutex;

  // 友元类不受访问权限影响
 private:
  friend class Condition;
};

class MutexLockGuard : noncopyable {
 public:
  explicit MutexLockGuard(MutexLock &_mutex) : mutex(_mutex) { mutex.lock(); }
  ~MutexLockGuard() { mutex.unlock(); }

 private:
  MutexLock &mutex;
};