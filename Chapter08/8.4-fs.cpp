#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string filename = "testfs.txt";
vector<string>& readandprint(vector<string>& strvec)
{
	string str;

	ifstream input(filename);
/*8.4 and 8.5*/
#if 0
	while(getline(input,str))
	{
		strvec.push_back(str);
	}
#else
	while(input>>str)
	{
		strvec.push_back(str);
	}
#endif
	return strvec;
}
int printvec(vector<string>& strvec)
{
	vector<string>::iterator it = strvec.begin();
	
	for(;it != strvec.end();it++)
	{
		cout<<*it<<endl;
	}

}
int main(int argc,char**argv)
{
	vector<string> filecon;
	readandprint(filecon);
	printvec(filecon);
	return 0;
}
