#pragma once
#include <string>
#include <vector>
class FullSailCourse
{
public:
	//getter
	std::string GetName() const;
	//setter
	void SetName(const std::string& name = "PG2");//pass-by-reference param

	void GetGrades(std::vector<float>& grades);

	void GetMinMax(const std::vector<float>& grades, float& min, float& max);

private:
	std::string name_;//field (data member)

};

