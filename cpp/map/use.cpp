#include <iostream>
#include <map>


using namespace std;

int main()
{
	map<string, string> student;

	student.insert(pair<string, string>("num0", "zhangsan"));
	student.insert(map<string, string>::value_type("num1", "lisi"));
	student.insert(pair<string, string>("num0", "testaa"));

	student["num2"] = "test4";
	student["num4"] = "test5";


	map<string, string>::iterator it;
	for(it = student.begin();it != student.end(); it++) {
		cout<<it->first << "=>" << it->second <<endl;
	}

	cout<<"find num0"<<student.find("num0")<<endl;

	cout<<"map size"<<student.size()<<endl;


	cout<<"hello world"<<endl;
}
