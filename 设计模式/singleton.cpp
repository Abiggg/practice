#include <iostream>
#include <mutex>

using namespace std;

class Csingleton
{
public:
    ~Csingleton();
    static Csingleton* getInstance();
//单例模式中，一定要把构造函数设为私有。
private:
    Csingleton();
    Csingleton *pInstance;
}

Csingleton::~Csingleton()
{
}

Csingleton::Csingleton()
{
}

Csingleton* Csingleton::getInstance()
{
    if(NULL == pInstance)
    {
        mutex mtx;
        mtx.lock();
        if(NULL == pInstance)
        {
            pInstance =  new Csingleton();
        }
        mtx.unlock();
    }
    return pInstance;
}

void main()
{
  cout<<"hello world"<<endl;
  return;
}
