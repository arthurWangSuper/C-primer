#include<iostream>
#include<string>
#include<vector>
#include<cassert>

using namespace std;

int printvec(vector<int> &ivec,vector<int>::iterator iter)
{
	static int cnt = 100;
	if(iter != ivec.end())
	{
		cout<<*iter<<endl;
#ifndef NDEBUG
		cout<<__func__<<"round: "<<cnt++<<endl;
#endif
		printvec(ivec,++iter);
	}
	return 0;
}

int main(int argc,char *argv[])
{
	vector<int> ivec{1,2,3,4,5,6,7,8,9,10};
	vector<int>::iterator iter = ivec.begin();
	
	printvec(ivec,iter);	

	return 0;
}
