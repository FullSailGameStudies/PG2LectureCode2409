#pragma once
class Weapon
{
private:
	//non-static data. (each object has their own values)
	int mRange;
	int mDamage;

	//static data (shared data across ALL objects)
	static int mNumberOfWeaponsCreated;//only 1 of these created for the class

public:
	Weapon(int range, int damage);

	static void WeaponReport();

	virtual void showMe();
	int calcDamage();

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};


