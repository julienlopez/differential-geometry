#include "variable.hpp"

Variable::Variable(std::string name_) noexcept : name(std::move(name_))
{}

Variable::Variable(Variable&& v) noexcept: name(std::move(v.name))
{}

bool Variable::operator==(const Variable& v) const
{
	return name == v.name;
}

bool Variable::operator!=(const Variable& v) const
{
	return !(*this == v);
}

bool operator<(const Variable& v1, const Variable& v2)
{
	return v1.name < v2.name;
}
