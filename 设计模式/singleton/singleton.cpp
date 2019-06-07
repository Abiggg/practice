#include <iostream>
#include <mutex>

using namespace std;

class Csingleton
{
private:
    Csingleton();
    static Csingleton *pInstance ;
public:
    ~Csingleton();
    static Csingleton* getInstance();
//单例模式中，一定要把构造函数设为私有。
public:
	int test;
};

Csingleton::~Csingleton()
{
}

Csingleton::Csingleton()
{
}

Csingleton *Csingleton::pInstance = NULL;


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

int main()
{
	Csingleton *testA = Csingleton::getInstance();
	Csingleton *testB = Csingleton::getInstance();
	cout << testA << endl;
	cout << testB << endl;

	testA->test = 1000;

	cout<< testB->test << endl;


	return 0;
}
