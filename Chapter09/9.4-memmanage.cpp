#include <iostream>

#include <string>
#include <vector>
#include <deque>
#include <forward_list>

using namespace std;

int main()
{
    //vector<int> ivec(10);
    vector<int> ivec;
    if(ivec.empty())
    {
        cout<<"ivec is empty"<<endl;
    }
    cout<<"capacity is: "<<ivec.capacity()<<" size is: "<<ivec.size()<<endl;

    ivec.insert(ivec.begin(),{0,1,2,3,4,5,6,7,8,9,10,11,12,13});

    for(auto elem:ivec)
        cout<<elem<<" ";
    cout<<endl;

    cout<<"after insert capacity is: "<<ivec.capacity()<<" size is: "<<ivec.size()<<endl;

    ivec.resize(15);
    cout<<"after resize capacity is: "<<ivec.capacity()<<" size is: "<<ivec.size()<<endl;
    ivec.resize(18,3);
    cout<<"after resize with parameters capacity is: "<<ivec.capacity()<<" size is: "<<ivec.size()<<endl;
    ivec.reserve(30);
    cout<<"after reserve capacity is: "<<ivec.capacity()<<" size is: "<<ivec.size()<<endl;

    ivec.shrink_to_fit();
    cout<<"after fit capacity is: "<<ivec.capacity()<<" size is: "<<ivec.size()<<endl;
     for(auto elem:ivec)
        cout<<elem<<" ";
    cout<<endl;
    
    return 0;
}