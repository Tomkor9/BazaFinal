#pragma once
#include <string>

class Person {
protected:
	static const char alias_;
	std::string name_;
	std::string surname_;
	std::string Pesel_;
	std::string gender_;
	std::string address_;
public:
	virtual void show() = 0;
	
	std::string getName() const { return name_; }
	std::string getSurname() const { return surname_; }
	std::string getPesel() const { return Pesel_; }
	std::string getGender() const { return gender_; }
	std::string getAddress() const { return address_; }
	
	void setAddress(std::string address) { address_ = address;}
	
	//temporary solution of bad project concept
	virtual int getIndex() = 0;
	virtual float getSalary() = 0;
	virtual void setSalary(float) = 0;
	virtual char getAlias() = 0;
};
