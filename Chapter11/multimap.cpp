#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::multimap;
using std::make_pair;
using std::pair;

//find
//count
//equal_range
//lower_bound
//high_bound

int main()
{
	multimap<string,int> authors;
	for(int i=0;i<10;i++)
	{
		for(int j = 0;j<=i;j++)
		{
			string s;
			s+='a'+j;
			authors.insert(make_pair(s,i));
			authors.insert(make_pair(s,i-1));
		}
	}
	
	multimap<string,int>::iterator map_it=authors.begin();
	typedef multimap<string,int>::iterator authors_it;
	cout<<"origin multimap: "<<endl;
	
	while(map_it != authors.end())
	{
		cout<<map_it->first<<":";

		typedef multimap<string,int>::size_type sz_type;
		sz_type cnt = authors.count(map_it->first);
		for(sz_type i =0;i!=cnt;++map_it,++i)
		{	
			cout<<map_it->second<<" ";
		}
		cout<<endl;
	}
	
	map_it=authors.find("c");
	pair<authors_it,authors_it> pos = authors.equal_range(map_it->first); 
	while(pos.first!=pos.second){
		if(pos.first->second==5)
		{
			pos.first=authors.erase(pos.first);
		}
		else
		{
			++pos.first;
		}
	}
	cout<<"删除(c,5)之后的multiple容器"<<endl;
	map_it=authors.begin();
	while(map_it!=authors.end()){
		cout<<map_it->first<<":";

		typedef multimap<string,int>::size_type sz_type;
		sz_type cnt = authors.count(map_it->first);
		for(size_t i = 0; i !=cnt;++map_it,++i)
		{
			cout<<map_it->second<<" ";
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}
