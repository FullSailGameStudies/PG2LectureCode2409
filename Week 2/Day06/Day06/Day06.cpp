// Day06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <iomanip>


enum class Weapon
{
    Sword, Axe, Spear, Mace
};

void PrintGrades(const std::map<std::string, double>& grades)
{
    std::cout << "\n     DCU Grades\n";
    std::cout << "----------------------\n";
    for (auto& [student,grade] : grades)
    {
        std::cout << std::setw(9) << std::left << student;
        std::cout << std::setw(7) << std::right << grade << "\n";
    }
}


int main()
{

    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Removing a key and its value from a map  ]

        erase(iterator) -- returns an iterator that points to the first item AFTER the ones that were removed OR end() if no element exist
        erase(key) -- returns the # of items removed

    */
    std::map<Weapon, int> dorasBackpack;
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    dorasBackpack[Weapon::Axe] = 3;

    dorasBackpack.erase(Weapon::Spear);

    size_t numberRemoved = dorasBackpack.erase(Weapon::Sword);
    if (numberRemoved > 0)
        std::cout << "The Swords were removed.\n";
    else
        std::cout << "Sword was not found in the map.\n";

    std::map<Weapon, int>::iterator found = dorasBackpack.find(Weapon::Axe);
    if (found != dorasBackpack.end())
    {
        //dorasBackpack.erase(Weapon::Axe);//not be good
        dorasBackpack.erase(found);//better!
        std::cout << "The Axes were removed.\n";
    }
    else
        std::cout << "Axe was not found in the map.\n";





    /*
        CHALLENGE 1:

                    print the students and grades below
                        use std::setw and std::left and std::right to format the output
                    ask for the name of the student to drop from the grades map
                        use std::getline to get the user's input
                    remove the student from the map
                    print message indicating what happened
                        if not found print an error message
                        else print the map again and print that the student was removed


    */
    srand((unsigned int)time(NULL));
    std::map<std::string, double> grades;
    grades["Bruce"] = rand() % 101;
    grades["Dick"] = rand() % 101;
    grades["Diana"] = rand() % 101;
    grades["Alfred"] = rand() % 101;
    grades["Clark"] = rand() % 101;
    grades["Arthur"] = rand() % 101;
    grades["Barry"] = rand() % 101;

    do
    {
        PrintGrades(grades);

        std::string student;
        std::cout << "Student to drop? ";
        std::getline(std::cin, student);
        if (student.empty()) break;

        for (char& c : student) c = tolower(c);
        student[0] = std::toupper(student[0]);

        auto foundStudent = grades.find(student);
        if(foundStudent != grades.end())
        {
            std::cout << student << " had a grade of " << foundStudent->second << ".\n";
            grades.erase(foundStudent);
            std::cout << student << " was dropped from the DCU.\n";
        }
        else
            std::cout << student << " was not enrolled in the DCU.\n";

        //size_t count = grades.erase(student);
        //if (count > 0)
        //{
        //    std::cout << student << " was dropped from the DCU.\n";
        //}
        //else
        //    std::cout << student << " was not enrolled in the DCU.\n";

    } while (true);
}