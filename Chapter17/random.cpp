#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include <cmath>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::uniform_real_distribution;
using std::normal_distribution;
using std::bernoulli_distribution;
using std::vector;
using std::string;

void generate_random()
{
    default_random_engine e;
    for(int i = 0;i<10;i++)
        cout<<e()<<" ";
    cout<<endl;
}
vector<unsigned> goodVec()
{
    //将这两个函数设置为static变量，那么避免了每次生成同样的序列的问题
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(0,9);
    vector<unsigned> ret;
    for(int i = 0;i<10;i++)
        ret.push_back(u(e));
    return ret;
}
//seed的作用是告诉engine从序列的什么位置进行生成
void test_seed()
{

    default_random_engine e1; // uses the default seed
    default_random_engine e2(2147483646); // use the given seed value

    // e3 and e4 will generate the same sequence because they use the same seed
    default_random_engine e3; // uses the default seed value
    e3.seed(32767); // call seed to set a new seed value
    default_random_engine e4(32767); // set the seed value to 32767

    default_random_engine e5;
    e5.seed(time(0));
    cout<<e5()<<endl;
    for (size_t i = 0; i != 100; ++i) {
        if (e1() == e2())
            cout << "unseeded match at iteration: " << i << endl;
        if (e3() != e4())
            cout << "seeded differs at iteration: " << i << endl;
    }

}

void normal_dis()
{
    default_random_engine e; // generates random integers
    normal_distribution<> n(4,1.5); // mean 4, standard deviation 1.5
    vector<unsigned> vals(9); // nine elements each 0
    for (size_t i = 0; i != 200; ++i) {
        unsigned v = lround(n(e)); // round to the nearest integer
        if (v < vals.size()) // if this result is in range
            ++vals[v]; // count how often each number appears
    }
    for (size_t j = 0; j != vals.size(); ++j)
        cout << j << ": " << string(vals[j], '*') << endl;
}
bool play(bool val)
{
    return val;
}
void bernoulli_dis()
{
    string resp;
    default_random_engine e; // e has state, so it must be outside the loop!
    bernoulli_distribution b; // 50/50 odds by default
    //bernoulli_distribution b(0.55)// give the house a slight edge
    do {
        bool first = b(e); // if true, the program will go first
        cout << (first ? "We go first"
                       : "You get to go first") << endl;
// play the game passing the indicator of who goes first
        cout << ((play(first)) ? "sorry, you lost"
                               : "congrats, you won") << endl;
        cout << "play again? Enter 'yes' or 'no'" << endl;
    } while (cin >> resp && resp[0] == 'y');
}

int main(int argc,char* argv[])
{
    vector<unsigned> ivec1;
    vector<unsigned> ivec2;
    generate_random();
    ivec1 = goodVec();
    ivec2 = goodVec();

    if(ivec1 == ivec2)
        cout<<"same"<<endl;
    else
        cout<<"diff"<<endl;

    test_seed();

    // empty <> signify we want to use the default result type
    // 注意 只有一个默认参数时 template的形式
    uniform_real_distribution<> u(0,1); // generates double by default

    default_random_engine e_float;

    cout<<u(e_float)<<endl;

    normal_dis();
    bernoulli_dis();

    return 0;
}
