#ifndef ARRAY_T_H
#define ARRAY_T_H
#include <utility>
#include <string>

namespace Share{

using std::pair;


//условие остановки рекурсии - взяли последний аргумент из args.
template<typename T, typename First> 
auto get_to_array(const T& arr, First&& first) {
	
	auto value = arr[first];
	
	return value;
};

template<typename T, typename First, typename... Args>
auto get_to_array(const T& arr, First&& first, Args&&... args) {
	auto value = arr[first];
	
	return get_to_array(value, std::forward<Args>(args)...);
};

using std::string;

template<typename T>
class arr_t{
public:
	size_t size_; //first initialization
private: //private val
	T* p_;
private: 
	//simple use std::swap
	void swap_rref(arr_t<T>&& other) {
		if(this != &other) {
			T* tmp = p_;

			p_ = other.p_;
			size_ = other.size_;		

			other.p_ = tmp; //use to delete tmp in other and dont call delete[] here 
		};	
	};

public:
	
	arr_t() : p_{nullptr}, size_(0) {}
	
	arr_t(const size_t& sz) : size_{sz}, p_{new T[size_]} {}

	T& operator[](const size_t& num) const {
		return p_[num];
	};
	
	//safe copy
	void copy(const arr_t<T>& other){

		if(this != &other){

			T* tmp = p_;
			size_t tmpsz = size_;

			size_ = other.size_;
			p_ = new T[size_];
			
			try{	
				for(int i = 0; i != other.size_; ++i)
				{
					p_[i] = other[i];	
				};
			} catch(...) { //don't understand what type of exception throw op= of type T
				delete [] p_;
				p_ = tmp;
				size_ = tmpsz;
				throw; //maybe throw bad_copy
			}; // в случае ошибки копирования оставляет объект в согласованном состоянии	

			delete [] tmp;
		};

	};
#ifdef OPTIMIZE
	arr_t<T>& operator=(arr_t<T>&& other){
		swap_rref(std::move(other));
		return *this;
	};

	arr_t(arr_t<T>&& other) : p_{other.p_}, size_{other.size_} {
		other.p_ = nullptr;
		other.size_ = 0;
	};
#endif

	arr_t<T>& operator=(const arr_t<T>& other) {
		copy(other);
		return *this;	
	};

	arr_t(const arr_t<T>& other) : arr_t() {
		copy(other);
	};

	

	~arr_t(){
		delete[] p_;	
	};
};

};

#endif
