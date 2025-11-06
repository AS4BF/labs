#ifndef EQUALS_H
#define EQUALS_H

namespace Share{
//this CRTP

template <typename Derived>
class Equals {
public:
	virtual bool equals(const Derived& rhs) const {
		return static_cast<const Derived*>(this) == &rhs;		
	};

	virtual ~Equals() {} //если объект окажется временным, необходим виртуальный деструктор
};

};

#endif
