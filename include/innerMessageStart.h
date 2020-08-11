#ifndef _INNER_MESSAGE_START_H_
#define _INNER_MESSAGE_START_H_

#include <string>
#include "innerMessageModel.h"

using namespace std;

class InnerMessageStart : public InnerMessageModel
{
private:
  string mMessage;;

public:
  InnerMessageStart(string message) : 
    InnerMessageModel(InnerMessageModel::Start),
    mMessage(message)
  {
  }

  virtual void Do(){
    return ;
  }

};

#endif

