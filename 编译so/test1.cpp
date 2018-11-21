/*
编译so方法
g++ test1.cpp -fPIC -shared -o libtest.so

-shared该选项指定生成动态连接库（让连接器生成T类型的导出符号表，有时候也生成弱连接W类型的导出符号），
不用该标志外部程序无法连接。相当于一个可执行文件。
-fPIC：表示编译为位置独立的代码，不用此选项的话编译后的代码是位置相关的所以动态载入时是通过代码拷贝
的方式来满足不同进程的需要，而不能达到真正代码段共享的目的。

-L.：表示要连接的库在当前目录中。

-lxxxx：编译器查找动态连接库时有隐含的命名规则，即在给出的名字前面加上lib，
后面加上.so来确定库的名称。
*/

#include <iostream>

typedef enum tagNUM
{
  NUM0 = 0,
  NUM1,
  NUM_END,
}NUM_E;


using namespace std;

int max(int x, int y)
{
  int temp = x > y ? x : y;
  cout<<"the max is"<< temp <<endl;
  return temp;
}

int test1()
{
  cout<<"the current is test1"<<endl;
}
