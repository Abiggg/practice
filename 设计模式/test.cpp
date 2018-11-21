#include<iostream>
#include <pthread.h>

using namespace std;
pthread_mutex_t mutex;

class Csingleton
{
public:
    ~Csingleton();
    static Csingleton* getInstance();

private:
    Csingleton();
    Csingleton *pInstance;
};

Csingleton::~Csingleton()
{
}

Csingleton::Csingleton()
{
}

static Csingleton* Csingleton::getInstance()
{
    if(NULL == pInstance)
    {
        if(pthread_mutex_lock(&mutex) != 0)
        {
          cout<<"lock error"<<endl;
        }
        if(NULL == pInstance)
        {
            pInstance =  new Csingleton();
        }
        pthread_mutex_unlock(&mutex);
    }
    return pInstance;
}

Csingleton * Csingleton::pInstance = NULL;
int main(){
cout<<"Hello, Linux!"<<endl;
return 0;
}
