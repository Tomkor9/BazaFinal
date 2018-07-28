#include "Person.hpp"
#include "Student.hpp"
#include "Employee.hpp"

#include <iostream>

/* PERSON CLASS */

void Person::show() {
	std::cout << name_ << " " << surname_ << ", " << PESEL_ <<
		", " << gender_ << ", " << address_ << "\n";
}

/* STUDENT CLASS */

void Student::show() {
	std::cout <<"["<< Student::alias_ << "] " << name_ << " " << surname_ << ", " << PESEL_ <<
		", " << gender_ << ", " << address_ <<", " << index_ << "\n";
}

	Student::Student(std::string name, std::string surname,
	std::string PESEL, std::string gender, std::string address, int index) {
	name_ = name;
	surname_ = surname;
	PESEL_ = PESEL;
	gender_ = gender;
	address_ = address;
	index_ = index;
}


/* EMPLOYEE CLASS */

void Employee::show() {
	std::cout << "[" << Employee::alias_ << "] " << name_ << " " << surname_ << ", " << PESEL_ <<
		", " << gender_ << ", " << address_ << ", " << salary_ << "$\n";
}

	Employee::Employee(std::string name, std::string surname,
	std::string PESEL, std::string gender, std::string address, float earnings){
	name_ = name;
	surname_ = surname;
	PESEL_ = PESEL;
	gender_ = gender;
	address_ = address;
	salary_ = earnings;
}