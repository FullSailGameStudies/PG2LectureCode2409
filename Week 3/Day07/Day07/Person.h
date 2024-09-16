#pragma once
#include <string>
class Person
{
public:
	Person(int age, std::string name);

	int Age() const { return age_; }
	void Age(int newAge)
	{
		if (newAge >= 0 && newAge <= 120)
			age_ = newAge;
	}

	std::string Name() { return name_; }
	void Name(std::string newName)
	{
		if (!newName.empty())
			name_ = newName;
	}

	void ItsMyBirthday();

private:
	int age_;
	std::string name_;
};

