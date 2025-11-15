#include <string>
#include <iostream>
#include <format>
#include <vector>
#include <chrono>
#include <utility>
#include <stack>
#include "../laba1Person/Person/person.h"
#include "./ResearchTeam/research_team.h"
#include "./Paper/paper.h"
#include "../laba1Array/Array/array.h"
#include "../laba1Array/speedtest.h"

using std::cin;
using std::cout;
using std::endl;
using std::format;
using std::stack;
using std::chrono::month;
using std::chrono::year;
using std::chrono::year_month_day;
using std::chrono::day;
using std::chrono::floor;
using std::chrono::ceil;
using std::chrono::days;
using std::pair;
using namespace variant3;



pair<int, int> toRowAndCol(const string& expr, const string& delimiter){
	
	size_t del = expr.find(delimiter, 0); 			
	return pair<int, int>(
			std::stoi(
				expr.substr(0, del)
				), 
	 std::stoi(
		 expr.substr(del + delimiter.length(), expr.end() - expr.begin())
		 )
	 );
	
};



int main(){
	ResearchTeam KF{};
	
	cout << std::format("Index: Year value is {}\nIndex: TwoYear value is {}\nIndex: Long value is {}\n",
		       	KF[TimeFrame::Year], KF[TimeFrame::TwoYear], KF[TimeFrame::Long]);

	KF.set_topic("Физика и техника полупроводников ");
	KF.set_org("Полоцкий Государственный университет");
	KF.set_duration(TimeFrame::Year);

	Person Vabick("Sergey", "Vabichevich", ymd{year{1965}, month{1}, day{1}});	
	
	std::vector<Paper> papers = {
		Paper{string{"Adhesion of Diazoquinone–Novolac Photoresist Films Implanted with Boron and Phosphorus Ions to Single-Crystal Silicon"},
		       	Vabick, ymd{year{2020}, month{1}, day{1}}}, Paper{}, Paper{} };
		

	KF.set_papers(papers);


	cout << KF.ToString() << endl;

	papers.push_back(Paper("Late", Person{},
			       	ymd{ceil<days>(system_clock::now())})
			);

	KF.AddPapers(papers);


		
	cout << KF.ToString() << endl;

	cout << KF.get_late_date_paper().ToString() << endl;

	using Type = Paper; //мне лень выводить это всё в отдельный .h и функции
	
	string nrowcol;
	string delimiter = "*";
	cout << "delimiter: " <<"NUM"<< delimiter <<"NUM"<< endl;

	cin >> nrowcol;
	
	auto rowcol = toRowAndCol(nrowcol, delimiter);
	int nrow = rowcol.first;
	int ncol = rowcol.second;	
	
	cout << "Quantity: " << nrow*ncol << endl;

	//new init obj constructor(without values)
	Type* onearray = new Type[nrow*ncol]{};

	Type** twodarray = new Type*[nrow];

	for(int i = 0; i < nrow; i++) { twodarray[i] = new Type[ncol]{}; }


	stack<int> sub;

	//количество элементов в строках, size & col - работают как флаг и маска соответственно всё что !0 == true
	for(int k = 0, col = 1, size = nrow*ncol; col <= size; k++, col = 1<<k) {
	       	if(size & col) { sub.push(col); }
       	};
	
	Share::arr_t<Share::arr_t<Type>> stepped(sub.size());
	//тут хорошо было бы использовать аллокатор что изначально выделил бы память размером row*col+размер hedera(структур что хранят данные о row и массиве в целом), но это не наш путь 
	//создание строк 
	
	for(auto row = 0; row != stepped.size_; row++) {
	       	stepped[row] = Share::arr_t<Type>(sub.top());

		cout << "stepped row size "  << stepped[row].size_ << endl; sub.pop();
       	};

	cout << endl;
	
	size_t row = stepped.size_-1;
	size_t col = stepped[row].size_-1;

	
	auto func = [](auto&&... args){ return Share::get_to_array(std::forward<decltype(args)>(args)...); };

	auto time = speedtest::speed(func, stepped, row, col);


	cout << "stepped\n"  << "Time: " << time << endl;

	row = nrow-1;
	col = ncol-1;

	

	time = speedtest::speed(func, twodarray, row, col);

	cout << "twodarray\n" << "Time: " << time << endl;

	
	time = speedtest::speed(func, onearray, row*col-1);

	cout << "onedarray\n" << "Time: " << time << endl;


	delete[] onearray;
	for(int i = 0; i != nrow; i++){
		delete[] twodarray[i];
	}
	delete[] twodarray;	
};
