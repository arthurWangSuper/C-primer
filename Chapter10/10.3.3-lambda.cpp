#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void fcn1()
{
    size_t v1 = 42; // local variable
    // copies v1 into the callable object named f
    auto f = [v1] { return v1; };
    v1 = 0;
    auto j = f(); // j is 42; f stored a copy of v1 when we created it
}

void fcn2()
{
    size_t v1 = 42; // local variable
    // the object f2 contains a reference to v1
    auto f2 = [&v1] { return v1; };
    v1 = 0;
    auto j = f2(); // j is 0; f2 refers to v1; it doesn't store it
    }
void fcn3()
{
    size_t v1 = 42; // local variable
    // f can change the value of the variables it captures
    auto f = [v1] () mutable { return ++v1; };
    v1 = 0;
    auto j = f(); // j is 43
}

void fcn4()
{
    size_t v1 =42;

    auto f = [&]{v1++;};

    auto f1 = [&]{return v1;};
    f();
    auto j = f1();

    cout<<v1<<endl;
}

void fcn5()
{
    int v1 = 10;
    // mutable 必须紧跟在参数列表后，注意此时的形式，
    auto f = [=]()mutable ->int {while(--v1);return false;};

    if(!f())
        cout<<" operation is done!!!"<<endl;
}

int main(int argc, char const *argv[])
{
    vector<int> strvec{10,21,22,31,3,3,4,4,4,4,5,5,5,5,5,5};

    int sz = 6;
    
    //返回有几个 4
    int i = count(strvec.begin(),strvec.end(),4);

    int j = count_if(strvec.begin(),strvec.end(),[&](int i)->int{if(i>sz) return true; else return false;});

    cout<<j<<endl;

    fcn5();


    return 0;
}
