#ifndef _STRBLOBPTR_
#define _STRBLOBPTR_

#include <string>
#include "../Chapter11/StrBlob.h"

class StrBlobPtr{
	public:
        StrBlobPtr()=default;
        StrBlobPtr(StrBlob &a,size_t sz):wptr(a.data),cur(sz){};

        /*dereference*/
        std::string& deref() const;
        /*incre*/
        StrBlobPtr& incr(); // prefix version

    private:
        std::shared_ptr<std::vector<std::string>>
            check(std::size_t,const std::string&) const;
        std::weak_ptr<std::vector<std::string>> wptr;
        std::size_t cur = 0;
};

std::shared_ptr<std::vector<std::string>>
            StrBlobPtr::check(std::size_t i,const std::string &msg) const
{
 	auto ret = wptr.lock();

 	ret->push_back(str);
	if(!ret)
		throw std::runtime_error("unbound StrBlobPtr");	
	
	if(i >= ret->size())
		throw std::out_of_range(msg);
	
	return ret;
}
std::string& StrBlobPtr::deref() const 
{
	auto p = check(cur,"deference past end");
	return (*p)[cur];
}
StrBlobPtr& StrBlobPtr::incr()

{

	// if curr already points past the end of the container, can't increment it

	check(cur, "increment past end of StrBlobPtr");
	++cur; // advance the current state

	return *this;

}
#endif
