#include <iostream>

#include <string>
#include <vector>
#include <deque>
#include <list>

using namespace std;

int main()
{

	string strA = "abcdef";
	string strB{"abcdg"};
	cout<<(strA>strB? strA:strB)<<endl;
	
	vector<int> ivec1{1,2,3,4,5,6};
	vector<int> ivec2{1,2,3,4,5,6};
	
	cout<<(ivec1==ivec2? 1:2)<<endl;

	return 0;
}
