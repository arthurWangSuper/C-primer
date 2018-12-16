#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc,char**argv)
{
	vector<int> ivec;

	ivec.push_back(10);
	cout<<"1:capacity: "<<ivec.capacity()<<" size: "<<ivec.size()<<endl;
	ivec.push_back(9);
	
	cout<<"2:capacity: "<<ivec.capacity()<<" size: "<<ivec.size()<<endl;
	
	vector<int>::iterator iter = ivec.end();
	ivec.insert(iter,{1,2,3,4});
	

	iter = ivec.end();
	ivec.insert(iter,5,12);

	for(auto element:ivec)
		cout<<element<<" ";
	cout<<endl;

	return 0;
}
