#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int val = -10; 

int get_size()
{
	return ++val;
}

int main()
{
	int ival=0; 
	while((val = get_size())<0);
		
	cout<<"keep going "<<endl;	
	return 0;
}
