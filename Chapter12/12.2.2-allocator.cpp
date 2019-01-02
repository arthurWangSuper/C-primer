#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

int main(int argc,char* argv[])
{
	allocator<string> astr;
	
	auto const p = astr.allocate(10);
	
	string str;
	
	auto q = p;

	int count = 10;
	while(--count)
	{
		cin>>str;
		astr.construct(q++,str);
	}

	while(q!=p)
		astr.destroy(--q);
	
	astr.deallocate(p,10);
	
	vector<string> vi{"s","d","f"};

	allocator<string> alloc;

	auto dp = alloc.allocate(vi.size()*2);


	auto qu = uninitialized_copy(vi.begin(), vi.end(), dp);
	/*uninitialized_copy_n(b,n,b2)*/

	// initialize the remaining elements to 42

	/*uninitialized_fill(b,e,t);*/
	//下边的函数返回的到底是什么
	auto quf = uninitialized_fill_n(qu, vi.size(), "ss");
#if 1
	auto pqu = qu;
	count = 5;
	while(--count)
		alloc.destroy(pqu++);
	alloc.deallocate(dp,vi.size()*2);
#endif
	
	return 0;
}
