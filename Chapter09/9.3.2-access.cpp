#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <array>
#include <forward_list>

using namespace std;


int main()
{
    string str[3] = {"ac","dc","bc"};
    vector<char> cvec{'a','b','c'};
    deque<int> ideque = {1,2,3,4,5,6,7,8};
    string strl(cvec.begin(),cvec.end());
    forward_list<int> ilist(ideque.crbegin(),ideque.crend());
    array<string,3> arrS{"ac","dc","bc"};
    vector<string> strvec(begin(str),end(str));

    cout<<cvec.front()<<endl;
    //back is invalid for forwardlist
    cout<<ilist.front()<<endl;
    //at is valid for array vector deque string 
    if(!arrS.empty())
    {
        cout<<arrS.at(2)<<endl;
    }
    cout<<strvec.back()<<endl;

    /*erase*/
    ideque.erase(ideque.begin());
    
    deque<int>::iterator iterbegin = ideque.begin();
    deque<int>::iterator itermedium = ideque.begin()+(ideque.end()-ideque.begin())/2;
    ideque.erase(iterbegin,itermedium);
    /*test after erase iterator is invalid*/
    cout<<*iterbegin<<endl;
    iterbegin = ideque.begin();
    cout<<*iterbegin<<endl;

    strvec.clear();

    if(strvec.empty())
    {
        cout<<" strvec is empty"<<endl;
    }


    return 0;
}