#include<iostream>
#include<string>

using namespace std;

int main(int argc,char** argv)
{
	string str1;
	string str2="VASKLS10";
	string str3 = string(10,'c');	

	for(decltype(str2.size()) i = 0;i<str2.size();i++ )
	{
		str2[i]='x';
	}
	cout<<str2<<endl;
	for(auto &c:str3)
		c='x';
	cout<<str3<<endl;
	return 0;
}
