#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;
int fcn(int i)
{
    cout<<"ars is is"<<endl;
    return i;
}

int main(int argc,char* argv[])
{

    vector<int> ivec1{2,3,4,5,6,6,7,7};
    vector<int> ivec2{1,2,3,4,5,6,7,8,9};
    vector<int> ivec3;
    vector<int> ivec4;

    list<int> ilist1;
    list<int> ilist2;
    
    //decltype(fcn) f;
    int (*pf)(int);
    pf = fcn;
    pf(1);

    /*与unique相同，需要两个重复元素相邻*/    
    unique_copy(ivec1.begin(),ivec1.end(),inserter(ilist1,ilist1.begin()));

    copy(ivec2.begin(),ivec2.end(),inserter(ivec3,ivec3.begin()));
    copy(ivec2.begin(),ivec2.end(),front_inserter(ilist2));
    copy(ivec2.begin(),ivec2.end(),back_inserter(ivec4));

    for(auto elem:ilist1)
        cout<<elem<<" ";
    cout<<endl;


    for(auto elem:ivec3)
        cout<<elem<<" ";
    cout<<endl;

    for(auto elem:ivec4)
        cout<<elem<<" ";
    cout<<endl;

    for(auto elem:ilist2)
        cout<<elem<<" ";
    cout<<endl;

    return 0;
}