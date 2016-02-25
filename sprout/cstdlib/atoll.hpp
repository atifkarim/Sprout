/*=============================================================================
  Copyright (c) 2011-2016 Bolero MURAKAMI
  https://github.com/bolero-MURAKAMI/Sprout

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef SPROUT_CSTDLIB_ATOLL_HPP
#define SPROUT_CSTDLIB_ATOLL_HPP

#include <sprout/config.hpp>
#include <sprout/cstdlib/ascii_to_int.hpp>

namespace sprout {
	//
	// atoll
	//
	inline SPROUT_CONSTEXPR long long
	atoll(char const* str) {
		return sprout::ascii_to_int<long long>(str);
	}
	template<typename Char>
	inline SPROUT_CONSTEXPR long long
	atoll(Char const* str) {
		return sprout::ascii_to_int<long long>(str);
	}
}	// namespace sprout

#endif	// #ifndef SPROUT_CSTDLIB_ATOLL_HPP
