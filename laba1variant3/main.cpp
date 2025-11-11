#include <string>
#include <iostream>
#include <format>
#include <vector>
#include <chrono>
#include "../laba1Person/Person/person.h"
#include "./ResearchTeam/research_team.h"
#include "./Paper/paper.h"

using std::cout;
using std::endl;
using std::format;
using std::chrono::month;
using std::chrono::year;
using std::chrono::year_month_day;
using std::chrono::day;

using namespace variant3;

int main(){
	ResearchTeam KF{};
	
	cout << std::format("Index: Year value is {}\n Index: TwoYear value is {}\n Index: Long value is {}\n",
		       	KF[TimeFrame::Year], KF[TimeFrame::TwoYear], KF[TimeFrame::Long]);

	KF.set_topic("Физика и техника полупроводников ");
	KF.set_org("Полоцкий Государственный университет");
	KF.set_duration(TameFrame::Year);

	Person Vabick("Sergey", "Vabichevich", ymd{year{1983}, month{1}, day{1}});	
	
	vector<Paper> papers = {Paper{"Adhesion of Diazoquinone–Novolac Photoresist Films Implanted with Boron and Phosphorus Ions to Single-Crystal Silicon", Vabick, ymd{year{2020}, month{1}, day{}}, Paper{}, Paper{}}
	
	};
		

	KF.set_papers(papers);

	cout << KF.ToString() << endl;
	

};
