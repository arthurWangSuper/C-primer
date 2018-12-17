#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

bool isShort(const string &s1,const string &s2)
{
    return s1.size()<s2.size();
}

void elimDups(vector<string> &words)
{
    sort(words.begin(),words.end());
    auto end_unique = unique(words.begin(),words.end());
    words.erase(end_unique,words.end());
}

void biggies(vector<string> &words,vector<string>::size_type sz)
{
    elimDups(words);

    stable_sort(words.begin(),words.end(),
        [](const string &a,const string &b)
            {return a.size()>b.size();});
    auto wc = find_if(words.begin(),words.end(),
        [](const string &a,const string &b)
            {return a.size()>b.size();});
    auto count = words.end()-wc;

    cout<<count<<" "<<make_plural(count,"word","s");
    <<" of length"<<sz<<" or longer"<<endl;

    for_each(wc,words.end(),[](const string &s){cout<<s<<"";})
    cout<<endl;
}


int main(int argc, char const *argv[])
{
    string str;
    vector<string> svec;

    while(cin>>str)
    {
        svec.push_back(str);
    }

    elimDups(svec);

    stable_sort(svec.begin(),svec.end(),isShort);

    for(auto elem:svec)
        cout<<elem<<" ";
    cout<<endl;

    return 0;
}