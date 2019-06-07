/*
 *
 *以女娲造人为例，可以造黄种人，白种人，黑种人。因此就人造人工厂
 * 
 * */

#include<iostream>

using namespace std;

class Human{
public:
	virtual void eye() = 0;
	virtual void hair() = 0;
	virtual void skin() = 0;	
};

class YellowHuman : public Human{
	void eye()
	{
		cout<< "black eye" <<endl;
	}
	void hair()
	{
		cout<< "black hair"<<endl;
	}
	void skin()
	{
		cout << "yello skin"<< endl;
	}

};

class WhiteHuman :public Human{
	void eye()
	{
		cout << "blue eye" <<endl;
	}
	void hair()
	{
		cout << "yello hair" <<endl;
	}
	void skin()
	{
		cout << "wright "<<endl;
	}
};

class BlackHuman:public Human{
	void eye()
	{
		cout << "black eye" <<endl;
	}
	void hair()
	{
		cout << "black hair" <<endl;
	}
	void skin()
	{
		cout <<"black skin" <<endl;
	}
};

class Factory{
public:
	virtual Human* creat() = 0;
};

class YellowHumanFactory: public Factory{
public:
	Human* creat()
	{
		new YellowHuman;
	}
};

class WhiteHumanFactory:public Factory{
public:
	Human* creat()
	{
		new WhiteHuman;
	}
};

class BlackHumanFactory:public Factory{
public:
	Human* creat()
	{
		new BlackHuman;
	}
};

int main()
{
	YellowHumanFactory yelloFactory;
	WhiteHumanFactory whiteFactory;
	BlackHumanFactory blackFactory;
	Human* a = yelloFactory.creat();
	a->eye();
	a->skin();
	a->hair();
    Human* b = whiteFactory.creat();
	b->eye();
	b->skin();
	b->hair();
	Human *c = blackFactory.creat();
	c->eye();
	c->hair();
	c->skin();

	return 0;
}
