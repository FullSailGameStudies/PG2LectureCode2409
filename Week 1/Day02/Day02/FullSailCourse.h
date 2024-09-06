#pragma once
#include <string>
#include <vector>
class FullSailCourse
{
public:
	//getter
	std::string GetName();
	//setter
	void SetName(std::string& name);//pass-by-reference param

	void GetGrades(std::vector<float>& grades);

private:
	std::string name_;//field (data member)

};

