#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    const char* strA = "king james";
    vector<char> cvec;

    copy(strA,strA+5,cvec.begin());
    
    return 0;
}