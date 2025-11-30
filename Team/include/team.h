#ifndef TEAM_H
#define TEAM_H
#include <string>
#include <format>
#include "INameAndCopy.h"
#include "to_string.h"
#include "equals.h"
#include "hash.h"

namespace variant3{
using std::string;

class Team : public variant3::INameAndCopy<Team>, public Share::Equals<Team>, public Share::ToStr, public Share::HashCode {
protected:
	unsigned int rnum_;
public:
	Team(const string& name, const unsigned int& rnum); //: INameAndCopy(name), rnum_{rnum} {};
	Team();
	
	const unsigned int& 
	get_rnum() const noexcept;	

	void 
	set_rnum(const unsigned int& rnum) noexcept;

	Team* 
	DeepCopy() const override ;

	bool
	equals(const Team& rhs) const noexcept override;

	bool 
	operator==(const Team& rhs) const noexcept;

	bool 
	operator!=(const Team& rhs) const noexcept;

	int
	GetHashCode() const override ;

	string
	ToString() const override ;
	
	virtual ~Team();
};

};

#endif
