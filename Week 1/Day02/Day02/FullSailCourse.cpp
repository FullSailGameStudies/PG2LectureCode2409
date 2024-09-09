#include "FullSailCourse.h"

std::string FullSailCourse::GetName() const
{
    //SetName("Gotham");
    //name_ = "Gotham";
    return name_;
}

void FullSailCourse::SetName(const std::string& name)//pass-by-ref parameter (an ALIAS is made)
{
    if (name.size() > 0)
        name_ = name;
}

void FullSailCourse::GetGrades(std::vector<float>& pg2grades)
{
    //add 10 grades to the vector
    for (size_t i = 0; i < 10; i++)
    {
        float grade = (rand() % 10001)/100.0f;//0-100
        pg2grades.push_back(grade);
    }
}

void FullSailCourse::GetMinMax(const std::vector<float>& grades, float& min, float& max)
{
    min = max = grades[0];
    for (size_t i = 1; i < grades.size(); i++)
    {
        if (min > grades[i]) min = grades[i];
        if (max < grades[i]) max = grades[i];
    }
}
