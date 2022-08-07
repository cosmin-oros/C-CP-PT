#include <iostream>
#include <list>
#include <string>

using namespace std;

class IObserver{
public:
    virtual ~IObserver(){};
    virtual void Update(const std::string &message_from_subject) = 0;
};

class ISubject {
 public:
  virtual ~ISubject(){};
  virtual void Attach(IObserver *observer) = 0;
  virtual void Detach(IObserver *observer) = 0;
  virtual void Notify() = 0;
};

/**
 * The Subject owns some important state and notifies observers when the state
 * changes.
 */

void clientCode(){

}

int main(){
    clientCode();

    return 0;
}