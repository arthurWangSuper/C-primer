#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

using std::placeholders::_1;
using std::bind;

int isLess(int cnt,int sz)
{
    if(cnt>sz)
        return true;
    else
        return false;
}

ostream &print(ostream &os, const string &s, char c)
{
    return os << s << c;
}

int main(int argc, char const *argv[])
{

     vector<int> ivec{10,21,22,31,3,3,4,4,4,4,5,5,5,5,5,5};
    vector<string> words{"ab","bc","cd"};

    int sz = 6;

    int j = count_if(ivec.begin(),ivec.end(),bind(isLess, _1,sz));
    cout<<j<<endl;

    for_each(words.begin(), words.end(),bind(print, ref(cout), _1, ' '));

    return 0;
}
