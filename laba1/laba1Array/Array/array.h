#ifndef ARRAY_T_H
#define ARRAY_T_H
#include <utility>
#include <string>

using std::string;

template<typename T>
class arr_t{
private:
	T* p_;
public:
	size_t size_;
	
	arr_t() : p_{nullptr}, size_(0) {}

	//perfect forwarding 
	arr_t(T*&& p, const size_t& sz) : p_{std::forward<T*>(p)}, size_{sz} {}

	T& operator[](const size_t& num) const {
		return p_[num];
	};

	arr_t<T>& operator=(arr_t<T>&& other){

		if(this != &other){
			delete[] p_;
			p_ = other.p_;
			size_ = other.size_;
			other.p_ = nullptr;
			other.size_ = 0;
		};

		return *this;
	};



	~arr_t(){
		delete[] p_;	
	};
};

#endif
