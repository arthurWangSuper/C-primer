#include <iostream>

#include <string>
#include <vector>
#include <deque>
#include <forward_list>

using namespace std;

int main()
{

	string strA;
    deque<string> ideque;

    cout<<"using push_back"<<endl;
    while(cin>>strA)
    {
        ideque.push_back(strA);
    }
    cin.clear();
    
    cout<<"using push_front"<<endl;
    while(cin>>strA)
    {
        ideque.push_front(strA);
    }
    cin.clear();
    
    cout<<"using insert"<<endl;
    deque<string>::iterator iter = ideque.begin();
    while(cin>>strA)
    {
        iter=ideque.insert(iter,strA);
    }
    cin.clear();

    cout<<"using emplace_front"<<endl;
    iter = ideque.begin();
    while(cin>>strA)
    {
        //return a iterator reference to element added 
        iter=ideque.emplace(iter,strA);
    }
    cin.clear();

    cout<<"using emplace_front"<<endl;
    while(cin>>strA)
    {
        //return void
        ideque.emplace_front(strA);
    }
    cin.clear();

    cout<<"using emplace_back"<<endl;
    while(cin>>strA)
    {
        ideque.emplace_back(strA);
    }
    cin.clear();

    for(deque<string>::iterator it = ideque.begin();it!=ideque.end();it++)
    {
        cout<<*it<<""<<endl;
    }


	return 0;
}