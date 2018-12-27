#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main(int argc,char *argcv[])
{
    set<string> wordset = {"The", "But", "And", "Or", "An", "A",
        "the", "but", "and", "or", "an","a"};
    map<string,size_t> wordmap;
    string str;

    while(cin>>str)
    {
        /*只统计不在set中的word*/
        if(wordset.find(str) == wordset.end())
            ++wordmap[str];
    }

    for(const auto &w:wordmap)
    {
        cout<<"word: "<< w.first<<"occurs"<< w.second <<endl;
    }

    return 0;
}