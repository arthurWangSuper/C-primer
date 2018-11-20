#include<iostream>

using namespace std;

int main()
{
	int i=0, &r1=i;
	double d=0, &r2=d;
	int &r3 = i;	
	
	r2 = 3.14159;
	r2 = r1;
	i = r2;
	r1 = d;
	i = 5;
	r1 = 10;
	r3 =20;
 
	cout<<i<<" "<<d<<" "<<r1<<" "<<r2<<endl;
	return 0;
}
