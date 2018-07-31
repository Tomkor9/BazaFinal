#pragma once
#include <string>

class Student : public Person {
private:
	static const char alias_ = 's';
	int index_;

public:
	int getIndex() { return index_; }
	void setIndex(int index) { index_ = index; }

	void show();
	char getAlias() { return alias_; };
	
	Student(std::string name = "", std::string surname = "",
		std::string Pesel = "00000000000", std::string gender = "",
		int index = 0000, std::string address = "");

	//bad solution (virtual base class method restriction)
	float getSalary() { return -1.0F; }
	void setSalary(float DO_NOT) {}
};
