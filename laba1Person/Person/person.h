#ifndef PERSON_H
#define PERSON_H
#include <chrono>
#include <iostream>
#include "../Interface/to_string.h"
#include <format>

using std::string;
using std::chrono::time_point;
using std::chrono::system_clock;
using std::chrono::days;
using ymd = std::chrono::year_month_day;
using std::chrono::floor;
using std::endl;

class Person : ToStr {
private:
	string Name;
	string Surname;	
	ymd Birthday;
public:
	Person(const string& name, const string& surname, const ymd& birthday) : Name(name), Surname(surname), Birthday(birthday) { } 
	Person() : Name(string("None")), Surname(string("None")), Birthday(floor<days>(system_clock::now())) { }
	
	void
       	set_name(const string &name) { this->Name = name; };

	void
       	set_surname(const string &surname) { this->Surname = surname; };

       	void
	set_birthday(const ymd &birthday) 
	{ 
		if(birthday.ok()){ this->Birthday = birthday; } 
		else { throw string("Invalid year.");  }	
	};

	string
	get_name() const { return this->Name; };
	
	string 
	get_surname() const { return this->Surname; };

	ymd	
	get_birthday() const { return this->Birthday; };

	string
	ToString() const override { 
		return std::format("Name: {}\nSurname: {}\nBirthday {}\n", 
				Name, Surname, Birthday);
	};
	
	string
       	ToShortString() const {	
		return std::format("Name: {}\nSurname: {}\n", 
				Name, Surname);
	};
};

#endif
