#include "Interface.hpp"

#include <iostream>
#include <algorithm>

/* UNIVERSAL METHODS */

void Interface::addNewPerson(std::unique_ptr<Person> person){
	database_.push_back(std::move(person));
}

void Interface::deleteByPESEL(std::string PESEL) {
		for (size_t i = 0; i < database_.size(); i++)
			if (database_.at(i)->getPESEL() == PESEL)
				database_.erase(database_.begin() + i);
}

int Interface::findBySurname(std::string surname){
	for (size_t i = 0; i < database_.size(); i++)
		if (database_.at(i)->getSurname() == surname) {
			database_.at(i)->show();
			return i;
		}         //prints result and outputs index
	return -1;    //-1 means: no index found
}

int Interface::findByPESEL(std::string PESEL){
	for (size_t i = 0; i < database_.size(); i++)
		if (database_.at(i)->getPESEL() == PESEL) {
			database_.at(i)->show();
			return i;
		}         //prints result and outputs PESEL
	return -1;    //-1 means: no index found
}

void Interface::sortByName(){
	if (!database_.empty())
		sort(database_.begin(), database_.end(),
			[](const std::unique_ptr<Person>& p1, const std::unique_ptr<Person>& p2) {
		return  p1->getName() < p2->getName();
	});
}

void Interface::sortByPESEL(){
	if (!database_.empty())
		sort(database_.begin(), database_.end(),
			[](const std::unique_ptr<Person>& p1, const std::unique_ptr<Person>& p2) {
		return  p1->getPESEL() < p2->getPESEL();
	});
}

void Interface::displayRecords() {

	if (!database_.empty()) {
		std::cout << "RECORD LIST:\n";
		for (size_t i = 0; i < database_.size(); i++) {
			std::cout << i + 1 << ". "; database_.at(i)->show();
		}
		std::cout << "\n";
	}
}

bool Interface::changeAddress(std::string PESEL, std::string address){
	for (size_t i = 0; i < database_.size(); i++)
		if (database_.at(i)->getPESEL() == PESEL) {
			database_.at(i)->setAddress(address);
			return true;
		}        
	return false;    
}

//TO DO! (STL functor / algorithm / isalpha)
bool Interface::checkPESEL(std::string PESEL){
	if (PESEL.size() != 11)
		return false;
	return true;
}

//TO DO! (algorithm!)
void Interface::mockData(){
}

//TO DO! (modify old)
void Interface::exportToFile(char *){
}

//TO DO! (modify old)
void Interface::importFromFile(char *){
}

void debugFill(Interface &I) {
	std::unique_ptr<Person> s1(new Student("Jack", "Berenz",
		"83018503020", "male", "Zurawia 7, Wroclaw", 3210));

	std::unique_ptr<Person> s2(new Student("Annabelle", "Savage",
		"66674366610", "female", "Minor st. 3, LA ", 6661));

	std::unique_ptr<Person> e1(new Employee("Wayne", "Static",
		"47392040165", "male", "Sandy Roads 13, Joshua Tree", 3800.0F));

	std::unique_ptr<Person> e2(new Employee("Ben", "Kowalewicz",
		"16421041288", "male", "Maple st. 65, Ottawa", 6000.0F));

	std::unique_ptr<Person> e3(new Employee("Anna", "Grodzki",
		"20231231654", "neuter", "Karczewska 29, Otwock", 8000.0F));
	
	I.addNewPerson(std::move(e1));
	I.addNewPerson(std::move(e2));
	I.addNewPerson(std::move(e3));
	I.addNewPerson(std::move(s2));
	I.addNewPerson(std::move(s1));
}

/* EMPLOYEE SPECYFIC */

void Interface::sortByEarnings(){
	if (!database_.empty())
		sort(database_.begin(), database_.end(),
			[](const std::unique_ptr<Person>& p1, const std::unique_ptr<Person>& p2) {
		return  p1->getSalary() > p2->getSalary();
	});
}

bool Interface::changeEarnings(std::string PESEL, float earnings){
	for (size_t i = 0; i < database_.size(); i++)
		if (database_.at(i)->getPESEL() == PESEL) {
			database_.at(i)->setSalary(earnings);
			return true;
		}
	return false;
}

/* STUDENT SPECYFIC */

void Interface::sortByIndex(){
	
	if (!database_.empty())
		sort(database_.begin(), database_.end(),
			[](const std::unique_ptr<Person>& s1, const std::unique_ptr<Person>& s2) {
		return  s1->getIndex() < s2->getIndex(); 
	});
}

void Interface::deleteByIndex(int index){
	for (size_t i = 0; i < database_.size(); i++)
		if (database_.at(i)->getIndex() == index)
			database_.erase(database_.begin() + i);
}

/* PRIVATE - HIDDEN */

//TO DO! (modify old)
void Interface::LoadContent(std::vector<std::string>&){
}
