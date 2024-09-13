#pragma once
#include <vector>
#include <string>
class Menu
{
public:
	void AddMenuItem(std::string itemToAdd);//DECLARATION
	void ShowMenu();
	void RemoveMenuItem(std::string itemToRemove);

private:
	std::vector<std::string> menuItems;
};

class Person
{
public:
	void SetAge(int age = 12);

private:
	int age_;
};

void Person::SetAge(int age)
{
	age_ = age;
}