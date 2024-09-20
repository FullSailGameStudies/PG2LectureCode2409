// Day08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Inheritance.h"
#include "Polymorphism.h"
#include "Car.h"
#include "FlyingCar.h"
#include "Pistol.h"
#include <vector>


void Looper()
{
	static int i = 0;
	std::cout << i << "\n";
	i++;
}

int main()
{
	for (size_t i = 0; i < 10; i++)
	{
		Looper();
	}
	/*
        ╔═══════════════╗
        ║  Inheritance  ║
        ╚═══════════════╝

								╔═════════╗     ╔══════════╗
				         class  ║SomeClass║  :  ║OtherClass║
								╚═════════╝     ╚══════════╝
									 │                │
									 └──┐             └──┐
								   ┌────▼────┐      ┌────▼────┐
								   │ Derived │      │  Base   │
								   │  Class  │      │  Class  │
								   └─────────┘      └─────────┘

			Access modes:
				public inheritance:
				protected inheritance:
				private inheritance: (default if not specified)
	


				CONSTRUCTORS: the derived constructor must call a base constructor
				public SomeClass(.....) : baseClass(....)


			Lecture Code: add a FlyingCar class that derives from Car
             
    */
	Car myCar(1985,"Ford", "Mustang GT");
	Car wifesCar(2015, "Ford", "GT");

	myCar.refuel();
	wifesCar.refuel(5);
	wifesCar.refuel(3.5F);

	//base ctors is called first
	//then the derived ctor is called
	FlyingCar delorean(2025,"Tesla","Cyberplane",5000,120);

	std::vector<Car> myGarage;
	myGarage.push_back(delorean);//??? we'll need POINTERS!!! to make this work

	std::cout << "G's Garage\n";
	std::cout << myCar.vehicleInformation() << "\n" << wifesCar.vehicleInformation();
	std::cout << "\n" << delorean.vehicleInformation() << "\n";

	//Weapon knife(3, 10);

	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

            add a new class, Pistol, that derives from Weapon.
            Pistol should have fields with getters/setters 
				for rounds and magCapacity.
            Add a constructor that calls the base constructor
	
	*/
	Pistol pewpew(100,50,10,15);
	Pistol throwAway(10, 10, 5, 10);
	pewpew = pewpew + throwAway;






	/*
        ╔═════════════════════════════╗
        ║  COMPILE-TIME Polymorphism  ║
        ╚═════════════════════════════╝

		Method Overloading:
			- changing the number of parameters
			- changing the types of the parameters

		Lecture Code: Overload the refuel method in Car

	*/



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

			Add an OVERLOAD of the calcDamage method in the Weapon class.
			The overload should take an int parameter called modifier
			to increase the damage when calculating the damage.

	*/





	/*
        ╔═════════════════════════════╗
        ║  COMPILE-TIME Polymorphism  ║
        ╚═════════════════════════════╝

		Operator Overloading

		Lecture Code: overload the + operator in Account

	*/



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

		overload the + in the Pistol class to add 2 pistols
			- it sets the magCapacity to the max of the 2 pistols
			- adds the # of rounds from both pistols. should not exceed the magCapacity.
	*/






	/*
        ╔════════════════════════╗
        ║  RUNTIME Polymorphism  ║
        ╚════════════════════════╝

		╔═════════════╗
		║ OVERRIDING  ║ - changing the behavior of a base method
		╚═════════════╝

		1) add 'virtual' to the base method
		2) add a method to the derived class that has the same signature as the base.
			OPTIONALLY put 'override' on the derived method


		FULLY OVERRIDING:
			not calling the base method from the derived method

		EXTENDING:
			calling the base method from the derived method
			to call the base method...  baseClassName::method(...)



		Lecture Code: override the print method in the base/derived classes in the Polymorphism.h file

	*/



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

			Override Weapon's showMe method in the Pistol class.
			In Pistol's version, call the base version then print out the rounds and magCapacity



	*/



}

