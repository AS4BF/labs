#include "research_team.h"

using v3Re = variant3::ResearchTeam;

void	
v3Re::vec_to_str(string& res) const 
{

	int i = 1;
	auto it = std::back_inserter(res);

	for(const auto& paper : papers_){
		it = std::format_to(it, "{} paper\n{}", i, paper.ToString());
		i++;
	};
};

string
v3Re::frame_to_str() const 
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


v3Re::ResearchTeam(const string& topic, const string& organization, const unsigned int& rnum, const variant3::TimeFrame& duration) : topic_{topic}, organization_{organization}, rnum_{rnum}, duration_{duration} {};
v3Re::ResearchTeam() : topic_{"None topic"}, organization_{"None organization"}, rnum_{0}, duration_{variant3::TimeFrame::Long} {};

const string&
v3Re::get_topic() const noexcept { return topic_; };	

const string&
v3Re::get_org() const noexcept{ return organization_; };

const unsigned int&
v3Re::get_rnum() const noexcept { return rnum_; };

const variant3::TimeFrame&
v3Re::get_duration() const noexcept { return duration_; };

const std::vector<variant3::Paper>&
v3Re::get_papers() const noexcept { return papers_; };

void
v3Re::set_topic(const string& topic) { topic_ = topic; };

void
v3Re::set_org(const string& organization) { organization_ = organization; };

void
v3Re::set_duration(const variant3::TimeFrame& duration) { duration_ = duration; };

void 
v3Re::set_papers(const vector<Paper>& papers) { papers_ = papers; };

const variant3::Paper& 
v3Re::get_late_date_paper() const 
{

	if(papers_.empty()){ throw string{"null"}; }; 

	auto comp = [](const auto& left, const auto& right)
	{ 
		return left.get_date() <=> right.get_date() > 0; //this is the starship hehe		       
	};
	
	auto latest = papers_.cbegin();

	for(auto it = papers_.cbegin() + 1;  
			it != papers_.cend();
			++it)
	{
		if(comp(*it, *latest)) { latest = it; };
	};

	return *latest;
};

//индексатор
bool 
v3Re::operator[] (const variant3::TimeFrame& index) const 
{
	return duration_ == index;
};

void 
v3Re::AddPapers(vector<Paper>& papers) 
{
	papers_.insert(papers_.cend(), papers.begin(), papers.end());
};

string 
v3Re::ToShortString() const 
{

	string res = std::format("Research topic: {}\norganization: {}\nregistration number: {}\nduration: {}\n",
			topic_, organization_, rnum_, frame_to_str());
	return res;
};

string
v3Re::ToString() const 
{
	string res = ToShortString();	
	
	vec_to_str(res); //дорогостоющая операция копировать vector в string

	return res;
};

