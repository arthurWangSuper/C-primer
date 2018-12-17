#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
bool isgreat(const string& str)
{
    return str.size()>5 ;
}

int main(int argc, char const *argv[])
{
    string str;
    vector<string> svec;

    while(cin>>str)
    {
        svec.push_back(str);
    }

    auto part_iter = partition(svec.begin(),svec.end(),isgreat);

    svec.erase(part_iter,svec.end());

    for(auto elem:svec)
        cout<<elem<<" ";
    cout<<endl;
    
    return 0;
}