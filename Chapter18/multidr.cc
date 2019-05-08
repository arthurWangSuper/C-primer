//派生类访问说明符的目的是为了控制派生类用户(包括派生类的派生类在内)
//个人难点在于protected继承
//public继承之后，所有成员访问性不变
//private继承之后，所有成员为private
//protected继承之后，所有public成员为protected
#include <iostream>
#include <string>
#include <memory>

class Base1{
	public:
	Base1()=default;
	Base1(const std::string &s){};
	Base1(std::shared_ptr<int> ptr){};
	Base1(int ival):ival(ival){};
	
	int aval = 123;
	private:
	std::string str;
	std::shared_ptr<int> sptr;
	protected://希望派生类使用，但是不希望成员使用
	int ival = 100;
};


class Base2{
	public:
	Base2()=default;
	Base2(const std::string& s){};
	Base2(std::shared_ptr<int> ptr){};
};

class D1:public Base1,public Base2{
	public:
//	using Base1::Base1;//从Base1 继承构造函数
//  using Base2::Base2;
};
class D2:public Base1,public Base2{

//	using Base1::Base1;
//	using Base2::Base2;
	public:
	D2(const std::string &s):Base1(s),Base2(s){ }
	D2() = default;

};
class D_pri:protected Base1{
	public:
		D_pri()=default;
		D_pri(int val,int ival):Base1(ival),val(val){};
		int getival();
	private:
		int val = 0;
};

int D_pri::getival()
{
	std::cout<<ival<<std::endl;
	return ival;
}


class DD_pri:public D_pri{
	public:
		int testival(){std::cout<<ival<<std::endl;}	

};

int main()
{
	std::cout<<"hello"<<std::endl;
	DD_pri *pd = new DD_pri();
	
	pd->testival();
	//std::cout<<pd->ival<<std::endl;
	return 0;

}
