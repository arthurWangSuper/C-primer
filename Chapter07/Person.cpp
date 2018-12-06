#include <iostream>
#include <string>

using namespace std;

class Person
{
	public:
		Person()=default;
		Person(string pername,int age):Name(pername),age(age){}
		const string& getName() const;
		int getAge() const; 
		int setAge();
		int printInfo()
		{
			cout<<"name = "<<this->Name<<",age = "<<this->age<<endl;
		}
	private:
		const string Name;
		int age = 0;
};

inline
int Person::getAge() const
{
	return age;
}
inline 
const string& Person::getName() const
{
	return 	Name;
}



int main(int argc,char** argv)
{
	Person *ars = new Person("arsenal",19);
	
	ars->printInfo();
	cout<<ars->getAge()<<endl;
	return 0;
}
