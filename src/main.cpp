#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <memory>
#include "team.h"
#include "research_team.h"


template<typename T, typename Comp>
using iiter = variant3::ResearchTeam::input_iterator<T, Comp>;

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
//списки сгенерированны ИИ по образу и подобию 
	
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

	auto copy = std::shared_ptr<variant3::ResearchTeam>(Rteam.DeepCopy());		


// persons2 - ВТОРОЙ уникальный набор людей
std::vector<Share::Person> persons2{
    // Российские ученые нового поколения
    {"Михаил", "Гельфанд", ymd{year{1963}, month{10}, day{24}}},
    {"Артем", "Оганов", ymd{year{1975}, month{1}, day{15}}},
    {"Алексей", "Старобинский", ymd{year{1948}, month{4}, day{19}}},
    {"Андрей", "Гейм", ymd{year{1958}, month{10}, day{21}}},
    
    // Женщины-ученые
    {"Татьяна", "Батышева", ymd{year{1978}, month{7}, day{12}}},
    {"Евгения", "Новикова", ymd{year{1985}, month{3}, day{30}}},
    {"Вера", "Рубцова", ymd{year{1990}, month{11}, day{5}}},
    
    // Молодые исследователи
    {"Кирилл", "Мартынов", ymd{year{1992}, month{9}, day{18}}},
    {"Арина", "Федорова", ymd{year{1995}, month{6}, day{22}}},
    {"Денис", "Волков", ymd{year{1998}, month{2}, day{28}}},
    
    // Люди БЕЗ публикаций (для тестов)
    {"Станислав", "Практикант", ymd{year{1999}, month{5}, day{14}}},
    {"Людмила", "Лаборант", ymd{year{1997}, month{8}, day{22}}},
    {"Георгий", "Наблюдатель", ymd{year{2000}, month{2}, day{28}}},
    
    // Зарубежные ученые
    {"Tim", "Berners-Lee", ymd{year{1955}, month{6}, day{8}}},
    {"Linus", "Torvalds", ymd{year{1969}, month{12}, day{28}}},
    {"Guido", "van Rossum", ymd{year{1956}, month{1}, day{31}}},
    {"Bjarne", "Stroustrup", ymd{year{1950}, month{12}, day{30}}},
    
    // Дополнительные
    {"Рашид", "Сюняев", ymd{year{1943}, month{3}, day{1}}},
    {"Владимир", "Захаров", ymd{year{1939}, month{8}, day{10}}},
    {"Светлана", "Жукова", ymd{year{1982}, month{4}, day{17}}}
};

