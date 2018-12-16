/*stack && deque*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


int main(int argc,char**argv)
{
    vector<int> ivec{1,2,3,4,5};

    stack<int,vector<int>> istack(ivec);
    istack.push(6);
    istack.emplace(7);
    cout<<istack.top()<<endl;

    while(!istack.empty())
    {
        /*just pop element*/
        istack.pop();
    }



    queue<int,vector<int>> iqueue(ivec);
    cout<<iqueue.front()<<endl;
    cout<<iqueue.back()<<endl;
    //couT<<iqueue.top()<<endl; //error:not support

    //priority_queue<int,vector<int>> ipqueue(ivec);//error
    priority_queue<int> ipqueue;
    ipqueue.push(1);
    ipqueue.push(2);
    ipqueue.emplace(3);
    cout<<ipqueue.top()<<endl;

    priority_queue<int> ipqueue();

}