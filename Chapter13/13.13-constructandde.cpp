#include <iostream>
#include <string>

using namespace std;

class X{
    public:
        X() {cout<<"X() "<<endl;}
        X(int){cout<<"x(int)"<<endl;}
        X(const X&){cout<<"X(const X&) "<<endl;}
        X& operator=(const X &rhs){cout<<"operator "<<endl;}
        ~X(){cout<<"~X "<<endl;}
};

X creatX()
{
    X x;
    X *tmp = new X();
    *tmp = x;
    //copy
    return *tmp;
}

int main(int argc, char* argv[]) {
    X x(*new X(0));
    cout<<"1st"<<endl;
    //copy
    X ax = x;
    cout<<"2nd"<<endl;
    X *bx = new X(0);
    cout<<"3rd"<<endl;
    //copy
    X cx[4] = {ax,*bx};
    cout<<"4th"<<endl;
    X dx = creatX();

    return 0;
}