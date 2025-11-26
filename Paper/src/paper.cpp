#include "paper.h"

using v3Pa = variant3::Paper;
using ymd = std::chrono::year_month_day;

using std::chrono::days;
using std::chrono::floor;
using std::string;

const string&	
v3Pa::get_name() const { return name_; };

const Share::Person&
v3Pa::get_author() const { return author_; };

const ymd& 
v3Pa::get_date() const { return date_; };	

void
v3Pa::set_name(const string& name) { name_ = name; };

void 
v3Pa::set_author(const Share::Person& author) { author_ = author; };

void
v3Pa::set_date(const ymd& date) { date_ = date; };

string
v3Pa::ToString() const {
	return std::format("Paper name: {}\nPaper date: {}\nAuthor:\n{}\n", name_, date_, author_.ToString());
};

typename variant3::Paper
v3Pa::DeepCopy() {
	return variant3::Paper(*this);
};

v3Pa::Paper() : name_{"None"}, author_{}, date_{floor<days>(std::chrono::system_clock::now())} {};

v3Pa::Paper(const string& name, const Share::Person author, const ymd& date) : name_{name}, author_{author}, date_{date} {};

