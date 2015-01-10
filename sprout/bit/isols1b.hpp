/*=============================================================================
  Copyright (c) 2011-2015 Bolero MURAKAMI
  https://github.com/bolero-MURAKAMI/Sprout

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef SPROUT_BIT_ISOLS1B_HPP
#define SPROUT_BIT_ISOLS1B_HPP

#include <type_traits>
#include <sprout/config.hpp>

namespace sprout {
	//
	// isols1b
	//
	template<typename Integral>
	inline SPROUT_CONSTEXPR typename std::enable_if<
		std::is_integral<Integral>::value,
		Integral
	>::type
	isols1b(Integral x) SPROUT_NOEXCEPT {
		return x & -x;
	}
}	// namespace sprout

#endif	// #ifndef SPROUT_BIT_ISOLS1B_HPP
