#include "Menu.h"
#include <iostream>
//DEFINITION
void Menu::AddMenuItem(std::string itemToAdd)
{
	menuItems.push_back(itemToAdd);
}
void Menu::RemoveMenuItem(std::string itemToRemove)
{
	std::cout << "\n\nIterator for loop\n";
	for (std::vector<std::string>::iterator i = menuItems.begin(); i != menuItems.end(); i++)
	{
		//use * on the iterator to get to the string
		std::string item = *i;
		if (item == itemToRemove)//case sensitive comparison
		{
			menuItems.erase(i);//i is an iterator
			break;
		}
	}
	for (int i = 0; i < menuItems.size(); i++)
	{
		//i is the index into the vector
		if (itemToRemove == menuItems[i])
		{
			menuItems.erase(menuItems.begin() + i);//i is an index
		}

	}

}
void Menu::ShowMenu()
{
	//for loop
	std::cout << "\n\nFor loop\n";
	for (int i = 0; i < menuItems.size(); i++)
	{
		//i is the index into the vector
		std::cout << i+1 << ". " << menuItems[i] << "\n";

	}

	//range-based for loop
	std::cout << "\n\nrange-based loop\n";
	for (std::string item : menuItems)
	{
		std::cout << item << "\n";
	}

	//first index: 0
	//last index: size()-1
	// 
	//for loop with iterators
	//begin() gives an iterator to the first item
	//end() gives an iterator to AFTER the last item
	//std::vector<std::string>::iterator OR auto
	std::cout << "\n\nIterator for loop\n";
	for (std::vector<std::string>::iterator i = menuItems.begin(); i != menuItems.end(); i++)
	{
		//use * on the iterator to get to the string
		std::string item = *i;
		std::cout << item << "\n";
	}

}