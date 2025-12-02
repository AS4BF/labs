#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "team.h"
#include "research_team.h"



int main() {
	variant3::Team team1{};	
	variant3::Team team2{};

	
	std::cout << "equals by value: " << 
		(team1 == team2) << std::endl 
		<< "equals by ref: " << 	
		(&team1 == &team2) << std::endl;
	
	try {
		team1.set_rnum(-1);
		std::cout << team1.get_rnum() << std::endl;
	} catch(std::string& error) {
		std::cout << error << std::endl;
	};

	variant3::ResearchTeam Rteam{};
	using ymd = std::chrono::year_month_day;
	using year = std::chrono::year;
	using month = std::chrono::month;
	using day = std::chrono::day;
	std::vector<Share::Person> persons{
			{"Игорь", "Иродов", ymd{year{1923}, month{11}, day{16}}}, 
		    {"Анна", "Петрова", ymd{year{1990}, month{5}, day{20}}},
		    {"Сергей", "Смирнов", ymd{year{1978}, month{8}, day{12}}},
		    {"Мария", "Иванова", ymd{year{1985}, month{3}, day{30}}},
	    
		    // Люди БЕЗ публикаций
		    {"Алексей", "Безработный", ymd{year{1995}, month{7}, day{15}}},
		    {"Ольга", "Студентова", ymd{year{2000}, month{2}, day{28}}},
		    {"Дмитрий", "Начинающий", ymd{year{1999}, month{9}, day{10}}},
    
	};
	
	std::vector<variant3::Paper> papers{
		    {"Квантовая физика", persons[0], ymd{year{2001}, month{1}, day{1}}},
		    {"Теория относительности", persons[0], ymd{year{2005}, month{6}, day{15}}},
		    {"Чёрные дыры", persons[0], ymd{year{2010}, month{9}, day{20}}},
		    
		    // Публикации Анны Петровой  
		    {"Машинное обучение", persons[1], ymd{year{2015}, month{3}, day{10}}},
		    {"Нейронные сети", persons[1], ymd{year{2018}, month{7}, day{25}}},
		    
		    // Публикации Сергея Смирнова
		    {"Базы данных", persons[2], ymd{year{2012}, month{4}, day{5}}},
		    
		    // Совместная публикация (два автора - используем одного как представителя)
		    {"Квантовые компьютеры", persons[0], ymd{year{2020}, month{11}, day{30}}},
		    {"Квантовые компьютеры", persons[3], ymd{year{2020}, month{11}, day{30}}}, // Мария Иванова
		    
		    // Публикация Марии Ивановой
		    {"Искусственный интеллект", persons[3], ymd{year{2019}, month{12}, day{12}}},
		    
		    // Старая публикация для тестирования фильтров по годам
		    {"Устаревшая теория", persons[0], ymd{year{1995}, month{1}, day{1}}},
		    
		    // Недавняя публикация
		    {"Современные технологии", persons[1], ymd{year{2025}, month{10}, day{1}}}
	};

	Rteam.AddMembers(persons);

	Rteam.AddPapers(papers);
		
	std::cout << Rteam.ToString() << std::endl;

	std::cout << Rteam.get_team().ToString() << std::endl;

		

};
