#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int printvec(vector<int>& ivec)
{
	vector<int>::iterator it = ivec.begin();

	for(;it!=ivec.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	return 0;
}

int main(int argc,char**argv)
{
	list<int> ilist{1,2,3,4,5,6,7,8,9,10};
	vector<int> ivec1;
	vector<int> ivec2(10,1);
	vector<int> ivec3{1,2,3,4,5};
	vector<int> ivec4 = {1,2,3,4,5};
	vector<int> ivec5(ivec4);
	vector<int> ivec6(ilist.begin(),ilist.end());
	
	vector<double> dvec1(ilist.begin(),ilist.end());
	vector<double> dvec2{1.1,2.2,3.3,5.4,4.5,1.6,7.7,8.8,9.9};
	vector<int> ivec7(dvec2.begin(),dvec2.end());

	printvec(ivec2);	
	printvec(ivec3);	
	printvec(ivec4);	
	printvec(ivec5);	
	printvec(ivec6);
	printvec(ivec7);

	for(auto element:dvec1)
		cout<<element<<" ";

	return 0;
}
