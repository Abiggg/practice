#include <iostream>
#include <map>
#include <string>

using namespace std;

class A{
public:
	A(){}
	static int a;
	int b;
	int c;
private:
	//A(){}
	//A(const A &a);
	//A& operator=(const A &a);
};


map<string,A> resource;
#if 0
A::A(const A &a)
{}

A& A::operator=(const A &a)
{}
#endif
int A::a = 10;

int getA(string str, A* a)
{
	map<string, A>::iterator it = resource.find(str);
	if(it == resource.end()) {
		cout<< "cant find str"<<str<<endl;
	}
	a = &(it->second);
	cout << "b value is "<< a->b <<endl;
	cout<<"it address"<<&(it->second)<<endl;
}

int main()
{
	int test1;
	int test2;

	int *test3 = new int;
	int *test4 = new int;
    cout<< &test1 <<" "<< &test2 <<endl;
	cout << test3 << " "<< test4 << endl; 
	cout << sizeof(A)<<endl;
	A a;
	a.b = 100;;
	cout<< "a adreess is "<< &a<<endl;
	cout <<"a.b address is"<< &(a.b)<<endl;
	cout <<"a.c address is"<< &(a.c)<<endl;
	resource.insert(std::pair<string,A>("A",a));
	A* b;
	getA("A",b);
    return 0;
}

