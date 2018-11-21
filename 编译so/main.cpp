/*
编译main成可执行文件，同时链上libtest1.so与libtest2.so
g++ main.cpp -L. -ltest1 -ltest2 -o main
*/

#include <iostream>

using namespace std;

extern NUM0;

int main()
{
  cout<<"printf the num is :"<<NUM0<<endl;
  return 0;
}
