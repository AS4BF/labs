#include "research_team.h"

using v3Re = variant3::ResearchTeam;
using std::vector;

template<typename T> void	
v3Re::vec_to_str(const vector<T>& vec,string& res) const 
{

	int i = 1;
	auto it = std::back_inserter(res);

	for(const auto& elem : vec){
		it = std::format_to(it, "{} elem\n{}", i, elem.ToString());
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


v3Re::ResearchTeam(const string& topic, const string& organization, const unsigned int& rnum, const variant3::TimeFrame& duration) : Team(organization, rnum), topic_{topic}, duration_{duration} {};


v3Re::ResearchTeam() : Team("None name research team", 0), topic_{"None topic"}, duration_{variant3::TimeFrame::Long} {};

const string&
v3Re::get_topic() const noexcept { return topic_; };	

const string&
v3Re::get_org_name() const noexcept{ return name_; };

const variant3::TimeFrame&
v3Re::get_duration() const noexcept { return duration_; };

const std::vector<variant3::Paper>&
v3Re::get_papers() const noexcept { return papers_; };

void
v3Re::set_topic(const string& topic) { topic_ = topic; };

void
v3Re::set_org_name(const string& organization) { name_ = organization; };

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

const vector<Share::Person>&
v3Re::get_persons() const {
	return persons_;
};

void
v3Re::set_persons(vector<Share::Person>& persons) {
	persons_ = persons;
};

void 
v3Re::AddMembers(vector<Share::Person>& persons){
	persons_.insert(persons_.cend(), persons.begin(), persons.end());
};

void 
v3Re::set_team(const Team& team) {
	auto tmp = ResearchTeam(topic_, team.get_name(), team.get_rnum(), duration_);
	std::swap(*this, tmp);
};

variant3::Team
v3Re::get_team() const {
	return *static_cast<const Team*>(this);
};

typename variant3::ResearchTeam*
v3Re::DeepCopy() const {
	return new ResearchTeam(*this);	
};

string 
v3Re::ToShortString() const {

	string res = std::format("Research topic: {}\norganization: {}\nregistration number: {}\nduration: {}\n",
			topic_, name_, rnum_, frame_to_str());
	return res;
};

string
v3Re::ToString() const {
	string res = ToShortString();	
	
	vec_to_str(papers_, res); //дорогостоющая операция копировать vector в string
	vec_to_str(persons_, res);

	return res;
};

template<typename T>
using pointer = vector<T>::const_iterator;

bool v3Re::deltaDateComp::operator()(pointer<variant3::Paper>& tmp) {
	
	if(tmp == end_) return true;	
	return (current_date - std::chrono::sys_days((*tmp).get_date())) < delta;
};

bool v3Re::dontHavePaper::operator()(pointer<Share::Person>& tmp) {
	if(tmp == end_) return true;

	for(auto&& paper : team_.papers_) {
		if(paper.get_author() == *tmp) {
			return false;	
		};
	};

	return true;
};

bool v3Re::LastYearPaper::operator()(pointer<variant3::Paper>& tmp){
	using days = std::chrono::days;
	if(tmp == end_) return true;

	return (current_date - std::chrono::sys_days((*tmp).get_date())) < days(365);
};

bool v3Re::HaveMoreOnePaper::operator()(pointer<Share::Person>& tmp){
	if(tmp == end_) return true;

	unsigned int i = 0;
	for(auto&& paper : team_.papers_){
		if(paper.get_author() == *tmp){
			++i;	
			if(i>1) { return true; };	
		};
	};
	
	return false;
};
	

