#ifndef _STRBLOB_
#define _STRBLOB_

#include <vector>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include "../Chapter12/StrBlobPtr.h"

using std::vector;
using std::out_of_range;

//class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;
    public:
        typedef std::vector<std::string>::size_type size_type;

        StrBlob():data(std::make_shared<vector<std::string>>()){};
        StrBlob(std::initializer_list<std::string> il):data(std::make_shared<vector<std::string>>(il)){};

        size_type size(){return data->size();}

        bool empty(){return data->empty();}
        /*push_back*/
        void push_back(const std::string &s){data->push_back(s);}
        /*pop_back*/
        void pop_back();
        /*front*/
        std::string& front();
        std::string& front() const ;
        /*back*/
        std::string& back();
        std::string& back() const ;
    private:
        std::shared_ptr<std::vector<std::string>> data;
        void check(size_type i,const std::string &msg) const;
};

void StrBlob::check(size_type i,const std::string &msg) const
{
    if(i>data->size())
        throw out_of_range(msg);
}
std::string& StrBlob::front()
{
    check(0,"front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back()
{
    check(0,"back on empty StrBlob");
    return data->back();
}

std::string& StrBlob::front() const
{
    check(0,"front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back() const
{
    check(0,"back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0,"pop_back on empty StrBlob");
    data->pop_back();
}

#endif