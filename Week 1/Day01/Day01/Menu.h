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

