#include <iostream>
#include <memory>
#include <cstring>
#include "mystring.hpp"

using std::cout;
using std::endl;
using std::allocator;
using std::ostream;
using std::uninitialized_copy_n;
using std::flush;
//静态变量的定义
allocator<char> mystring::alloc;

//注意其返回值
ostream& operator<<(ostream& os,const mystring& s)
{
	os<<s.c_str;
	os<<flush;
	return os;
}

void swap(mystring& lhs,mystring& rhs)
{
	//注意这一点
	using std::swap;

	swap(lhs.c_str,rhs.c_str);
	swap(lhs.len,rhs.len);
}

mystring::mystring(char *str)
{
	if(str == nullptr)
	{
		c_str = nullptr;
		len = 0;
	}
	else
	{
		//strlen without '\0' in count
		len = strlen(str);
		c_str = alloc.allocate(len+1);
		uninitialized_copy_n(str,len+1,c_str);
	}	
}

mystring::mystring(const mystring& s)
{
	len = s.size();
	c_str = alloc.allocate(len+1);
	uninitialized_copy_n(s.c_str,len+1,c_str);
}

mystring::~mystring()
{
	alloc.deallocate(c_str,len+1);
}

mystring& mystring::operator=(mystring& rhs)
{
	//深拷贝
	len = rhs.size();
	c_str = alloc.allocate(len+1);
	uninitialized_copy_n(rhs.pstr(),len+1,c_str);
	return *this;
}

mystring operator+(mystring& lhs,mystring& rhs)
{
	mystring res;
	int sum = lhs.len+rhs.len;

	char *cptr = mystring::alloc.allocate(sum+1);
	
	uninitialized_copy_n(lhs.c_str,lhs.len,cptr);
	uninitialized_copy_n(rhs.c_str,rhs.len+1,cptr+lhs.len);
	
	mystring:: alloc.deallocate(lhs.c_str,lhs.len+1);
   // alloc.deallocate(rhs.c_str,rhs.len+1);

	res.c_str = cptr;
	res.len =sum;

	return res;
}


int main()
{
	mystring s1("ssss");
	mystring s2(s1);
	mystring s3;
	s3 = s2;
	mystring s4 = "abcd";
	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<s3<<endl;

	swap(s1,s4);	
	cout<<s1<<endl;
	cout<<s4<<endl;
	
	cout<<"s1 len: "<<s1.size()<<endl;
    cout<<"s1+s4: "<<s1+s4<<endl;
	return 0;
}
