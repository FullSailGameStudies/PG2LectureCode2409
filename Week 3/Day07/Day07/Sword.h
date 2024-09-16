#pragma once
#include "Color.h"
enum WeaponMaterial
{
	Steel,
	Bronze,
	Wood,
	Iron
};

//PascalNamingConvention
// 
//the compiler will create a default ctor IFF we do not create any constructor
//as soon as we create any ctor, the compiler's default is not longer created
class Sword
{
public:
	//CONSTRUCTORS
	// have the same EXACT name as the class
	// NO return type. not even void.
	// need to initialize the fields of the class
	Sword()
	{
		material_ = WeaponMaterial::Wood;
		damage_ = 5;//?
		twoHanded_ = false;//??
	}
	Sword(WeaponMaterial material, int damage, bool twoHanded);
	
	//PascalNamingConvention
	int Hit();//declaration

	//getters (accessors)
	//	no parameters
	//	const
	//	return type is the same type as the field
	WeaponMaterial GetMaterial() const
	{
		return material_;
	}
	int Damage() const { return damage_; }
	bool IsTwoHanded() const { return twoHanded_; }

	//setters (mutators)
	//	void return type (they don't return data)
	//	parameter of the same type as the field
	void SetMaterial(WeaponMaterial newMaterial)
	{
		if (material_ != WeaponMaterial::Wood &&
			newMaterial != WeaponMaterial::Wood)
		{
			material_ = newMaterial;
		}
	}
	void Damage(int newDamage)//overload
	{
		if (newDamage > 0 && newDamage < 100)
			damage_ = newDamage;
	}

private:
	//damage, durability, material, length, two-handed
	//crafter
	//camelCasingNamingConvention_
	int damage_;//m_iDamage  m_damage  mDamage _damage damage_
	WeaponMaterial material_;
	bool twoHanded_;

	//void Method(int damage)
	//{
	//	int damage;
	//	damage_ = 5;
	//}
};

