#pragma once
#include <climits>

class Employee : public Person {
private:
	static const char alias_ = 'e';
	float salary_;

public:
	float getSalary() { return salary_; }
	void setSalary(float salary) { salary_ = salary; }

	void show();

	Employee(std::string name = "", std::string surname = "",
		std::string PESEL = "00000000000", std::string gender = "", 
		std::string address = "", float earnings = 0.0F);

	//bad solution (virtual base class method restriction)
	int getIndex() { return INT_MAX; }
	
};