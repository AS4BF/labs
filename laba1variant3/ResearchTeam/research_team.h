#ifndef RESEARCH_TEAM_H
#define RESEARCH_TEAM_H
#include <string>
#include <vector>
#include <algorithm>
#include "../Paper/paper.h"
#include "../../Interface/to_string.h"
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
	vec_to_str(string&& res) const 
	{

		int i = 1;
		auto it = std::back_inserter(res);

		for(const auto& paper : papers_){
			it = std::format_to(it, "{} paper\n{}", i, paper.ToString());
			i++;
		};
	};

	string
	frame_to_str() const 
	{
		switch(duration_){
			case TimeFrame::Year:
				return "Year";
			case TimeFrame::TwoYear:
				return "TwoYear";
			case TimeFrame::Long:
				return "Long";
			default:
				return "Unknown";
		};
	};

public:
	//ctor default init vector	
	ResearchTeam(const string& topic, const string& organization, const int& rnum, const TimeFrame& duration) : topic_{topic}, organization_{organization}, rnum_{rnum}, duration_{duration} {};
	ResearchTeam() topic_{"None topic"}, organization_{"None organization"}, rnum_{0}, duration_{TimeFrame::Long} {};

	const auto&
	get_topic() const noexcept { return topic_; };	
	
	const auto&
	get_org() const noexcept{ return organization_; };

	const auto&
	get_rnum() const noexcept { return rnum_; };

	const auto&
	get_duration() const noexcept { return duration_; };

	const auto&
	get_papers() const noexcept { return papes_; };

	void
	set_topic(const string& topic) { topic_ = topic; };

	void
	set_org(const string& organization) { organization_ = organization; };

	void
	set_duration(const TimeFrame& duration) { duration_ = duration; };

	void 
	set_papers(const vector<Paper>& papers) { papers_ = papers; };

	const auto& 
	get_late_date_paper() const 
	{

		if(papers_.empty()){ throw string{"null"}; }; 

		auto comp = [](const auto& left, const auto& right)
		{ 
			return left.get_date() <=> right.get_date() > 0; //this is the starship hehe		       
		};
		
		auto latest = papers_.cbegin();

		for(auto it = papers_.cbegin() + 1;  
				it != papers_.cend();
		 		it++)
		{
			if(comp(*it, *latest) { latest = it; };
		};

		return *latest;
	};

	//индексатор
	bool 
	operator[] (const TimeFrame& index) const 
	{
		return duration_ == index;
	};

	void 
	AddPapers(vector<Paper>& papers) 
	{
		papers_.insert(papers_.cend(), papers.begin(), papers.end());
	};

	virtual string 
	ToShortString() const 
	{

		string res = std::format("Research topic: {}\n
				organization: {}\n
				registration number: {}\n
				duration: {}\n",
				topic_, organization_, rnum_, frame_to_str());
		return res;
	};

	string
	ToString() const override
	{
		string res = ToShortString();	
		
		vec_to_str(res); //дорогостоющая операция копировать vector в string

		return res;
	};


	
};

}

#endif
