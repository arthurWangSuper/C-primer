#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string beforestr;
	string s;
	string repeatstr;
	int flag = 0;	

	while(cin>>s)
	{

		if(islower(s[0]))	
		{
			continue;
		}
		if(s==beforestr)
		{
			flag = 1;
			repeatstr = s; 
			break;
		}
		else
		{
			flag = 0;
			beforestr = s;
		}
	}
	
	if(flag)
	{
		cout<<"repeat string is "<<repeatstr<<endl;
	}
	else
	{
		cout<<"no repeat string "<<endl;
	}
	
	return 0;
}
