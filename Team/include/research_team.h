#ifndef RESEARCH_TEAM_H
#define RESEARCH_TEAM_H
#include <string>
#include <vector>
#include <algorithm>
#include "paper.h"
#include "person.h"
#include "team.h"
#include <format>
#include <iterator>

namespace variant3{

using std::string;
using std::vector;

enum class TimeFrame{ Year, TwoYear, Long };

class ResearchTeam : public Team {
	string topic_;
	TimeFrame duration_;

	vector<Share::Person> persons_;	
	vector<variant3::Paper> papers_;
private:	
	template<typename T> void	
	vec_to_str(const vector<T>& vec, string& res) const;
		
	string
	frame_to_str() const;

public:
	//ctor default init vector	
	ResearchTeam(const string& topic, const string& organization, const unsigned int& rnum, const TimeFrame& duration);
	ResearchTeam();

	const string&
	get_topic() const noexcept;	
	
	const string&
	get_org_name() const noexcept;

	const TimeFrame&
	get_duration() const noexcept;

	const vector<variant3::Paper>&
	get_papers() const noexcept;

	void
	set_topic(const string& topic);

	void
	set_org_name(const string& organization);

	void
	set_duration(const TimeFrame& duration);

	void 
	set_papers(const vector<Paper>& papers);

	const variant3::Paper& 
	get_late_date_paper() const;

	//индексатор
	bool 
	operator[] (const TimeFrame& index) const;

	void 
	AddPapers(vector<variant3::Paper>& papers);

	const vector<Share::Person>&
	get_persons() const ;

	void
	set_persons(vector<Share::Person>& persons);
	
	void	
	AddMembers(vector<Share::Person>& persons);

	void
	set_team(const Team& team);

	Team
	get_team() const ;

	virtual string 
	ToShortString() const;

	string
	ToString() const override;

	ResearchTeam*
	DeepCopy() const override;

};

};

#endif
