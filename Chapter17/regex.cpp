#include <iostream>
#include <regex>
#include <string>
#include <exception>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::regex;
using std::sregex_iterator;
using std::regex_error;
using std::smatch;
using std::regex_constants::format_no_copy;

bool valid(const smatch& m)
{
    //如果区号前有一个括号
    if(m[1].matched)
    {
        //则区号后必须有一个右括号，之后紧跟剩余号码或一个空格
        return m[3].matched && (m[4].matched == 0|| m[4].str() == " "); 
    }
    else
    {
        //否则，区号后不能有右括号
        //另两个组成部分间的分隔符必须匹配
        return !m[3].matched && m[4].str() == m[6].str();
    }
}

int main(int argc,char* argv[])
{
    string pattern("[^c]ei");

    pattern = "[[:alpha:]]*"+pattern+"[[:alpha:]]*";
    
    regex r(pattern,regex::icase);
    smatch results;

    string test_str = "receipt freind theif receive";

    cout<<"===regex_search==="<<endl;
    if(regex_search(test_str,results,r))
    {
        cout<<results.str()<<endl;
    }
    cout<<"===sregex_iterator==="<<endl;
    //end_it 是一个空regex_iterator,起到尾后迭代器的作用。
    for(sregex_iterator it(test_str.begin(),test_str.end(),r),end_it;it != end_it;++it)
        cout<<it->str()<<endl;

    try{
        regex re("[[:alnums:]]+\\.(cpp|cxx|cc)$",regex::icase);
    }catch(regex_error e){
        cout<<e.what()<<"\ncode: " <<e.code()<<endl;
    }

    //子表达式
    string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    
    regex rp(phone);

    smatch m;

    string s;

    while(getline(cin,s))
    {
        for(sregex_iterator it(s.begin(),s.end(),rp),end_it;it != end_it;++it)
        {
            if(valid(*it))
            {
                cout<<"vaild: "<< it->str()<<endl;
            }
            else
            {
                cout<<"invaild "<< it->str()<<endl;
            }
        }
    }

    string fmt = "$2.$5.$7";//将号码改为ddd.ddd.dddd
    string fmt2 = "$2.$5.$7 ";

    string number = "(908) 555-1800 111-11-1111";

    cout << regex_replace(number,rp,fmt)<<endl;

     //通知regex_replace 只拷贝它替换的文本
     //regex_replace(seq,r,fmt,mft) or regex_replace(dest,seq,r,fmt,mft)
    cout << regex_replace(number,rp,fmt,format_no_copy)<<endl;

    return 0;
}