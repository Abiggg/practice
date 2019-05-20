#include <iostream>
#include <string.h>

using namespace std;

class String {
	public:
		String(const char* p_str = NULL);
		String(const String &str);
		String(String &&str);
		String &operator=(const String &str);
		String &operator=(String && str);
		~String();
	private:
		char* my_data;
};

String& String::operator=(const String &str)
{
	int len = strlen(str.my_data);
	this->my_data = new char[len];
	strcpy(this->my_data, str.my_data);
	cout<<"assginment copy"<<endl;
	return *this;
}

String &String::operator=(String && str)
{
	this->my_data = str.my_data;
	str.my_data = NULL;
	cout<<"copy assignment "<<endl;
	return *this;
}



String::String(String &&str)
{
    this->my_data = str.my_data;
	str.my_data = NULL;
	cout<< "move construct" <<endl;	
}



String::String(const String &str)
{
	int len = strlen(str.my_data);
	my_data = new char[len];
	memcpy(my_data, str.my_data, len);
	cout<<"this is copy construct"<<endl;
}

String::String(const char *p_str)
{
	if(p_str == NULL) {
		my_data = new char[1];
		my_data[0] = '\0';
	} else {
		int len = strlen(p_str);
	    my_data = new char[len];
		strcpy(my_data, p_str);
	}
    cout<<"this is default construct"<<endl;
}


String::~String()
{
	delete[] my_data;
	cout<<"this is destory fun"<<endl;
}

int main()
{
	String str1;
	String str2("abc");
	String str3(str2);
	String str4 = std::move(str3);
	String str5 = str4;
	String str6;
	str6= std::move(str5);

    return 0;
}
