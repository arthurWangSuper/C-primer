#include <iostream>
#include <string>
#include <tuple>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256]={0};
        int length = 0;
        int max = 0;
        int begin = 0;
        int end = 0;
        int index = 0;

        while(index <256)
        {
            hash[index++] = 0;
        }

        for(int i = 0;i<s.length();i++)
        {
            if(hash[s[i]] == 0)
            {
                ++hash[s[i]];
            }
            else if(hash[s[i]] == 1)
            {

                length = end-begin;
                if(length>max)
                {
                    max = length;
                }


                while(s[i] != s[begin++]){

                    hash[s[begin]] = 0;
                }
            }
            end++;
        }

        length = end-begin;
        if(length>max)
        {
            max = length;
        }
        return max;
    }
};

int main(int argc,char* argv[])
{
#if 0
    tuple<int,string> ist;
    ist = make_tuple(1,"tomp");

    typedef decltype(ist) ist_type;

    //return the size of tuple_size
    size_t size = tuple_size<ist_type >::value;
    //return the type of n-th elem
    tuple_element<0,ist_type >::type it = 10;

    cout<<"size of tuple is "<<size<<endl;
    cout<<"1st elem is "<<it<<endl;

    if(fork() == 0)
    {
        cout<<"child process pid is "<<getpid()<<endl;
        cout<<"parent process pid is "<<getppid()<<endl;
    }
    else{
        int exitstatus = 0;
        //pit_t wait(int *status)
        wait(&exitstatus);

        cout<<"parent‘s process pid is "<<getppid()<<endl;
    }

#endif
    Solution sol;
    string str = "abcabcdb";
    cout<<sol.lengthOfLongestSubstring(str)<<endl;
    return 0;
}