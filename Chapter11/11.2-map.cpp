#include <iostream>

#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(int argc,char*argv[])
{
    map<string,list<int>> wordoccur;

    map<vector<int>::iterator , int> vectormap;
    //map是有序容器，key需要方法来进行排序，list迭代器不具备这个功能。
    map<list<int>::iterator , int> listmap;
	
	map<int,string> strmap;

	strmap.insert(make_pair(1,"a"));

	strmap.insert(make_pair(2,"b"));

	strmap[3] = "c";
	strmap[2] = "2";
	
	strmap.insert(make_pair(3,"3"));
	strmap.emplace(make_pair(4,"d"));
	strmap.emplace(make_pair(4,"4"));

	map<int,string> cstrmap;

	cstrmap.insert({5,"e"});	
	cstrmap.swap(strmap);
	std::swap(strmap,cstrmap);
	map<int,string>::iterator it = strmap.begin();

	while(it!= strmap.end())
	{
		cout<<it->second<<endl;
		it++;
	}
	
	cout<<"strmap: "<<strmap.at(1)<<endl;

	for(auto elem:strmap)
	{
		cout<<elem.first<<" ";
	}
	cout<<endl;

	vector<int> ivec = {1,2,3,4,5,6,7};
	vector<int>::iterator itr =ivec.begin();

	//ivec.push_back(8);

	itr++;

    cout<<"itr: "<<*itr<<endl;
	cout<<"vector cap:"<<ivec.capacity()<<"size:"<<ivec.size()<<endl;
    //ivec.clear();
	cout<<"vector cap:"<<ivec.capacity()<<"size:"<<ivec.size()<<endl;
    ivec.erase(itr);
    cout<<"vector cap:"<<ivec.capacity()<<"size:"<<ivec.size()<<endl;
	return 0;
}
