#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	string str1;
	string str2;

	cin>>str1;
	
	cout<<str1<<" "<<str1.size()<<endl;
        cout<<str1.substr(3,string::npos)<<endl;
	return 0;
}
