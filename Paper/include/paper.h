#ifndef PAPER_H
#define PAPER_H
#include <string>
#include <chrono>
#include <format>
#include "to_string.h"
#include "person.h"

namespace variant3 {

using std::string;
using std::chrono::days;
using ymd = std::chrono::year_month_day;
using std::chrono::floor;


class Paper : public Share::ToStr {
	string name_;	
	Share::Person author_; 
	ymd date_;
public:
	const string&	
	get_name() const;

	const Share::Person&
	get_author() const;
	
	const ymd& 
	get_date() const;	

	void
	set_name(const string& name);

	void 
	set_author(const Share::Person& author); 

	void
	set_date(const ymd& date); 


	Paper(); 

	Paper(const string& name, const Share::Person author, const ymd& date);

	string
	ToString() const override;

	Paper DeepCopy();
		
};

};

#endif
