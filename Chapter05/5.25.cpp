#include<iostream>
#include<stdexcept>

using namespace std;

int main()
{
	int a,b;

	try
	{
		cin>>a>>b;
		if(b==0)
			throw(runtime_error("被除数不得为0"));
		
	}
	catch(runtime_error)
	{
		cout<<"catch U!"<<endl;
	}
	return 0;
}
