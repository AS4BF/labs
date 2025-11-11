#ifndef PAPER_H
#define PAPER_H
#include <string>
#include "../../laba1Person/Person/Person.h"
#include "../../laba1Person/Interface/to_string.h"
#include <chrono>
#include <format>

namespace Variant3 {

using std::string;
using std::chrono::days;
using ymd = std::chrono::year_month_day;
using std::chrono::floor;


class Paper : ToStr{
	string name_;	
	Person author_; 
	ymd date_;
public:
	const auto&	
	get_name() const { return name_; };

	const auto&
	get_author() const { return author_; };
	
	const auto& 
	get_date() const { return date_; };	

	void
	set_name(const string& name) { name_ = name; };

	void 
	set_author(const Person& author) { author_ = author; };

	void
	set_date(const ymd& date) { date_ = date};

	Paper() : name_{"None"}, author_{}, date{floor<days>(system_clock::now())} {};

	Paper(const string& name, const Person author, const ymd& date) : name_{name}, author_{author_}, date_{date} {};

	string
	ToString() const override {
		return std::format("Paper name: {}\nPaper date: {}\nAuthor:\n", name_, date_, author_.ToString());
	}
		
};

};

#endif
