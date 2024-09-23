// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>



/*
    ╔══════════╗
    ║ File I/O ║
    ╚══════════╝

    3 things are required for File I/O:
    1) Open the file
    2) read/write to the file
    3) close the file



*/
int main()
{
    std::cout << "Hello PG2!\n";

    std::string path = "C:\\temp\\2409\\";
    std::string fileName = "PG2_2409.csv";
    std::string fullPath = path + fileName;
    //1) Open the file
    std::ofstream outFile(fullPath);
    char delimiter = '$';
    if (outFile.is_open())
    {
        //2) write to the file
        outFile << "Batman was here.";
        outFile << delimiter << "D5"
            << delimiter << 13.7 
            << delimiter << true;
    }
    else
    {
        std::cout << fullPath << " could not be opened.\n";      
    }

    //3) CLOSE the file
    outFile.close();


    /*

        ╔════════════════╗
        ║ write csv data ║
        ╚════════════════╝

        [  Open the file  ]
        [  Write to the file  ]
        [  Close the file  ]

        you need the path to the file
            use full path ( drive + directories + filename )
            or use relative path ( directories + filename )
            or current directory ( filename )

        Make sure to separate the data in the file with a delimiter.
        The delimiter is important because it is used
            to separate the data when reading the file back in.


        Lecture code: set a filePath variable, open an output file, write some csv data to it
    */


    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

        Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
    */
    std::string userData;
    std::cout << "Please enter something: ";
    std::getline(std::cin, userData);


    //1) Open the file to read it
    std::ifstream inFile(fullPath);
    if (inFile.is_open())
    {
        //read the file
        std::string line;
        std::getline(inFile, line);//read up to a \n
        std::cout << "DATA: " << line << "\n";

        std::stringstream lineStream(line);//convert the string to an input stream
        std::string data;
        std::getline(lineStream, data, delimiter);
        std::cout << data << "\n";
        
        try
        {
            std::getline(lineStream, data, delimiter);
            int number = std::stoi(data);

            std::getline(lineStream, data, delimiter);
            double dVal = std::stod(data);

            std::getline(lineStream, data, delimiter);
            bool bVal = (bool)std::stoi(data);
        }
        catch(const std::exception& ex)
        {
            std::cout << ex.what() << "\n";
        }
    }
    else
    {
        std::cout << fullPath << " could not be opened.\n";
    }

    //3) close the file
    inFile.close();


    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

        Lecture code: 
            using the line read in above, use a stringstream to split the line using getline.
            store the separate items in a vector
            parse each item in the vector to an appropriate variable.
        

    */





    /*

        CHALLENGE:

        Parse the multi csv string (below) to get the data.
        NOTE: the data is a collection of object data.
        There are multiple delimiters.
        Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
        Then, separate the object csv data on objectSeparator to get the details of the object.

        EX: hero#hero#hero   each hero is separated by a #
            name^secret^age  the details of each hero is separated by a ^

    */
    std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
    char collectionSeparator = '#';
    char objectSeparator = '^';
    //Hero:   Secret:  Age: 
    std::stringstream heroesStream(multi);
    std::string heroData;
    std::cout << "\nHeroes...\n";
    while (std::getline(heroesStream, heroData, collectionSeparator))
    {
        std::cout << "heroData: " << heroData << "\n";

        std::string name, secret, ageString;
        int age;
        std::stringstream heroStream(heroData);
        std::getline(heroStream, name, objectSeparator);
        std::getline(heroStream, secret, objectSeparator);
        std::getline(heroStream, ageString, objectSeparator);
        age = std::stoi(ageString);

        std::cout << "Hero: " << name << "\nSecret: " << secret;
        std::cout << "\nAge: " << age << "\n\n";
    }
}