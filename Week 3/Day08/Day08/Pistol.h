#pragma once
#include "Weapon.h"
#include <utility>
#include <stdlib.h>
class Pistol : public Weapon
{
public:
	Pistol(int range, int damage, int rounds, int magCapacity) :
		Weapon(range, damage),
		rounds_(rounds),
		magCapacity_(magCapacity)
	{
	}
	int Rounds() const { return rounds_; }
	void Rounds(int rounds) {
		if (rounds >= 0 && rounds <= magCapacity_)
			rounds_ = rounds;
	}

	int MagCapacity() const { return magCapacity_; }
	void MagCapacity(int newCapacity)
	{
		if (newCapacity > 0 && newCapacity < 20)
			magCapacity_ = newCapacity;
	}

	int calcDamage() override
	{
		return rand() % (damage() + 1);
	}

	Pistol operator+(const Pistol& otherGun)
	{
		int rounds = otherGun.rounds_;
		rounds = std::min(magCapacity_, rounds_ + rounds);
		Pistol newGun(range(), damage(), rounds, magCapacity_);
		return newGun;
	}

private:
	int rounds_, magCapacity_;
};