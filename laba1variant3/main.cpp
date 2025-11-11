#include <string>
#include <iostream>
#include <format>
#include <vector>
#include "./ResearchTeam/research_team.h"
#include "./Paper/paper.h"

using std::cout;
using std::endl;
using std::format;
using variant3;


int main(){
	ResearchTeam KF{};
	
	cout << std::format("Index: Year value is {}\n
			Index: TwoYear value is {}\n
			Index: Long value is {}\n",
		       	KF[TimeFrame::Year], KF[TimeFrame::TwoYear], KF[TimeFrame::Long]);

	KF.set_topic("Физика и техника полупроводников ");
	KF.set_org("Полоцкий Государственный университет");
	KF.set_duration(TameFrame::Year);	
	
	vector papers = {Paper{"Adhesion of Diazoquinone–Novolac Photoresist Films Implanted with Boron and Phosphorus Ions to Single-Crystal Silicon", Person }
	
	};

	KF.set_papers();
	

}:
