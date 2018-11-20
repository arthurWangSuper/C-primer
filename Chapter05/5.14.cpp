/*vector 不可以用下标操作进行赋值*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;


int main()
{
	
	vector<int> cnt;
	vector<string> istr;
	int str_index = 0;
	int maxcnt =0;
	int max_index=0;
	string s;
	int cnttmp = 0;
	
	while(cin>>s)
	{
		if(istr.empty())
		{
			istr.push_back(s);
			cnttmp++;
		}
		else if(istr[str_index]==s)
		{
			cnttmp++;
		}
		else
		{
			istr.push_back(s);		
			cnt.push_back(cnttmp);
			cnttmp = 1;
			str_index++;
		}
	}

        cnt.push_back(cnttmp);
	
	for(int i=0;i < cnt.size();i++)
	{
		if(maxcnt<cnt[i])
		{
			maxcnt=cnt[i];
			max_index = i;
		}
	}

	cout<<"maxcnt string :"<<istr[max_index]<<endl<<"maxcnt "<<cnt[max_index]<<endl;
	return 0;
}
