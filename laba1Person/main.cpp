#include <chrono>
#include <iostream>
#include "./Person/person.h"


using std::string;
using std::chrono::time_point;
using std::chrono::system_clock;
using std::chrono::days;
using std::chrono::month;
using std::chrono::year;
using std::chrono::year_month_day;
using std::cout;
using std::chrono::floor;
using std::chrono::day;
using std::endl;

int main(){
	unsigned int d;
	unsigned int m;
	int y;

	std::cin >> d >> m >> y;

	year_month_day ymd{year{y}, month{m}, day{d}};

	Person I("Andrey", "Chernyaev", ymd);
	cout << I.ToString();

	I.set_name("NeAndrey");	
	I.set_surname("NeChernyaev");

	I.set_birthday(year_month_day(year(2000), month(10), day(1)));

	cout << I.ToString();

	cout << I.get_name() << '\t'<<I.get_surname()<<'\t'<<I.get_birthday();



}
