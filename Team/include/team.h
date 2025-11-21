#ifndef TEAM_H
#define TEAM_H
#include <string>
#include "INameAndCopy.h"
#include "to_string.h"
#include "equals.h"

namespace variant3{
using std::string;

class Team : public variant3::INameAndCopy<Team>, Share::Equals<Team>, Share::ToString {
protected:
	unsigned int rnum_;
public:
	Team(const string& name, const int& rnum); //: INameAndCopy(name), rnum_{rnum} {};
	Team();
	
	const int& 
	get_rnum();	

	void 
	set_rnum(const unsigned int& rnum);
	
	Team 
	DeepCopy() const override ;

	bool
	equals(const Team& rhs) const override ;

	bool 
	operator==(const Team& rhs) const ;

	bool 
	operator!=(const Team& rhs) const ;

	int 
	GetHashCode() const override ;

	string
	ToString() const override ;

};

};

#endif
