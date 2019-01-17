#include <iostream>

#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(int argc,char*argv[])
{
    map<string,list<int>> wordoccur;

    map<vector<int>::iterator , int> vectormap;
    //map是有序容器，key需要方法来进行排序，list迭代器不具备这个功能。
    map<list<int>::iterator , int> listmap;

    return 0;
}