#include "Interface.hpp"

#include <iostream>
#include <algorithm>
#include <fstream>

/* UNIVERSAL METHODS */

void Interface::addNewPerson(std::unique_ptr<Person> person){
	database_.push_back(std::move(person));
}

void Interface::deleteByPesel(std::string Pesel) {
		for (size_t i = 0; i < database_.size(); i++)
			if (database_.at(i)->getPesel() == Pesel)
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

int Interface::findByPesel(std::string Pesel){
	for (size_t i = 0; i < database_.size(); i++)
		if (database_.at(i)->getPesel() == Pesel) {
			database_.at(i)->show();
			return i;
		}         //prints result and outputs Pesel
	return -1;    //-1 means: no index found
}

void Interface::sortByName(){
	if (!database_.empty())
		sort(database_.begin(), database_.end(),
			[](const std::unique_ptr<Person>& p1, const std::unique_ptr<Person>& p2) {
		return  p1->getName() < p2->getName();
	});
}

void Interface::sortByPesel(){
	if (!database_.empty())
		sort(database_.begin(), database_.end(),
			[](const std::unique_ptr<Person>& p1, const std::unique_ptr<Person>& p2) {
		return  p1->getPesel() < p2->getPesel();
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

bool Interface::changeAddress(std::string Pesel, std::string address){
	for (size_t i = 0; i < database_.size(); i++)
		if (database_.at(i)->getPesel() == Pesel) {
			database_.at(i)->setAddress(address);
			return true;
		}        
	return false;    
}

bool Interface::checkPesel(std::string Pesel){
	std::vector<int> vect_Pesel;

	for (size_t i = 0; i < Pesel.size(); ++i)
		vect_Pesel.push_back(Pesel[i] - '0');

	// >for testing/debug purpose
	// for (std::vector<int>::const_iterator i = vect_Pesel.begin(); i != vect_Pesel.end(); ++i)
	//         std::cout << *i << ' ';

	// calculate sum
	int sum;
	sum = vect_Pesel[0] * 1 +
		vect_Pesel[1] * 3 +
		vect_Pesel[2] * 7 +
		vect_Pesel[3] * 9 +
		vect_Pesel[4] * 1 +
		vect_Pesel[5] * 3 +
		vect_Pesel[6] * 7 +
		vect_Pesel[7] * 9 +
		vect_Pesel[8] * 1 +
		vect_Pesel[9] * 3;
	sum = (10 - sum % 10) % 10;

	// final validation
	if (vect_Pesel.size() != 11)
		return false;
	if (sum == vect_Pesel[10])
		return true;
	else
		return false;
}

//Generating random data - in progress
void Interface::mockData(int instances){
	if (instances <= 100){

		for (int i = 0; i < instances; i++) {
			if (i % 2) {
				//student
			}
			else {
				//employee
			}
		}
	}
	
}

void Interface::exportToFile(char * dir){
	std::ofstream file(dir);
	if (!file.is_open())
		throw std::runtime_error("unable to open file");
	
	if (!database_.empty()) {
		for (size_t i = 0; i < database_.size(); i++) {
			if (database_.at(i)->getAlias() == 's') {
				file << database_.at(i)->getAlias() << " " << database_.at(i)->getName()
					<< " " << database_.at(i)->getSurname() << " " << database_.at(i)->getPesel()
					<< " " << database_.at(i)->getGender() << " " << database_.at(i)->getIndex()
					<< " " << database_.at(i)->getAddress() << " < \n";
			}
			else if (database_.at(i)->getAlias() == 'e') {
				file << database_.at(i)->getAlias() << " " << database_.at(i)->getName()
					<< " " << database_.at(i)->getSurname() << " " << database_.at(i)->getPesel()
					<< " " << database_.at(i)->getGender() << " " << database_.at(i)->getSalary()
					<< " " << database_.at(i)->getAddress() << " < \n";
			}}}
	file.close();
}

//TO DO! (modify old)
void Interface::importFromFile(char * dir){
	std::ifstream file(dir);
	if (!file.is_open())
		throw std::runtime_error("unable to open file");

	std::vector<std::string> content;
	{                                                     //scope
		std::string temp;
		while (file >> temp)
			content.push_back(std::move(temp));
		file.close();
	}
	if (content.size() >= 7)                              //smallest possible amount of data to construct object
		loadContent(content);                             //if the content has been loaded correctly
}

void debugFill(Interface &I) {
	std::unique_ptr<Person> s1(new Student("Jack", "Berenz",
		"83018503020", "male", 3210, "Zurawia 7, Wroclaw" ));

	std::unique_ptr<Person> s2(new Student("Annabelle", "Savage",
		"66674366610", "female", 6661, "Minor st. 3, LA "));

	std::unique_ptr<Person> e1(new Employee("Wayne", "Static",
		"47392040165", "male", 3800.0F, "Sandy Roads 13, Joshua Tree" ));

	std::unique_ptr<Person> e2(new Employee("Ben", "Kowalewicz",
		"16421041288", "male", 6000.0F, "Maple st. 65, Ottawa" ));

	std::unique_ptr<Person> e3(new Employee("Anna", "Grodzki",
		"20231231654", "neuter", 8000.0F, "Karczewska 29, Otwock"));
	
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

bool Interface::changeEarnings(std::string Pesel, float earnings){
	for (size_t i = 0; i < database_.size(); i++)
		if (database_.at(i)->getPesel() == Pesel) {
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

void Interface::loadContent(std::vector<std::string>& content) {
	std::string s_temp = "";
	
	for (size_t i = 0; i < content.size(); i++) {
		if (content.at(i) == "s") {
			std::unique_ptr<Person> s(new Student(content.at(i + 1), content.at(i + 2), content.at(i + 3),
				content.at(i + 4), std::stoi(content.at(i + 5))));
			while (content.at(i + 6) != "<") {
				s_temp += " " + content.at(i + 6);
				i++;
			}
			s->setAddress(s_temp);
			database_.push_back(std::move(s));
			s_temp = "";
		}
		if (content.at(i) == "e") {
			std::unique_ptr<Person> e(new Employee(content.at(i + 1), content.at(i + 2), content.at(i + 3),
				content.at(i + 4), std::stof(content.at(i + 5))));
			while (content.at(i + 6) != "<") {
				s_temp += " " + content.at(i + 6);
				i++;
			}
			e->setAddress(s_temp);
			database_.push_back(std::move(e));
			s_temp = "";
		}
	}
}
