#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <fstream>
//#include "Sales_data.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::begin;
using std::end;
using std::cerr;
using std::equal;
using std::istream_iterator;
using std::ostream_iterator;
using std::ifstream;
using std::ofstream;
template<typename T>
void printconstainer(T& ct){
	for(auto const &elem:ct)
	{
		cout<<elem<<" ";
	}
	cout<<endl;
}

int main(int argc,char **argv){
	
	list<string> l1;
	
	auto lback_it = back_inserter(l1);

	vector<string> words = {"qu'est",
							"ce",
							"que",
							"c'est",
							"que",
							"ce",
							"truc",
							"que",
							"je",
							"vois"};
	list<string> l_words(words.cbegin(),words.cend());
	// because unique just check cur && next charactor,so sort first 
	sort(words.begin(),words.end());
	//copy version of unique with back inserter to output anthor constainer
	unique_copy(words.cbegin(),words.cend(),lback_it);

	vector<int> v2= {1,2,3,4,5,6,7,8,9};
	
	list<int> l_insert,l_back,l_front;

	auto insert_it = inserter(l_insert,l_insert.begin());
	auto back_it = back_inserter(l_back);
	auto front_it = front_inserter(l_front);

	copy(v2.cbegin(),v2.cend(),insert_it);
	copy(v2.cbegin(),v2.cend(),back_it);
	copy(v2.cbegin(),v2.cend(),front_it);

	cout<<"inserter: ";
	printconstainer(l_insert);
	
    cout<<"back inserter: ";
	printconstainer(l_back);

	
	cout<<"front inserter: ";
	printconstainer(l_front);
	
	ifstream ifstrm("book_sales");
	if(!ifstrm.is_open()){
		cerr<<"File open fails"<<endl;
		return EXIT_FAILURE;
	}
	
	//bound to a stream requires a read 
	//bound to nothing indicates the eof value
	istream_iterator<string> isit1(ifstrm),ieof1;

	words.clear();

#ifndef COPY_INSERTER
	while(isit1 != ieof1)
	{
		words.push_back(*isit1++);
	}
#else
	auto vback_it = back_inserter(words);
	copy(isit1,ieof1,vbacj_it);
#endif
    cout<<"read string using istream iterator: "<<endl;

	for(auto const &elem:words)
	{
		if(elem.size()==5)
		{
			cout<<elem<<endl;
		}
		else 
		{
			cout<<elem<<" ";
		}
	}

	cout<<"read from input iterator"<<endl;

	auto iback_it = back_inserter(v2);
	istream_iterator<int> isit2(cin),ieof2;
	
	copy(isit2,ieof2,iback_it);
	sort(v2.begin(),v2.end());

	//write to output iterator 
	cout<<"sort ints read from stream: ";
	
	ostream_iterator<int> osit2(cout," ");
	
	unique_copy(v2.cbegin(),v2.cend(),osit2);

	//open a new input file and bind to a new istream iterator
	ifstrm.close();
	ifstrm.open("integers");
	if(!ifstrm.is_open())
	{
		cerr<<"integers input file open fails"<<endl;
		return EXIT_FAILURE;
	}
	
	
	istream_iterator<int> isit3(ifstrm),ieof3;

	//open two output files and bind to output iterators
	ofstream of_odd("odd"),of_even("even");
	if(!of_odd||!of_even )
	{
		cerr<<"output file open fails "<<endl;
		return EXIT_FAILURE;
	}

	//end string is " " or "\n"
	ostream_iterator<int> it_odd(of_odd,"");   
	ostream_iterator<int> it_even(of_even,"\n");

	while(isit3!=ieof3)
	{
		if(*isit3%2)
		{
			*it_odd++=*isit3;
		}
		else
		{
			*it_even++=*isit3;
		}
		++isit3;
	}

	//print elements reversely using reverse iterator
    v2={1,2,0,3,4,0,5,6};
    cout<<endl<<"print reversely(reverse iterator): ";
    auto rever=v2.crbegin();
    while(rever!=v2.crend())
    {
        cout<<*rever++<<" ";
    }

    //print reversely using normal iterator
    auto it2=v2.cend();
    cout<<endl<<"print reversely(normal iterator): ";
    while(it2!=v2.cbegin())
    {
        cout<<*--it2<<" ";
    }
    cout<<endl;

    list<int> l2(v2.cbegin(),v2.cend());
    
    //reverse iterator act just like normal iterator:
    //traverse from rbegin to rend, ++riter
    //yet the internal behavior is the opposite
    auto it_0=find(l2.crbegin(),l2.crend(),0);
    
    auto l_size=l2.size()-1;
    
    auto rever2=l2.crbegin();
    while(rever2!=it_0)
    {
        --l_size;
        ++rever2;
    }
    cout<<"the last 0 is at list["<<l_size<<"]"<<endl;

    v2={1,2,3,4,5,6,7,8,9,10};
    l2.assign(v2.crbegin()+3,v2.crbegin()+8);

    cout<<"copy with reverse iterator: ";
    for(const auto &ele:l2)
    {
        cout<<ele<<" ";
    }
    cout<<endl;

    //remove duplicates elements in list
    l_words.sort();
    l_words.unique();

    return EXIT_SUCCESS;


	return 0;
}
