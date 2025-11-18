#include "person.h"

using SPe = Share::Person;
using ymd = std::chrono::year_month_day;

SPe::Person(const string& name, const string& surname, const ymd& birthday) : Name(name), Surname(surname), Birthday(birthday) { } 

SPe::Person() : Name(string("None")), Surname(string("None")), Birthday(floor<days>(system_clock::now())) { }

void
SPe::set_name(const string &name) { this->Name = name; };

void
SPe::set_surname(const string &surname) { this->Surname = surname; };

void
SPe::set_birthday(const ymd &birthday) 
{ 
	if(birthday.ok()){ this->Birthday = birthday; } 
	else { throw string("Invalid year.");  }	
};

const string& 
SPe::get_name() const { return this->Name; };

const string&	
SPe::get_surname() const { return this->Surname; };

const ymd&	
SPe::get_birthday() const { return this->Birthday; };

string
SPe::ToString() const { 
	return std::format("Name: {}\nSurname: {}\nBirthday {}\n", 
			Name, Surname, Birthday);
};

string
SPe::ToShortString() const {	
	return std::format("Name: {}\nSurname: {}\n", 
			Name, Surname);
};
