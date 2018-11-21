/*
编译so方法
g++ test2.cpp -fPIC -shared -o libtest.so
*/

#include <iostream>

using namespace std;

typedef enum tagNUM
{
  NUM0 = 0,
  NUM1,
  NUM_END,
}NUM_E;


int max(int x, int y)
{
  int temp = x > y ? x : y;
  cout<<"the max is"<< temp <<endl;
  return temp;
}

int test2()
{
  cout<<"the current is test2"<<endl;
}
