#include<iostream>
#include<string>
#include<vector>
#include<memory>

using namespace std;

class Customer{

public:
	virtual string getName()=0;
protected:
	string name_;
};

class RealCustomer:public Customer{
public:
	RealCustomer(string name)
	{
		name_ = name;
	}
	virtual string getName() override;
protected:
	string name_;
};

string RealCustomer::getName()
{
	return name_;
}

class NullCustomer:public Customer{
public:
	NullCustomer(string name)
	{
		name_ = name;
	}
	virtual string getName() override;
protected:
	string name_;
};

string NullCustomer::getName()
{
	return "null NullCustomer" + name_;
}

class CustomerFactory{
public:
	static int a;
	static vector<string> nameList; 
	static shared_ptr<Customer> getCustomer(string name) 
	{
		for(const auto& each:nameList)
		{
			if(each == name) {
				return make_shared<RealCustomer>(name);
			}
		}
		return make_shared<NullCustomer>(name);
	}
};

int CustomerFactory::a = 100;
vector<string> CustomerFactory::nameList = {"zhangsan", "lisi","wangwu"};

int main()
{
	shared_ptr<Customer> customer1 = CustomerFactory::getCustomer("zhangsan");
	shared_ptr<Customer> customer2 = CustomerFactory::getCustomer("lisi");
	shared_ptr<Customer> customer3 = CustomerFactory::getCustomer("test");

	cout<< customer1->getName()<<endl;
	cout<< customer2->getName()<<endl;
	cout<< customer3->getName()<<endl;

	return 0;
}
