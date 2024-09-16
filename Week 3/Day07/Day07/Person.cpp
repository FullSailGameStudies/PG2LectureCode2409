#include "Person.h"
#include <iostream>

Person::Person(int age, std::string name) :
	name_(name),
	age_(age)
{
}

void Person::ItsMyBirthday()
{
	age_++;
	std::cout << "It's my birthday! I'm " << age_ << " years old today.\n";
	std::cout << "Let's have some cake!!\n";
}
