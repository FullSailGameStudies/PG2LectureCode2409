#pragma once
#include <string>

class Car
{
public:
	//Car() : mMake("Ford"), mModel("A"), mModelYear(1908), mFuelLevel(0), mMaxFuelLevel(15)
	//{   }

	Car(int year, std::string make, std::string model)
		: mModelYear(year), mMake(make), mModel(model), mFuelLevel(0), mMaxFuelLevel(15)
	{	}
	virtual std::string vehicleInformation();

	void refuel()
	{
		mFuelLevel = mMaxFuelLevel;
	}
	void refuel(int fuelToAdd)//overload of the refuel method
	{
		mFuelLevel = std::min(mMaxFuelLevel, mFuelLevel + fuelToAdd);
	}
	void refuel(float fuelToAdd)//overload of the refuel method
	{
		mFuelLevel = std::min<int>(mMaxFuelLevel, (int)(mFuelLevel + fuelToAdd));
	}

	//getter (accessor)
	int modelYear() const
	{
		return mModelYear;
	}

	//setter (mutator)
	void modelYear(int newModelYear)
	{
		if (newModelYear > 1908 && newModelYear < 2100)
		{
			mModelYear = newModelYear;
		}
	}

	void fuelLevel(int newFuelLevel)
	{
		mFuelLevel = newFuelLevel;
	}

private:
	int mModelYear;
	std::string mModel;
	std::string mMake;

	int mFuelLevel;
	int mMaxFuelLevel;

private:
};


