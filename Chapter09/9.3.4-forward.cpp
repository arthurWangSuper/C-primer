#include <iostream>

#include <string>
#include <vector>
#include <deque>
#include <forward_list>

using namespace std;

int main()
{

    int a[10] = {1,2,3,4};
    forward_list<int> iflist;
    forward_list<int>::iterator listiter;

    iflist.push_front(1);
    
    listiter = iflist.before_begin();
    iflist.insert_after(listiter,{1,2,3,4,5});
    
    forward_list<int>::const_iterator clistiter;
    clistiter = iflist.cbefore_begin();
    iflist.insert_after(clistiter,5,2);
    
    listiter = iflist.before_begin();
    iflist.insert_after(listiter,begin(a),end(a));

    for(auto element:iflist)
        cout<<element<<" ";
    cout<<endl;

    clistiter = iflist.cbefore_begin();
    iflist.erase_after(clistiter);
    for(auto element:iflist)
        cout<<element<<" ";
    cout<<endl;

    clistiter = iflist.cbefore_begin();
    iflist.emplace_after(clistiter,5);
    
    iflist.emplace_front(20);
    for(auto element:iflist)
        cout<<element<<" ";
    cout<<endl;

}