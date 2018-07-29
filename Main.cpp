// BazaFinal.cpp : Defines the entry point for the console application.
//
#include "Interface.hpp"
#include "Person.hpp"
#include "Employee.hpp"
#include "Student.hpp"

#include <iostream>

int main()
{
	Interface I;

	debugFill(I);

	I.displayRecords();
	I.sortByEarnings();
	I.deleteByPESEL("83018503020");
	I.displayRecords();
	I.findBySurname("Kowalewicz");
	
	std::cin.get();
    return 0;
}

