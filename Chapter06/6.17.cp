#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool has_upper(const string& str)
{
	int flag = 0;
	if(str.empty())
	{
		return flag;
	}
	
	for(int i = 0;i<str.size();i++)
	{
		if(!islower(str[i]))
		{
			flag = 1;
			break;
		}
	}
	return 1;
}

int strlower(string& str)
{
 	for(int i = 0;i<str.size();i++)
	{
		if(!islower(str[i]))
		{
			str[i] = tolower(str[i]);
		}
	}
	return 0;
	
}

int main()
{
	string s1 = "aaaAvv";
	string s2 = "aaaaaa";
	
	if(has_upper(s1))
	{
		strlower(s1);
	}
	cout<<s1<<endl;
	
	return 0;
}
