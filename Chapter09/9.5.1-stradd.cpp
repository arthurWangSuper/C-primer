#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(int argc,char**argv)
{
	
	vector<char> charvec{'h','e','l','l','o'};
	
	vector<char>::iterator itbegin = charvec.begin();	
	vector<char>::iterator itend = charvec.end();

	string s(itbegin,itend);

	const char* pstr = "hello world";
	/*pstr is pointer to array*/
	string s1(pstr);
	cout<<s1<<endl;
	/*copy first 3 charactor*/
	string s2(s1,6);
	cout<<s2<<endl;

	/*copy 4 charactors from pos 2*/
	string s3(s1,2,4);
	cout<<s3<<endl;

	string s4(pstr+6,6);
	cout<<s4<<endl;

	/*operation*/
	unsigned istr =1234;

	string str = to_string(istr);
	/* stoi(string&,size_t*,int _base) _base:表示多少进制*/
	unsigned si = stoi(str,0,10);
	
	string strs = "abc1345";
	unsigned ssi = stoi(strs.substr(strs.find_first_of("+-.012345678")));
	
	cout<<si<<endl;
	cout<<ssi<<endl;

	string strA = "abcssssdf";
	string patternstr1 = "df";
	string patternstr2 = "ds";

	cout<<strA.find(patternstr1)<<endl;

	if(strA.find(patternstr2)==string::npos)
	{
		cout<<"cannot find"<<endl;
	}

	return 0;
}
