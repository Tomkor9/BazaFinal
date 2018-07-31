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
	char getAlias() { return alias_; };

	Employee(std::string name = "", std::string surname = "",
		std::string Pesel = "00000000000", std::string gender = "",
		float earnings = 0.0F, std::string address = "");

	//bad solution (virtual base class method restriction)
	int getIndex() { return INT_MAX; }
	
};
