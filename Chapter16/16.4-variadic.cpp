#include <iostream>
#include <string>

using namespace std;

class testclass{
    public:
        testclass(){};
        ~testclass(){};
        
};
/*因为左侧对象必须是对象本身，因此输入输出函数无法是成员函数*/
ostream& operator<<(ostream& os,const testclass &tc)
{
            return os<<"kiss"<<endl;
};
/*sizeof...() 函数的使用*/
template <typename T,typename... Args>
void foo(const T &t,const Args& ... rest)
{
   cout<<sizeof...(rest)<<endl;
   cout<<sizeof...(Args)<<endl;
}

template<typename T>
ostream& my_print(ostream& os,const T& t)
{
    return os<<t;
}

template<typename T,typename... Args>
ostream& my_print(ostream& os,const T& t,const Args ... rest)
{
    os<<t<<","; //打印第一个实参 
    return my_print(os,rest...);//注意rest的写法，这样表明 这是一个扩展类型
}

template <typename... T>
void my_test(T ...  rest)
{
    cout<<sizeof...(rest)<<endl;
}


int main(int argc,char **argv)
{
    int i =0;
    double d = 3.14;
    testclass *ptc = new testclass();
    string s = "how u brown cow";
#if 0
    foo(i,s,42,d);
    foo(d,s);
    foo(d);
#endif
    //my_print(cout,i,s,42,d);
    my_print(cout,i,*ptc);
    cout<<endl;

    //my_test(1,2,3,4,5);

    return 0;
}