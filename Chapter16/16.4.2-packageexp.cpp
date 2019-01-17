#include <iostream>
#include <string>

using namespace std;

template <typename T> 
string debug_rep(const T &t)
{
    ostringstream ret;
    ret<<t;
    return ret.str();
}

template<typename... T>
ostream &errorMsg(ostream& s,const Args&... rest)
{
    return print(os,debug_rep(rest)...);
}

int main(int argc,char **argv)
{

    return 0;
}