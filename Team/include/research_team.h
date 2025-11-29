#ifndef RESEARCH_TEAM_H
#define RESEARCH_TEAM_H
#include <string>
#include <vector>
#include <algorithm>
#include <format>
#include <chrono>
#include <memory>
#include "paper.h"
#include "person.h"
#include "team.h"

namespace variant3{

using std::string;
using std::vector;

enum class TimeFrame{ Year, TwoYear, Long };

class ResearchTeam : public Team {
	string topic_;
	TimeFrame duration_;

	vector<Share::Person> persons_;	
	vector<variant3::Paper> papers_;
public: //iterators
	
	template<typename T>
	class Comparator{
	public:
		virtual bool operator()(T& tmp) = 0;
	};

	template<typename T>	
	using pointer = vector<T>::const_iterator;

	class PaperComp : public Comparator<pointer<variant3::Paper>> {
		bool operator()(pointer<variant3::Paper>& tmp) { return true; }
	};

	class PersonComp : public Comparator<pointer<Share::Person>> {
		bool operator()(pointer<Share::Person>) { return true; };
	};


/*
	class DateComp : public PaperComp {
	public:
		ymd current_date;
	}

	class deltaDateComp : public DateComp {
		years delta;	
		bool operator(pointer<variant3::Paper>& tmp)() override;	
	};

	class LastYearPaper: public DateComp {
		bool perator(pointer<variant3::Paper>& tmp) override;
	};
	class dontHavePaper: public PersonComp {
	public:
		bool operator(pointer<Share::Person>& tmp) override;
	};

	class HaveMoreOnePaper: public PersonComp { 
	public:
		bool operator(pointer<Share::Person>& tmp) override;
	};

*/

	template<typename T, typename Comp>
	class input_iterator {
	public:
		using value_type = T;
		using differenc_type = T;
		using pointer = vector<T>::const_iterator;
		using reference = T;
	private:
		pointer pT_;
		std::unique_ptr<Comp> comparator_;
	public: 
		input_iterator(pointer pT, std::unique_ptr<Comp> comparator) : pT_{pT}, comparator_{std::move(comparator)} {};
		
		reference operator*() {
			return *pT_; };

		input_iterator& operator++() {
			auto tmp = pT_; 

			//begin() == true -> else error
			do { 
				++tmp;
			} while(!comparator_(tmp)); 

			std::swap(pT_, tmp);

			return *this;
		};

		input_iterator operator++(int) {
			auto tmp = *this;
			++(*this);
			return tmp;
		};

		pointer operator->() {
			return pT_;	
		};

	};


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
