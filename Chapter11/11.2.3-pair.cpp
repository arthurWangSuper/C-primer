#include <iostream>

#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;

int main(int argc,char*argv[])
{
    pair<string,int> pair1{"abc",1};

    pair<string,int> pair2={"abc",2};

    pair<string,int> pair3("bcd",3); 

    pair<string,int> pair4;
    pair<string,int> pair5;

    pair5.first = "def";
    pair5.second = 2;

    pair4 = make_pair("def",4);
    
    cout<<"first: "<<pair4.first<<" second: "<<pair4.second<<endl;
    cout<<"first: "<<pair5.first<<" second: "<<pair5.second<<endl;

    pair<int,int> pair6{3,2};
    pair<int,int> pair7{2,3};
    /*先比第一个，后比第二个*/
    if(pair6<pair7)
    {
        cout<<" pair 6"<<endl;
    }
    else
    {
        cout<<" pair 7"<<endl;
    }


    return 0;
}