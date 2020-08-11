#ifndef _INNER_MESSAGE_MODEL_H_
#define _INNER_MESSAGE_MODEL_H_

class InnerMessageModel {
public:
  enum MessageID
  {
    Start,
    End
  };

private:
  InnerMessageModel::MessageID mId;

public:
  InnerMessageModel(InnerMessageModel::MessageID id) : mId(id)
  {
  }

  virtual ~InnerMessageModel(){}

  InnerMessageModel::MessageID getId(){ return mId;}

  virtual void Do() = 0;
};


#endif
