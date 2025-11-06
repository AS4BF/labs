#ifndef PERSON_H
#define PERSON_H
#include <chrono>
#include <iostream>
#include "../Interface/to_string.h"
#include "../Interface/equals.h"
#include "../Interface/hash.h"
#include <functional>
#include <format>

namespace Share{

using std::string;
using std::chrono::time_point;
using std::chrono::system_clock;
using std::chrono::days;
using ymd = std::chrono::year_month_day;
using std::chrono::floor;
using std::endl;

class Person : ToStr, Equals<Person>, HashCode {
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

	bool equals(const Person& rhs) const override {
		return (Name == rhs.Name) && (Surname == rhs.Surname) && (Birthday == rhs.Birthday); 
	};	
	
	bool operator==(const Person& rhs) {
		return equals(rhs);	
	};

	bool operator!=(const Person& rhs) {
		return !equals(rhs);
	};
	
	int GetHashCode() const override {
		auto res = std::hash<string>{}(Name);
		size_t factor = 997;
		res = res * factor 
			+ std::hash<string>{}(Surname);
	        res = res * factor
		       + std::hash<int>{}(static_cast<int>(Birthday.year()))
		       + std::hash<int>{}(static_cast<int>(Birthday.month()))
		       + std::hash<int>{}(static_cast<int>(Birthday.day()));				

		return res; 		
	};

	Person DeepCopy() const {
		return Person(Name, Surname, Birthday);
	};


};

};

#endif
