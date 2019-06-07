/*我们去餐厅吃饭，我们是通过服务员来点菜，具体是谁来做这些菜和他们什么时候完成的这些菜，其实我们都不知道。抽象之，“菜单请求者”我们和“菜单实现者”厨师，2者之间是松耦合的，我们对这些菜的其他一些请求比如“撤销，重做”等，我们也不知道是谁在做。其实这就是本文要说的Command模式。
*/
#include<iostream>
#include<list>

using namespace std;

class Cooker{
public:
	void cookMeat() 
	{
		cout<<"cook meat"<<endl;
	}
	void cookfruit() 
	{
		cout<< "cook juice"<<endl;
	}

};

class command{
public:
	command()
	{
	}
	command(Cooker *p_cooker)
   	{
		p_cooker_ = p_cooker;
	}
	virtual void do_it()=0;
protected:
	Cooker *p_cooker_;
};

class Waiter{
public:
	void setOrder(command *p_command)
	{
		list_command.push_back(p_command);	
		cout<<"set order"<<endl;
	}
	void notify() 
	{
		list<command*>::iterator it;
		for(it= list_command.begin();it!= list_command.end();++it) {
			(*it)->do_it();
		}
		cout<<"notify"<<endl;
	}
private:
	list<command*> list_command;
};

class cookMeatCommand:public command {
public:
	virtual void do_it()
   	{
		p_cooker_->cookMeat();
	}
};

class cookfruitCommand:public command {
public:
	virtual void do_it()
	{
		p_cooker_->cookfruit();
	}
};

int main()
{
    Waiter waiterA;
	command* p_commandMeat = new cookMeatCommand;
	command* p_commandFruit = new cookfruitCommand;

	waiterA.setOrder(p_commandMeat);
	waiterA.setOrder(p_commandFruit);

	waiterA.notify();

	delete p_commandMeat;
	delete p_commandFruit;
    return 0;
}
