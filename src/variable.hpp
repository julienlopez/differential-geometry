#pragma once

#include <string>

class Variable
{
public:
	explicit Variable(std::string name_) noexcept;
	~Variable() noexcept = default;

	Variable(const Variable&) = default;
	Variable(Variable&& v) noexcept;

	Variable& operator=(const Variable&) = default;
	Variable& operator=(Variable&& v) = default;

	const std::string name;

	bool operator==(const Variable& v) const;
	bool operator!=(const Variable& v) const;
};

bool operator<(const Variable& v1, const Variable& v2);
