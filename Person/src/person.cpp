#include "person.h"

using Per = Share::Person;
using T = typename Share::Person; 

using std::string;
using std::chrono::time_point;
using std::chrono::system_clock;
using std::chrono::days;
using ymd = std::chrono::year_month_day;
using std::chrono::floor;
using std::endl;


Per::Person(const string& name, const string& surname, const ymd& birthday) : Name(name), Surname(surname), Birthday(birthday) { } 
Per::Person() : Name(string("None")), Surname(string("None")), Birthday(floor<days>(system_clock::now())) { }

void
Per::set_name(const string &name) { this->Name = name; };

void
Per::set_surname(const string &surname) { this->Surname = surname; };

void
Per::set_birthday(const ymd &birthday) 
{ 
	if(birthday.ok()){ this->Birthday = birthday; } 
	else { throw string("Invalid year.");  }	
};

string
Per::get_name() const { return this->Name; };

string 
Per::get_surname() const { return this->Surname; };

ymd	
Per::get_birthday() const { return this->Birthday; };

string
Per::ToString() const { 
	return std::format("Name: {}\nSurname: {}\nBirthday {}\n", 
			Name, Surname, Birthday);
};

string
Per::ToShortString() const {	
	return std::format("Name: {}\nSurname: {}\n", 
			Name, Surname);
};

bool 
Per::equals(const T& rhs) const {
	return (Name == rhs.Name) && (Surname == rhs.Surname) && (Birthday == rhs.Birthday); 
};	

bool 
Per::operator==(const T& rhs) {
	return equals(rhs);	
};

bool 
Per::operator!=(const T& rhs) {
	return !equals(rhs);
};

int 
Per::GetHashCode() const {
	auto res = std::hash<string>{}(Name);
	size_t factor = 997;
	res = res * factor 
		+ std::hash<string>{}(Surname);
	res = res * factor
	       + std::hash<int>{}(static_cast<int>(Birthday.year()))
	       + std::hash<int>{}(static_cast<unsigned>(Birthday.month()))
	       + std::hash<int>{}(static_cast<unsigned>(Birthday.day()));				

	return res; 		
};

T
Per::DeepCopy() const {
	return Person(*this); //copy ctor
};


