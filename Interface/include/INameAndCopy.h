#ifndef INAMEANDCOPY_H
#define INAMEANDCOPY_H
#include <string>
using std::string;

namespace variant3 {

template<typename Derived>
class INameAndCopy
{
protected:
string name_;
public:
INameAndCopy(const string& name) : name_{name} {};

const string&
get_name() const { return name_; };

void
set_name(const string& name) { name_ = name; };

virtual Derived* DeepCopy() const = 0; //* для обеспечения ковариантности, просто Derived подвержен срезки

virtual ~INameAndCopy() {};
};

};

#endif
