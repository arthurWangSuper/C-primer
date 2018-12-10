#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct PersonInfo{
	string name;
	vector<string> phones;
};

int main(int argc,char**argv)
{
	string line,word;
	vector<PersonInfo> people;
	
	istringstream erecord;
	while(getline(cin,line))
	{
		PersonInfo info;

		erecord.str(line);
		istringstream record(line);
		record>>info.name;
		while(record>>word)
		{
			info.phones.push_back(word);
		}
		people.push_back(info);
	}
	
	return 0;
}
