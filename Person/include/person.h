#ifndef PERSON_H
#define PERSON_H
#include <chrono>
#include <iostream>
#include "to_string.h"
#include "equals.h"
#include "hash.h"
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

class Person : ToStr, public Equals<Person>, HashCode {
private:
	string Name;
	string Surname;	
	ymd Birthday;
public:
	Person(const string& name, const string& surname, const ymd& birthday); 
	Person(); 
	
	void
       	set_name(const string &name);

	void
       	set_surname(const string &surname);

       	void
	set_birthday(const ymd &birthday);

	string
	get_name() const;
	
	string 
	get_surname() const;

	ymd	
	get_birthday() const;

	string
	ToString() const override;
	
	string
       	ToShortString() const;

	bool equals(const Person& rhs) const override;	
	
	bool operator==(const Person& rhs);

	bool operator!=(const Person& rhs);
	
	int GetHashCode() const override;

	Person DeepCopy() const;


};

};

#endif
