#ifndef _MESSAGE_QUEUE_H_
#define _MESSAGE_QUEUE_H_

#include<unistd.h>
#include<queue>
#include<mutex>
#include"innerMessageModel.h"

using namespace std;

class MessageQueue
{
private:
  mutex mMtx;
  queue<InnerMessageModel*> mQueue;

public:
  void push(InnerMessageModel *message)
  {
    lock_guard<mutex> lock(mMtx);
    mQueue.push(message);
  }

  InnerMessageModel* pop()
  {
    lock_guard<mutex> lock(mMtx);
    if(mQueue.empty()) return nullptr;

    InnerMessageModel *msg = mQueue.front();
    mQueue.pop();

    return msg;
  }
};

#endif
