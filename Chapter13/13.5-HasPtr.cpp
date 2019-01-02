#include <iostream>
#include <string>

using namespace std;

class HasPtr{

	public:
		HasPtr(const string &s= string()):
			ps(new string(s)),i(0) { }
		HasPtr(HasPtr &hp)
		{
			this->i = hp.i;
			this->ps = new string(*hp.ps);
		}
		HasPtr& operator=(const HasPtr& rhs)
		{
			i = rhs.i;
			ps = new string(*rhs.ps);
			return *this;
		}
        /*需要手动释放 指针指向的内存*/
		~HasPtr(){delete ps};

		int setval_ps(string &s)
		{
			ps = &s;
			return 0;
		}

		int setval_i(int val)
		{
			this->i = val;
		}
		int printHasPtr()
		{
			cout<<"string is: "<<*this->ps<<"i is: "<<this->i<<endl;
			return 0;
		}
	private:
		string *ps;
		int i;
};

int main(int argc, char* argv[])
{
	HasPtr *ptr = new HasPtr("str");
	
	ptr->setval_i(20);
	string ss = string("abc");
	
	auto pss = new string(10,'C');
	pss = &ss;

	ptr->setval_ps(*pss);
	
	HasPtr &rtr = *ptr;
	
	HasPtr hp = rtr;

	
	hp.printHasPtr();
	
	HasPtr dp;
	
	dp = rtr;

	cout<<"operator = result"<<endl;

	dp.printHasPtr();

	return 0;
}
