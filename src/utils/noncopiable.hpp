#pragma once

namespace utils {

struct noncopiable
{
	noncopiable() noexcept = default;
	~noncopiable() noexcept = default;

	noncopiable(const noncopiable&) noexcept = delete;
	noncopiable& operator=(const noncopiable&) noexcept = delete;

	noncopiable(noncopiable&&) noexcept = default;
	noncopiable& operator=(noncopiable&&) noexcept = default;
};

} // utils
