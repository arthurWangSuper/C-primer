#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(int argc,char *argcv[])
{
    map<string,vector<string>> famap;
    string namestr,childstr;

    cin>>namestr;

    while(cin>>childstr)
    {
        famap[namestr].push_back(childstr);
    }

    for(const auto &w:famap)
    {
        cout<<"family name : "<< w.first<<endl;
        
        for(const auto &ch:w.second)
            cout<<ch<<" ";
    }
    cout<<endl;
    return 0;
}