#include <iostream>
#include <memory>

using namespace std;

int main()
{
	int a = 10;
	shared_ptr<int> ptr_a = make_shared<int>(a);
	shared_ptr<int> ptr_b(ptr_a);
	cout << ptr_a.use_count() <<endl;

	int b = 20;
	int *pb = &b;
	shared_ptr<int> ptr_c = make_shared<int>(b);
	shared_ptr<int> ptr_d;
	ptr_d = ptr_c;
	cout << ptr_c.use_count()<<endl;

	int c = 30;
	unique_ptr<int> ptr_e(new int(10));
	unique_ptr<int> ptr_f = move(ptr_e);

	return 0;
}
