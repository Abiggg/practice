/*
 *观察者模式，就是多个类依赖一个，当一个变化（通知时，会同时通知多个其他的）
 *以学生上课为例，一个学生去上课，其余3个未去，当需点名时，会同时通知其他3人，其他则相应动作
 *
 * */

#include<iostream>

using namespace std;

class studentBase{
public:
	virtual void GetCurrentStatus() = 0;
	virtual void update() = 0;
protected:
	string status;
};

class studentA:public studentBase{
public:
	studentA()
	{
		status = "sleep";
	}
	update()
	{
		status = "get up";
	}
};

class studentB: public studentBase{
public:
	studentB()
	{
		status = "go out";
	}
	update()
	{
		status = "got back";
	}
};

class notifierBase{
public:
	virtual void Notify(string msg) = 0;
	virtual void RegisterObserver(studentBase *student) = 0;
	virtual void RemoveObserver(studentBase *student) = 0;
};

class NotifierA{
	NotifierA()
	{
		studentList_ = new list<studentBase *>;
	}
	~NotifierA()
	{
		delete studentList_;
	}
	void RemoveObserver(studentBase *student)
	{
		studentList_->erase(student);
	}
	void RegisterObserver(studentBase *student)
	{
		studentList_->push_back(student);
	}
	void Notify(string msg)
	{
		if(msg = "sos")
		{
			for(list<studentBase*>::iterator it = studentList_->begin(); it != studentList_->end();it++)
			{
				(*it)->update();
			}
		}
	}

private:
	list<studentBase *> *studentList_;
};



int main()
{
	NotifierA notifierA;
	notifierA
	return 0;
}
