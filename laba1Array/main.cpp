#include <iostream>
#include <string>
#include <stack>
#include <memory>
#include <utility>
#include <chrono>
#include <format>
#include "../laba1Person/Person/person.h"
#include "./Array/array.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stack;
using std::pair;
using Type = Person;


pair<int, int> toRowAndCol(const string& expr, const string& delimiter){
	
	size_t del = expr.find(delimiter, 0); 			
	return pair<int, int>(
			stoi(
				expr.substr(0, del)
				), 
	 stoi(
		 expr.substr(del + delimiter.length(), expr.end() - expr.begin())
		 )
	 );
	
};

template<typename T>
auto timeToComplite(const T& arr, size_t row, size_t col) {

	auto start = std::chrono::steady_clock::now();

	auto value = arr[row][col];
	
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed = end - start;

	return pair(value, elapsed.count()); 
}


int main(){
	
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
	
	arr_t<arr_t<Type>> stepped(new arr_t<Type>[sub.size()], sub.size());
	//тут хорошо было бы использовать аллокатор что изначально выделил бы память размером row*col+размер hedera(структур что хранят данные о row и массиве в целом), но это не наш путь 
	//создание строк 
	
	for(auto row = 0; row != stepped.size_; row++) {
	       	stepped[row] = arr_t<Type>(new Type[sub.top()]{},
				       	sub.top());

		cout << "stepped row size "  << stepped[row].size_ << endl; sub.pop();
       	};

	cout << endl;
	
	size_t row = stepped.size_-1;
	size_t col = stepped[row].size_-1;
	auto valtime = timeToComplite(stepped, row, col);


	cout << "stepped value: " <<  valtime.first.ToString() 
	       	<< "Time: "	<< valtime.second << endl;

	row = nrow-1;
	col = ncol-1;
	valtime = timeToComplite(twodarray, row, col);

	cout << "twodarray value: " <<  valtime.first.ToString() 
	       	<< "Time: "	<< valtime.second << endl;

	
	auto start = std::chrono::steady_clock::now();

	auto value = onearray[row*col-1];
	
	auto end = std::chrono::steady_clock::now();

	std::chrono::duration<double> elapsed = end - start;

	cout << "onedarray value: " <<  value.ToString() 
	       	<< "Time: "	<< elapsed.count() << endl;


	delete[] onearray;
	for(int i = 0; i != nrow; i++){
		delete[] twodarray[i];
	}
	delete[] twodarray;	
};
