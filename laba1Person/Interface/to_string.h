#ifndef TO_STRING_H
#define TO_STRING_H
#include <iostream>

using std::string;

class ToStr{
public:
	virtual string ToString() const = 0;
	virtual ~ToStr() {};

};

#endif
