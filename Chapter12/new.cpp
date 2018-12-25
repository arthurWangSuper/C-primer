#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

int main(int argc,char* argv[])
{
	string *pstr = new string("i am a a!");

	string str = "adc dd";
	int *p = new int(10);

	auto ps = new auto(str);

	ps = pstr;

	cout<<str<<endl;
	
	//const 变量需要定义初始化
	const int *cp = new const int(1024);

	auto pv = new vector<int>{1,2,3,4,5,6};

	for(auto elem:*pv)
		cout<<elem<<endl;

	return 0;
}
