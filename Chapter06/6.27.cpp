#include<iostream>
#include<string>
#include<initializer_list>
using namespace std;

int sum_initializer(initializer_list<int> ilist)
{
	int sum = 0;
	for(auto i:ilist)
	{
		sum+=i;
	}
	return sum;
}

int main(int argc,char *argv[])
{
	initializer_list<int> ilist{1,2,3,4,5,6,7,8,9};
	int sum = sum_initializer(ilist);
	
	cout<<sum<<endl;

	return 0;
}
