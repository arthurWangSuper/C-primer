#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::endl;

int main()
{
	int x[10];
	int *p = x;
	
	vector<string> istr;
	istr.push_back("i");
	istr.push_back("am");
	
	vector<string>::iterator iter=istr.begin();

	vector<int>ivec(10);
	
	cout<<sizeof(ivec)<<endl;	
	cout<<sizeof(int)<<endl;
	cout<<sizeof(x)/sizeof(*x)<<endl;
	cout<<sizeof(p)/sizeof(*p)<<endl;
	return 0;
}
