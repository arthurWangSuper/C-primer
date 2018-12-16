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

	cout<<"-------------------------"<<endl;
	vector<char> chAvec{'a','b','c','d','e'};
	vector<char> chBvec{'f','g','h','i','j'};

	vector<char>::iterator itrA = chAvec.begin()+(chAvec.end()-chAvec.begin())/2;
	
	chAvec.swap(chBvec);

	cout<<"vector A MEDIUM IS "<<*itrA<<endl;

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
	cout<<"test swap invail point reference"<<endl;
	
	string strA = "my way to success";
	string strB{"do and ferget pain"};

	string::iterator strAmed = strA.begin()+(strA.end()-strA.begin())/2;
	cout<<"med of strA is "<<*strAmed<<endl;
	
	strA.swap(strB);
	cout<<"med of strA is "<<*strAmed<<endl;

	return 0;
}
