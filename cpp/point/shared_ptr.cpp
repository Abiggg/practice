#include <iostream>
#include <stddef.h>

using namespace std;

template<typename T>

class shared_p {
	public:
		//consturct fun
		shared_p(T* ptr = NULL);
		//copy construct fun
		shared_p(const shared_p &ptr);
		//count use times
		size_t use_count();
		//reload operator *
		T& operator*();
		//reload oprerator &
		T* operator->();
		//destory
		~shared_p();
	private:
		T* ptr_;
		size_t count = 0;
};

template <typename T>
shared_p<T>::shared_p(T* ptr):ptr_(ptr)
{
	ptr_ = ptr;
	count++;
	cout<< "construct fun"<<endl;
}

template <typename T>
T& shared_p<T>::operator*()
{
	if(this->ptr != NULL) {
		return *(this->ptr_);
	}
}

template <typename T>
T* shared_p<T>::operator->()
{
	return this->ptr_;
}


template <typename T>
shared_p<T>::shared_p(const shared_p &ptr)
{
	if(this != &ptr) {
		this->ptr_ = ptr.ptr_;
		this->count = ptr.count;
		count++;	
	}

	cout<<"copy contruct"<<endl;
}

template <typename T>
shared_p<T>::~shared_p()
{
	count--;
	if (count == 0) {
		delete ptr_;
	}
	cout<<"destory fun"<<endl;
}

template <typename T>
size_t shared_p<T>::use_count()
{
	return count;
}

int main()
{
	shared_p<int> ptr_a = new int(10);
    cout << ptr_a.use_count()<<endl;
	shared_p<int> ptr_b(ptr_a);
    cout<< ptr_b.use_count()<<endl;
	return 0;
}
