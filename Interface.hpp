#pragma once

#include "Person.hpp"
#include "Student.hpp"
#include "Employee.hpp"

#include <vector>
#include <memory>

class Interface{

private:
	std::vector< std::unique_ptr<Person> > database_;
	void LoadContent(std::vector<std::string>&);

public:
	//universal
	void addNewPerson( std::unique_ptr<Person> person );
	void deleteByPESEL(std::string PESEL);
	int findBySurname(std::string surname);
	int findByPESEL(std::string PESEL);
	void sortByName();
	void sortByPESEL();
	void displayRecords();
	bool changeAddress(std::string PESEL, std::string address);
	bool checkPESEL(std::string PESEL);
	void mockData();

	void exportToFile(char *);
	void importFromFile(char *);

	//employee specyfic
	void sortByEarnings();
	bool changeEarnings(std::string PESEL, float ernings);

	//student specyfic
	void sortByIndex();
	void deleteByIndex(int);
};

//fills vector with static data
void debugFill(Interface &I);