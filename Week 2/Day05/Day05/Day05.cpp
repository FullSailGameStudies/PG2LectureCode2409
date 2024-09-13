// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

enum class Weapon
{
    Sword, Axe, Spear, Mace
};

const int NOT_FOUND = -1;

/// <summary>
/// Performs a linear search on the vector parameter.
/// </summary>
/// <param name="nums">Vector to search.</param>
/// <param name="numberToSearchFor">The number to find.</param>
/// <returns>-1 if not found. The index if found.</returns>
int LinearSearch(const std::vector<int>& nums, int numberToSearchFor)
{
    //start at the beginning
    for (int i = 0; i < nums.size(); i++)
    {
        //look for the search #
        if (numberToSearchFor == nums[i])
        {
            return i;//return the index
        }
    }
    return NOT_FOUND;//-1 means NOT FOUND
}




int main()
{
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE:

            write a method to linear search the numbers list.
                The method should take 2 parameters: vector of ints to search, int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    //N = 7 or the size of numbers
    std::vector<int> numbers = { 0,1,2,3,4,5,6 };
    int searchNumber = 0;
    int foundIndex = LinearSearch(numbers, searchNumber);
    if (foundIndex == NOT_FOUND)
    {
        std::cout << searchNumber << " was not found in the vector.\n";
    }
    else
    {
        std::cout << searchNumber << " was found at index " << foundIndex << "\n";
    }


    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys.
            TValue is a placeholder for the type of the values.

        When you want to create a map variable,
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a map:
        1) using the insert method.
        2) using [key] = value
    */
    std::map<std::string, double> menu;
    menu["Curry Eggs"] = 14.99;
    menu["Bacon"] = 6.99;
    menu["Bacon"] = 7.99;//overwrites the existing value


    //pairs have 2 members: first and second
    //map pairs: first is the key and second is the value
    std::pair<std::string, double> menuPair =
        std::make_pair<std::string, double>("Coffee",3.99);
    auto result = menu.insert(menuPair);//will NOT overwrite if the key is already there
    //pairs have 2 members: first and second
    //insert pair: 
    //  first is the iterator to the map's key-value pair
    //  second is the bool telling you if the pair was inserted or not
    if (result.second)
        std::cout << "The menu item was inserted.\n";
    else
        std::cout << "The menu item was already on the menu.\n";

    std::string itemName = "Bacon";
    //double price = menu[itemName];
    //std::cout << itemName << " costs " << price << "\n";
    //itemName = "Breakfast Burrito"; 
    //price = menu[itemName];//????
    auto foundMenuItemIter = menu.find(itemName);
    if (foundMenuItemIter == menu.end()) //not found
        std::cout << itemName << " is not on the menu.\n";
    else
    {
        //menu[itemName] *= 1.05;wasted effort b/c we already found the key
        double oldPrice = foundMenuItemIter->second;
        foundMenuItemIter->second *= 1.05;
        std::cout << itemName << " used to costs " << oldPrice << "\n";
        std::cout << itemName << " now costs " << menu[itemName] << "!!\n Thanks Putin!\n";
    }

    //DO NOT ASSUME the key is in the map and use [key] to lookup the value
    //DO NOT LOOP to find a key
    //for (auto& [name, menuprice] : menu)
    //{
    //    if(name == itemName){}
    //}

    std::pair<std::string, int> myEnum;
    myEnum.first = "YELLOW";
    myEnum.second = 2;




    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map


    /*
        CHALLENGE:

            Create a map that stores names (string) and numerical grades. 
            Call the variable grades.
            Add students and grades to your map.

    */
    srand(time(NULL));
    std::map<std::string, double> grades;
    std::vector<std::string> students = {
        "Brianna", "David", "Joshua", "Victor",
        "Valenco", "Matthew", "Malcolm", "Terry",
        "Andrew", "Aquaman"
    };
    for (auto& name : students)
    {
        grades[name] = (rand() % 10001) / 100.0;
    }

    std::cout << "\n\nPG2 Grades 2409\n";
    auto iter = grades.begin();
    while (iter != grades.end())
    {
        //first is the key, second is the value
        const std::string& name = iter->first;
        double& grade = iter->second;
        std::cout << std::setw(10) << std::left << name;
        std::cout << std::setw(7) << std::right << grade << "\n";
        ++iter;
    }


    std::cout << "\n\nPG2 Grades 2409\n";
    for (auto& [name,grade] : grades)
    {
        std::cout << std::setw(10) << std::left << name;
        std::cout << std::setw(7) << std::right << grade << "\n";
    }





    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }


    /*
        CHALLENGE:

            Loop over your grades map and print each student name and grade.

    */



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }



    /*
        CHALLENGE:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found

    */




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an exisiting value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



    /*
        CHALLENGE:

            Pick any student and curve the grade (add 5) that is stored in the grades map

    */
}