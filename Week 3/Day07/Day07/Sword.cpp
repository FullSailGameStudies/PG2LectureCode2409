#include "Sword.h"
#include <stdlib.h>

//initialize the fields with the Member Initialization List
// preferred method
Sword::Sword(WeaponMaterial material, int damage, bool twoHanded) :
	material_(material),
	damage_(damage),
	twoHanded_(twoHanded)
{
	twoHanded = twoHanded_;//backwards
	twoHanded_ = twoHanded;//correct

	//this-> is only really used to eliminate ambiguity for the compiler
}

int Sword::Hit()
{
	return rand() % damage_;
}
