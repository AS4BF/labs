#ifndef PERSON_H
#define PERSON_H
#include <chrono>
#include <iostream>
#include "to_string.h"
#include <format>

namespace Share{

using std::string;
using std::chrono::days;
using std::chrono::system_clock;
using ymd = std::chrono::year_month_day;
using std::chrono::floor;
using std::endl;

class Person : ToStr {
protected: //что бы в будущем классы наследники имели доступ к полям Person при public наследовании, отношение is-a
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

	const string& 
	get_name() const;
	
	const string&	
	get_surname() const;

	const ymd&	
	get_birthday() const;

	string
	ToString() const override;
	
	string
       	ToShortString() const;
};

};

#endif
