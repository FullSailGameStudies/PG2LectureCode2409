#include <iostream>
#include "Weapon.h"


int Weapon::mNumberOfWeaponsCreated = 0;

Weapon::Weapon(int range, int damage) : mRange(range), mDamage(damage)
{
	mNumberOfWeaponsCreated++;
}

//static methods do NOT have a 'this' parameter
//static methods can ONLY access other static members
void Weapon::WeaponReport()
{
	//std::cout << mRange;//there is no this->
	std::cout << mNumberOfWeaponsCreated << " weapons created\n";
}

//non-static methods have a 'hidden' parameter
//  called 'this'
//non-static methods can access non-static AND static members
void Weapon::showMe()//(Weapon* this)
{
	std::cout << "Range: " << mRange << 
				" Damage: " << mDamage << "\n";
}

int Weapon::calcDamage()
{
	return rand() % (mDamage+1);
}
