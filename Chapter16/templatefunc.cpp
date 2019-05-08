#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

template <typename T>
int compare(const T& lhs, const T& rhs)
{
    if(lhs<rhs)
        return 1;
    else
        return 0;
}

template <typename I,typename T>
I& my_find(I b,I e,T val)
{
    while((b != e)&(*b!=val))
        b++;
    return b;
}

template <typename T,size_t N>
int my_print(T (&a)[N])
{
    for(auto iter = begin(a);iter != end(a);iter++)
    {
        cout<<*iter<<endl;
    }

    return 0;
}

template <typename T,size_t N>
T* my_begin(T (&a)[N])
{
    return &a[0];
}

template <typename T,size_t N>
T* my_end(T (&a)[N])
{
    return &a[0]+N;
}

template <typename T,size_t N> constexpr
size_t my_length(T (&a)[N])
{
    return N;
}

template<typename It>
auto fcn(It beg, It end)->decltype(*beg)
{
	return *beg;
}

int main(int argc,char** argv)
{
    int a[4]={10,2,1,2};
    cout<<my_end(a)<<endl;
	vector<int> ivec(std::begin(a),std::end(a));
	
	cout<<fcn(ivec.begin(),ivec.end())<<endl;

    return -1;
}
