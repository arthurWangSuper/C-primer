#include<iostream>
#include<string>
#include<vector>

using namespace std;

int printvec(vector<int> &ivec,vector<int>::iterator iter)
{
	if(iter != ivec.end())
	{
		cout<<*iter<<endl;
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
