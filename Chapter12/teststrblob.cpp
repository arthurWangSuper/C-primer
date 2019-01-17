#include <iostream>
#include <string>
#include <vector>

#include "StrBlobPtr.h"
#include "../Chapter11/StrBlob.h"

using namespace std;

int main(int argc,char**argv)
{
    initializer_list<string> il = {"hello","camera","a","b"};
    StrBlob *pStrB = new StrBlob(il);

    StrBlobPtr *pStrBP = new StrBlobPtr(*pStrB,0);

    //pStrBP->deref() = "ars";

    string str = pStrBP->deref();
    cout<<str<<endl;
    return 0;

}