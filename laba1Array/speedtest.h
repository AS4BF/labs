#ifndef SPEED_TEST_H
#define SPEED_TEST_H
#include <utility>
#include <chrono>

namespace speedtest{



decltype(auto) speed(auto&& func, auto&&... Args){
	auto start = std::chrono::steady_clock::now();
	
	std::forward<decltype(func)>(func)(
			std::forward<decltype(Args)>(Args)...
			);	
		
	auto end = std::chrono::steady_clock::now();
	
	std::chrono::duration<double> elapsed = end - start;
	return elapsed;
};


};
#endif
