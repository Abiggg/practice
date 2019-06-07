/*
 *组合模式
 *就是基类容合了子类的所有方法，子类可以对基类的方法重载，也可不具备了类的方法
 *例如学生高考，理工生只需考语数英理综，文科生考语数英文综，美术生高语数英美，体育生考语数英体
 * */


#include<iostream>

using namespace std;

class student{
public:
	virtual void chinese() 
	{
		cout << "test chinese"<< endl;
	} 
	virtual void math()
	{
		cout << "test math" <<endl;
	}
	virtual void English()
	{
		cout << "test English" << endl;
	}

	virtual void lizong()
	{
		cout << "test combine" << endl;
	}

	virtual void wenzong()
	{
		cout << "test wenzong" << endl;
	}
	
	virtual void art()
	{
		cout << "test ART" << endl;
	}

	virtual void pe()
	{
		cout << "test pe" <<endl;
	}

};

class li_student{
public:
	void chinese()
	{
		cout << "li_studen test chinese" << endl;
	}
	void math()
	{
		cout << "li_student test math" << endl;
	}

	void English()
	{
		cout << "li_student test English" << endl;
	}

	void lizong()
	{
		cout << "li_student test lizong" << endl;
	}
};

class art_student{
public:
	void chinese()
	{
		cout << "art_student test chinese"<<endl;
	}
	void art()
	{
		cout << "art_student test art" << endl;
	}
};

int main()
{
	li_student studentA;
	art_student studentB;

	studentA.chinese();
	studentB.art();

	return 0;
}