// papers2 - ВТОРОЙ уникальный набор публикаций
std::vector<variant3::Paper> papers2{
    // ========== Михаил Гельфанд (биоинформатика) ==========
    {"Биоинформатика геномов", persons2[0], ymd{year{1995}, month{8}, day{15}}},
    {"Эволюция белков", persons2[0], ymd{year{2000}, month{6}, day{20}}},
    {"Метагеномика", persons2[0], ymd{year{2005}, month{3}, day{10}}},
    {"Системная биология", persons2[0], ymd{year{2010}, month{11}, day{30}}},
    
    // ========== Артем Оганов (материаловедение) ==========
    {"Предсказание новых материалов", persons2[1], ymd{year{2006}, month{4}, day{5}}},
    {"USPEX алгоритм", persons2[1], ymd{year{2004}, month{9}, day{12}}},
    {"Сверхтвердые материалы", persons2[1], ymd{year{2015}, month{7}, day{22}}},
    {"Кристаллография", persons2[1], ymd{year{2018}, month{2}, day{8}}},
    
    // ========== Алексей Старобинский (космология) ==========
    {"Инфляционная Вселенная", persons2[2], ymd{year{1980}, month{1}, day{1}}},
    {"Квантовые флуктуации", persons2[2], ymd{year{1982}, month{5}, day{15}}},
    {"Темная энергия", persons2[2], ymd{year{2003}, month{10}, day{20}}},
    
    // ========== Андрей Гейм (графен) ==========
    {"Графен: открытие", persons2[3], ymd{year{2004}, month{10}, day{22}}},
    {"Свойства графена", persons2[3], ymd{year{2007}, month{6}, day{30}}},
    {"Двумерные материалы", persons2[3], ymd{year{2013}, month{4}, day{12}}},
    {"Гекко-лента", persons2[3], ymd{year{2003}, month{8}, day{26}}},
    
    // ========== Татьяна Батышева (медицина) ==========
    {"Неврология развития", persons2[4], ymd{year{2005}, month{11}, day{14}}},
    {"Детская реабилитация", persons2[4], ymd{year{2012}, month{3}, day{8}}},
    {"Аутизм: новые подходы", persons2[4], ymd{year{2018}, month{7}, day{19}}},
    
    // ========== Евгения Новикова (химия) ==========
    {"Органический синтез", persons2[5], ymd{year{2010}, month{9}, day{5}}},
    {"Катализ", persons2[5], ymd{year{2014}, month{5}, day{20}}},
    {"Зеленая химия", persons2[5], ymd{year{2019}, month{2}, day{15}}},
    
    // ========== Вера Рубцова (экология) ==========
    {"Изменение климата", persons2[6], ymd{year{2015}, month{4}, day{10}}},
    {"Биоразнообразие", persons2[6], ymd{year{2017}, month{8}, day{25}}},
    {"Устойчивое развитие", persons2[6], ymd{year{2020}, month{12}, day{1}}},
    
    // ========== Молодые исследователи ==========
    {"Машинное обучение в химии", persons2[7], ymd{year{2021}, month{6}, day{18}}},
    {"Квантовые точки", persons2[8], ymd{year{2022}, month{1}, day{14}}},
    {"Микропластик в океане", persons2[9], ymd{year{2023}, month{5}, day{7}}},
    
    // ========== Tim Berners-Lee (WWW) ==========
    {"World Wide Web", persons2[13], ymd{year{1989}, month{3}, day{12}}},
    {"HTML протокол", persons2[13], ymd{year{1990}, month{12}, day{25}}},
    {"Semantic Web", persons2[13], ymd{year{2001}, month{5}, day{17}}},
    
    // ========== Linus Torvalds (Linux) ==========
    {"Ядро Linux", persons2[14], ymd{year{1991}, month{9}, day{17}}},
    {"Git система", persons2[14], ymd{year{2005}, month{4}, day{7}}},
    
    // ========== Guido van Rossum (Python) ==========
    {"Python язык", persons2[15], ymd{year{1991}, month{2}, day{20}}},
    {"The Zen of Python", persons2[15], ymd{year{1999}, month{8}, day{19}}},
    
    // ========== Bjarne Stroustrup (C++) ==========
    {"Язык C++", persons2[16], ymd{year{1983}, month{10}, day{14}}},
    {"The C++ Programming Language", persons2[16], ymd{year{1985}, month{1}, day{1}}},
    {"Дизайн C++11", persons2[16], ymd{year{2011}, month{8}, day{12}}},
    
    // ========== Совместные публикации ==========
    {"Космологическая инфляция", persons2[2], ymd{year{1982}, month{6}, day{15}}},
    {"Космологическая инфляция", persons2[2], ymd{year{1982}, month{6}, day{15}}}, // дубль для теста
    
    {"Двумерные кристаллы", persons2[3], ymd{year{2010}, month{9}, day{5}}},
    {"Двумерные кристаллы", persons2[1], ymd{year{2010}, month{9}, day{5}}},
    
    // ========== Рашид Сюняев (астрофизика) ==========
    {"Эффект Сюняева-Зельдовича", persons2[17], ymd{year{1970}, month{5}, day{22}}},
    {"Рентгеновские двойные", persons2[17], ymd{year{1973}, month{8}, day{30}}},
    
    // ========== Владимир Захаров (физика) ==========
    {"Уравнение Захарова", persons2[18], ymd{year{1972}, month{4}, day{1}}},
    {"Плазменная турбулентность", persons2[18], ymd{year{1974}, month{11}, day{15}}},
    
    // ========== Светлана Жукова (IT) ==========
    {"Распределенные системы", persons2[19], ymd{year{2010}, month{7}, day{8}}},
    {"Облачные вычисления", persons2[19], ymd{year{2015}, month{3}, day{19}}},
    
    // ========== Для тестирования фильтров ==========
    {"Очень старая статья", persons2[2], ymd{year{1975}, month{1}, day{1}}},
    {"Совсем недавняя", persons2[7], ymd{year{2024}, month{1}, day{15}}},
    {"Будущая публикация", persons2[8], ymd{year{2025}, month{6}, day{1}}}
};	

	copy->AddMembers(persons2);
	copy->AddPapers(papers2);

	std::cout << std::endl << "copy: " << std::endl <<
		copy->ToString() << std::endl;

	//Please give me make_iterator<>(args) std::forward and I will change the world
	using dontHave = variant3::ResearchTeam::dontHavePaper;

	std::cout << "Don't have paper" << std::endl;

	for(iiter<Share::Person, dontHave> it{copy->get_persons().cbegin(), std::make_unique<dontHave>(*copy)}, 
			end{copy->get_persons().cend(), std::make_unique<dontHave>(*copy)}; 
			it != end; ++it
			) {

		std::cout << it->ToString();
	};


	std::cout << "Last 2 years paper" << std::endl;	

	using deltaDate = variant3::ResearchTeam::deltaDateComp;
	
	using std::chrono::days;
	using std::chrono::floor;
	
	for(iiter<variant3::Paper, deltaDate> it{copy->get_papers().cbegin(), std::make_unique<deltaDate>(*copy, floor<days>(std::chrono::system_clock::now()), days{730})}, 
			end{copy->get_papers().cend(),
			std::make_unique<deltaDate>(*copy, floor<days>(std::chrono::system_clock::now()), days{730})}; 
			it != end; ++it
			) {

		std::cout << it->ToString();
	}; 

	using HavePaper = variant3::ResearchTeam::HaveMoreOnePaper;	

	std::cout << "Have more one paper" << std::endl;

	for(iiter<Share::Person, HavePaper> it{copy->get_persons().cbegin(), std::make_unique<HavePaper>(*copy)}, 
			end{copy->get_persons().cend(),
			std::make_unique<HavePaper>(*copy)}; 
			it != end; ++it
			) {

		std::cout << it->ToString();
	};

	

	using LastYear = variant3::ResearchTeam::LastYearPaper;
	std::cout << "Last Year Paper" << std::endl;

	for(iiter<variant3::Paper, LastYear> it{copy->get_papers().cbegin(), std::make_unique<LastYear>(*copy, floor<days>(std::chrono::system_clock::now()))}, 
			end{copy->get_papers().cend(),
			std::make_unique<LastYear>(*copy, floor<days>(std::chrono::system_clock::now()))}; 
			it != end; ++it
			) {

		std::cout << it->ToString();
	};








};
