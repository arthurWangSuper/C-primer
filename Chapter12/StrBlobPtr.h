#ifdef _STRBLOBPTR_
#define _STRBLOBPTR_

#include <string>
#include "../Chapter11/strBlob.h"

class StrBlobPtr{
    private:
        StrBlobPtr();
        StrBlobPtr(strBlob &a,size_t sz):wptr(a.data),cur(sz){};

        /*dereference*/
        std::string& deref() const;
        /*incre*/
        StrBlobPtr& incr(); // prefix version

    private:
        std::shared_ptr<std::vector<string>>
            check(std::size_t,const string&) const;
        std::weak_ptr<std::vector<string>> wptr;
        std::size_t cur = 0;
};

std::shared_ptr<std::vector<string>>
            StrBlobPtr::check(std::size_t i,const string &msg) const
{
 	auto ret = wptr.lock();
     	
	if(!ret)
		throw std::runtime_error("unbound StrBlobPtr");	
	
	if(i >= ret->size())
		throw std::out_of_range(msg);
	
	return ret;
}
std::string& StrBlobPtr::deref() const 
{
	auto p = check(curr,"deference past end");
	return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incr()

{

	// if curr already points past the end of the container, can't increment it

	check(curr, "increment past end of StrBlobPtr");
	++curr; // advance the current state

	return *this;

}
#endif
