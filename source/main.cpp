#include<iostream>
#include<thread>
#include"innerMessageStart.h"
#include"MessageQueue.h"

using namespace std;

void ThreadFunc(MessageQueue *queue)
{
  std::cout << "Thread Start" << std::endl;
  while(1)
  {
    InnerMessageModel *message = queue->pop();
    if(message != nullptr){
      message->Do();
      if(message->getId() == InnerMessageModel::MessageID::Start){
        break; ;
      }
    }

    this_thread::sleep_for(chrono::milliseconds(10));
  }

  std::cout << "Thread End" << std::endl;
  return ;
}

int main(){
  std::cout << "Main Start" << std::endl;

  // キュー生成
  MessageQueue *queue = new MessageQueue();

  // スレッド生成
  thread th(ThreadFunc, queue);

  // StartMessage送信
  InnerMessageStart *pStart = new InnerMessageStart("TestMessage");
  queue->push(pStart);

  // Thread終了待ち
  th.join();

  // キュー破棄
  delete queue;

  std::cout << "Main End" << std::endl;
  return 0;
}

