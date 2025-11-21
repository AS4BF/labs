#ifndef INAMEANDCOPY_H
#define INAMEANDCOPY_H
#include <string>
using std::string;

namespace variant3 {

template<typename Derived>
class INameAndCopy
{
protected:
string Name_;
public:
INameAndCopy(const string& name) : Name{name} {};

const string&
get_name() const { return Name_; };

void
set_name(const string& name) { Name_ = name; };

virtual Derived DeepCopy() const = 0;

virtual ~INameAndCopy() {};
};

};

#endif
