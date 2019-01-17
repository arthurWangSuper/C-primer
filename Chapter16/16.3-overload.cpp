#include <iostream>
#include <string>

using namespace std;

template<typename T> 
void f(T t)
{
    cout<<"call function: f1"<<endl;
}
template<typename T> 
void f(const T *t)
{
    cout<<"call function: f2"<<endl;
}

template<typename T> 
void g(T t)
{
    cout<<"call function: g1"<<endl;
}
template<typename T> 
void g(T *t)
{
    cout<<"call function: g2"<<endl;
}
/*验证16.42*/
template<typename T> 
void gval(T&& val)
{
    T v = val;
    cout<<"v addr: "<<&v
        <<" val addr: "<<&val<<endl;
}
int main(int argc,char **argv)
{
    int i =42, *p =&i;
    const int ci = i/*顶层const，对象本身*/,*p2 = &ci;

    g(42);
    g(p);
    g(ci);
    g(p2);

    f(42);
    f(p);/*无法匹配到const指针所以当成常量了*/
    f(ci);
    f(p2);

    gval(i);
    gval(ci);
    gval(i*ci);

    return 0;
}