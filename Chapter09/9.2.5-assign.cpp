#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <array>

using namespace std;

int main(int argc,char**argv)
{
	list<const char*> ilist = {"i","an","chicken"};

	vector<string> ivec;
	ivec.assign(ilist.begin(),ilist.end());
	
	vector<string> ivec1;
	ivec1.assign(3,"isis");

	for(auto element:ivec1)
		cout<<element<<endl;

	for(auto element:ivec)
		cout<<element<<endl;
	cout<<"-------------------------"<<endl;
	ivec.swap(ivec1);
	for(auto element:ivec1)
		cout<<element<<endl;

	for(auto element:ivec)
		cout<<element<<endl;
	array<string,3> arrA{"a","a","a"};
	array<string,3> arrB{"b","b","b"};
	
	/*
	 array<string,3> arrc(3,"c");//error: not support

	array<string,3> arrc("a");
	*/
	arrA.swap(arrB);
	
	cout<<"========================="<<endl;
	for(auto element:arrA)
		cout<<element<<endl;

	for(auto element:arrB)
		cout<<element<<endl;


	return 0;
}
