#pragma once

#include "Person.hpp"
#include "Student.hpp"
#include "Employee.hpp"

#include <vector>
#include <memory>

class Interface{

private:
	std::vector< std::unique_ptr<Person> > database_;
	void loadContent(std::vector<std::string>&);

public:
	//universal
	void addNewPerson( std::unique_ptr<Person> person );
	void deleteByPesel(std::string Pesel);
	int findBySurname(std::string surname);
	int findByPesel(std::string Pesel);
	void sortByName();
	void sortByPesel();
	void displayRecords();
	bool changeAddress(std::string Pesel, std::string address);
	bool checkPesel(std::string Pesel);
	void mockData(int instances);

	void exportToFile(char *);
	void importFromFile(char *);

	//employee specyfic
	void sortByEarnings();
	bool changeEarnings(std::string Pesel, float ernings);

	//student specyfic
	void sortByIndex();
	void deleteByIndex(int);
};

//fills vector with static data
void debugFill(Interface &I);
