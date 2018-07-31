// BazaFinal.cpp : Defines the entry point for the console application.
//
#include "Interface.hpp"
#include "Person.hpp"
#include "Employee.hpp"
#include "Student.hpp"

#include <iostream>

int main()
{
    bool result;
    Interface I;

    debugFill(I);

    I.displayRecords();
    I.sortByEarnings();

    result = I.checkPesel("83012312954"); //pesel is correct
    std::cout << "Pesel is valid: " << std::boolalpha<<result<<std::endl;
    result = I.checkPesel("83012312953"); //pesel is incorrect
    std::cout << "Pesel is valid: " << std::boolalpha<<result<<std::endl;
    result = I.checkPesel("8301231295"); //pesel is incorrect
    std::cout << "Pesel is valid: " << std::boolalpha<<result<<std::endl;

    I.displayRecords();
    I.findBySurname("Kowalewicz");
	
    std::cin.get();
    return 0;
}

