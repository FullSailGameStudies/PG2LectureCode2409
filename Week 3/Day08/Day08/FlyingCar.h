#pragma once
#include "Car.h"
class FlyingCar : public Car
{
public:
	//CTORs
	//  derived ctor MUST call a base ctor
	FlyingCar(int year, std::string make, std::string model, 
			  float maxAltitude, float maxAirspeed)
		: Car(year,make,model),
		maxAltitude_(maxAltitude), maxAirspeed_(maxAirspeed)
	{
		//DO NOT do what the base ctor does.
	}

	std::string vehicleInformation() override;
	//override keyword is optional
	//override makes sure this is actually an override

	void sampple()
	{
		//mFuelLevel++;
		fuelLevel(10);
	}
protected:
private:
	float maxAltitude_, maxAirspeed_;
public:
};

