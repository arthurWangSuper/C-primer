#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    const char* strA = "king james";
    const char* strB = "king james";

    if(equal(strA,strA+11,strB))
    {
        cout<<"yes it is "<<endl;
    }
    else
    {
        cout<<"no it isnot "<<endl;
    }

    vector<double> ivec{1.5,2,3,4,5,6.7,7,8,9,10};
    cout<<accumulate(ivec.cbegin(),ivec.cend(),0.0)<<endl;

    return 0;
}
