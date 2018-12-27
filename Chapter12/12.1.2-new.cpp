#include <iostream>

#include <vector>
#include <memory>

using namespace std;

void inputvec(vector<int> *p)
{
    int i = 0;
    while(cin>>i)
    {
        p->push_back(i);
    }
}


void printvec(shared_ptr<vector<int>> p)
{
    for(auto elem:*p)
        cout<<elem<<endl;
}
void inputvec(shared_ptr<vector<int>> p)
{
    int i = 0;
    while(cin>>i)
    {
        p->push_back(i);
    }
}

void printvec(vector<int> *p)
{
    for(auto elem:*p)
        cout<<elem<<endl;
}

int main(int argc,char* argv[])
{
    auto p = new vector<int>;

    auto sp = make_shared<vector<int>>();
    
    vector<int> ivec{9,7,5,3};

    shared_ptr<vector<int>> pvec(p);

    //inputvec(sp);
    //printvec(sp);
    //inputvec(sp);
    
    //pvec = sp;
    
    //printvec(pvec);

    
    delete p;
    p = nullptr;
    return 0;
}

