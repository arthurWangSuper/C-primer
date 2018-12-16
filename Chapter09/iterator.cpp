#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc,char**argv)
{
	vector<int> ivec{1,2,3,4,5,6,7};
	const vector<int> cvec{2,4,6,8,10};

	auto it1 = ivec.begin();
	auto it2 = cvec.begin();
	auto it3 = ivec.cbegin();
	auto it4 = cvec.cbegin();
	/*cvec.push_back(12);*//*error:cvec is const vector<int>*/
	it1[2] = 10;
	it3[2] = 2;
	/*it2[2] = 11;*/

	return 0;
}
