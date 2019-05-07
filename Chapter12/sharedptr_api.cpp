#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;
void delete_string(string* p)
{
	cout<<"bye-bye"<<endl;
	delete p;
}
void printcontext(const shared_ptr<string>& sptr)
{ 
	weak_ptr<string> wptr(sptr);
	auto pstr = wptr.lock();
	if(pstr != nullptr)
	{
		cout<<"cont is: "<<*pstr<<"cnt is: "<<sptr.use_count()<<endl;
	}
	else{
		cout<<"ptr is empty"<<endl;
	}
}
int main(int argc,char* argv[])
{

	shared_ptr<string> sp1;
	
	/*make_shared<T>(args)*/
	sp1 = make_shared<string>(10,'s');
	
	auto sp0 = make_shared<string>("string");
	//get ptr from shared_ptr
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

	cout<<"sp1 use_count is "<<sp1.use_count()<<endl;
	cout<<"sp1 is "<<*sp0<<"sp2 is "<<*sp2<<endl;
	//注意此时不可以直接将从sp1 获得的指针交给 sp5构造函数，容易出现问题。
	shared_ptr<string> sp5(new string(*sp3));

	cout<<"sp1 use_count is "<<sp1.use_count()<<endl;

	cout<<"sp3 use_count is "<<sp5.use_count()<<endl;
	
	auto str = new string(10,'a');
	shared_ptr<string> pstr(str);
	
	cout<<"str is "<<*str<<endl;
	pstr = sp0;
	auto sp4 = new string("spsiy");
	cout<<"pstr is "<<*pstr<<endl;
	/*注意这段验证，str并没有被销毁，产生野指针，所以在用一个build指针对shared进行赋值时要注意*/
	if(str != nullptr)
	{
		cout<<"str is "<<*str<<endl;
	}

	/*reset 并指向一个新的内存地址*/
	/*pstr.reset()*/
	/*pstr.reset(q,d) 用d来free [q]*/
	pstr.reset(sp4);

	cout<<"pstr is "<<*pstr<<endl;

	shared_ptr<int> pi = make_shared<int>(42);

	unique_ptr<string> ustr(new string("string"));
	
	/*shared_ptr<string>p(q,d); 其中d为callable object*/
	shared_ptr<string> sptr(new string("afnkd"),delete_string);
	weak_ptr<string> wptr(sptr); //= make_shared<string>(10,'s');
	cout<<"lock before count: "<<wptr.use_count()<<endl;
	//其返回的是shared_ptr<T> 指针
	//sptr = wptr.lock();
	
	cout<<"sptr count: "<<sptr.use_count()<<" "<<*sptr<<endl;
	cout<<"lock after count: "<<wptr.use_count()<<endl;
	
	printcontext(sptr);
	sptr.reset();
	

	return 0;
}
