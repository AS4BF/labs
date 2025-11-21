#ifndef RESEARCH_TEAM_H
#define RESEARCH_TEAM_H
#include <string>
#include <vector>
#include <algorithm>
#include "paper.h"
#include "to_string.h"
#include <format>
#include <iterator>

namespace variant3{

using std::string;
using std::vector;

enum class TimeFrame{ Year, TwoYear, Long };

class ResearchTeam : ToStr{
	string topic_;
	string organization_;
	unsigned int rnum_;
	TimeFrame duration_;
	vector<Paper> papers_;
private:	
	void	
	vec_to_str(string& res) const;
	
	string
	frame_to_str() const;

public:
	//ctor default init vector	
	ResearchTeam(const string& topic, const string& organization, const unsigned int& rnum, const TimeFrame& duration);
	ResearchTeam();

	const string&
	get_topic() const noexcept;	
	
	const string&
	get_org() const noexcept;

	const unsigned int&
	get_rnum() const noexcept;

	const TimeFrame&
	get_duration() const noexcept;

	const vector<variant3::Paper>&
	get_papers() const noexcept;

	void
	set_topic(const string& topic);

	void
	set_org(const string& organization);

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
	AddPapers(vector<Paper>& papers);

	virtual string 
	ToShortString() const;

	string
	ToString() const override;

};

};

#endif
