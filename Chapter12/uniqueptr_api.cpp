#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main(int argc,char* argv[])
{
	string *str =new string("abcc");
	/*unique_ptr<T,D> u;*/
	/*unique_ptr<T,D> u(d); d must be an object of the type D in place of delete*/
	unique_ptr<string> u1(str);
	unique_ptr<int> u2(new int(42));
	unique_ptr<int> u3(new int(43));
	unique_ptr<string> u4(new string("shdjkjf"));
	unique_ptr<string> u5(new string("akjd"));
	u1 = nullptr;
	/*Relinquishes control of the point u had held;
	 * returns the pointer u had held and makes u null*/
	auto ptr = u2.release();
	/*test*/
	/*
	unique_ptr<string> u6(u5);
	unique_ptr<string> u7;
	u7 = u1;
	*/

	u3.reset();
	u4.reset(new string("arsenal"));
	u5.reset(nullptr);

	int ix =1024, *pi =&ix, *pi2 = new int(2048);
	typedef unique_ptr<int> IntP;

	IntP p0(ix);
	IntP p1(pi);
	IntP p2(pi2);
	IntP p3(&ix);
	IntP p4(new int(2048));
	IntP p5(p2.get());
	
	return 0;
}
