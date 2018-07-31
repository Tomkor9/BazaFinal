#include "Person.hpp"
#include "Student.hpp"
#include "Employee.hpp"

#include <iostream>

/* PERSON CLASS */

void Person::show() {
	std::cout << name_ << " " << surname_ << ", " << Pesel_ <<
		", " << gender_ << ", " << address_ << "\n";
}

/* STUDENT CLASS */

void Student::show() {
	std::cout <<"["<< Student::alias_ << "] " << name_ << " " << surname_ << ", " << Pesel_ <<
		", " << gender_ << ", " << address_ <<", " << index_ << "\n";
}

	Student::Student(std::string name, std::string surname,
	std::string Pesel, std::string gender, int index, std::string address) {
	name_ = name;
	surname_ = surname;
	Pesel_ = Pesel;
	gender_ = gender;
	address_ = address;
	index_ = index;
}


/* EMPLOYEE CLASS */

void Employee::show() {
	std::cout << "[" << Employee::alias_ << "] " << name_ << " " << surname_ << ", " << Pesel_ <<
		", " << gender_ << ", " << address_ << ", " << salary_ << "$\n";
}

	Employee::Employee(std::string name, std::string surname,
	std::string Pesel, std::string gender,  float earnings, std::string address){
	name_ = name;
	surname_ = surname;
	Pesel_ = Pesel;
	gender_ = gender;
	address_ = address;
	salary_ = earnings;
}
