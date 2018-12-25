#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

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
	
	//shared_ptr<string> pstr = new string(10,'a');

	//cout<<"pstr is "<<*pstr<<endl;
	return 0;
}
