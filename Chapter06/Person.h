#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

class Person{
	public:
		Person() = default;
		~Person();
		string getName() const;
		string getAddress() const;
	private:
		string name;
		string address;
};	

Person::getName() const
{
	return this->name;
}
Person::getAddress() const
{
	return this->address;
}

#endif
