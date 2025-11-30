#include "team.h"

using std::string;
using Team = variant3::Team;


Team::Team(const string& name, const unsigned int& rnum) : INameAndCopy(name), rnum_{rnum} {};

Team::~Team() {};

Team::Team() : INameAndCopy("None"), rnum_{0} {};

const unsigned int&
Team::get_rnum() const noexcept {
	return rnum_;	
};

void
Team::set_rnum(const unsigned int& rnum) noexcept {
	rnum_ = rnum;	
};

typename variant3::Team*
Team::DeepCopy() const {
	return new Team(name_, rnum_);
};

bool
Team::equals(const variant3::Team& rhs) const noexcept {
	return (rhs.name_ == name_) && (rhs.rnum_ == rnum_);
};

bool 
Team::operator==(const Team& rhs) const noexcept {
	return equals(rhs);
};

bool
Team::operator!=(const Team& rhs) const noexcept {
	return !equals(rhs);
};

int
Team::GetHashCode() const {
	auto res = std::hash<string>{}(name_);	
	auto factor = 997u;
	res = res * factor + std::hash<unsigned int>{}(rnum_);
	return res;

}; 

string 
Team::ToString() const {
	return std::format("Name: {}, reg num: {}", name_, rnum_);
};
