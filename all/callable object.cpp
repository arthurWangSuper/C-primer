//callable object
#include <iostream>
#include <functional>
#include <map>

using namespace std;
using std::placeholders::_1;
template<typename T>
void myswap(T&& val0,T&& val1)
{
	T tmp = val0;
	val0 =val1;
	val1 = tmp;
}

template<unsigned  N, unsigned M>
int compare(const char (&p1)[N],const char (&p2)[M])
{
	return strcmp(p1,p2);
}

int sum(int a,int b){
	return a+b;
};
template <typename T = int> class co{
	friend int sum(int , int);
public:
	co()=default;
	co(int a,int b):a(a),b(b){};
	//注释掉的原因在于，如果delete掉拷贝构造函数，那么无法通过值传递传参，无法通过值传递返回，在赋值构造函数需要用到
	//co(const co&)=delete;
	
	co& operator=(const co& val){
		this->a = val.a;
		this->b = val.b;
		return *this;
	};
	co& operator=(int val){
		this->a = val;
		this->b = val;
		return *this;
	};

	~co(){};
	int operator()(int x,int y){
		return a+b+x+y;
	};
private:
	int a = 0;
	int b = 20;
	T c;
};

int main()
{
	int a = 10;
	int b = 20;
	//按值捕获：相当于拷贝捕获值，而且还要注意时间点，且捕获的值是const的且是lambda定义时捕获，如果想要修改，则需要添加mutable标识符
	//按引用捕获：相当于引用传递，可以修改
	auto f =[=,&a]()mutable{ cout<<a++<<" "<<b++<<endl;};
    
	auto f1 = std::bind(sum,_1,2);
	co<> def;
	co<int> obj;
	co<int> *pobj = new co<int>(1,20);
	co<int> obj1;
	obj1 = 20;
	auto obj2 = obj1;
	function< void(void)> f2 = [=,&a]()mutable{ cout<<a++<<" "<<b++<<endl;};
	a =50;
	b = 15;
	f();
	f1(1);
	f2();
	
	int &val1 = a;
	int val2 = b; 
	myswap(val1,val2);
	cout<<"myswap==val1: "<<val1<<" val2: "<<val2<<endl;
	compare("hi","momí");
	cout<<"a: "<<a<<" b: "<<b<<" obj: "<<obj(5,10)<<" obj1: "<<obj1(5,10)<<endl;	
	return 0;
}
