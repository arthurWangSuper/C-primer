#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

void del

int main(int argc,char* argv[])
{

	shared_ptr<string> sp1;
	
	/*make_shared<T>(args)*/
	sp1 = make_shared<string>(10,'s');
	
	auto sp0 = make_shared<string>("string");

	string *sp3 = sp1.get();
	
	/*shared_ptr<T> p(q):q is a copy of the shared_ptr*/
	shared_ptr<string> sp2(sp1);

	sp0.swap(sp2);

	if(!sp0.unique())
	{
		cout<<"sp0 is not  unique"<<endl;
	}
	else
	{
		cout<<"sp0 is unique"<<endl;
	}

	cout<<"use_count is "<<sp1.use_count()<<endl;
	cout<<"sp1 is "<<*sp0<<"sp2 is "<<*sp2<<endl;
	
	auto str = new string(10,'a');
	shared_ptr<string> pstr(str);
	
	pstr = sp0;
	auto sp4 = new string("spsiy");
	cout<<"pstr is "<<*pstr<<endl;
	
	/*reset 并指向一个新的内存地址*/
	/*pstr.reset()*/
	/*pstr.reset(q,d) 用d来free [q]*/
	pstr.reset(sp4);

	cout<<"pstr is "<<*pstr<<endl;

	shared_ptr<int> pi = make_shared<int>(42);

	unique_ptr<string> ustr(new string("string"));
	
	shared_ptr<string> sptr(new string("afnkd"));
	

	return 0;
}
