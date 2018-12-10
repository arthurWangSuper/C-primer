#include <iostream>
#include <sstream>
#include <string>

using namespace std;

istream& readout(istream& is)
{
	string str;
	while(!(is>>str).eof())
	{
		cout<<str<<endl;		
	}
	//auto关键字，在编译器确定？
	auto isstate = is.rdstate();
	is.clear();
	
	return is;
}

int main(int argc,char**argv)
{
	string sstr;
	getline(cin,sstr);
	istringstream ss(sstr);
	readout(ss);
	return 0;
}
