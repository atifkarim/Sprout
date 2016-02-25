/*=============================================================================
  Copyright (c) 2011-2016 Bolero MURAKAMI
  https://github.com/bolero-MURAKAMI/Sprout

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef SPROUT_FUNCTIONAL_POLYMORPHIC_LESS_HPP
#define SPROUT_FUNCTIONAL_POLYMORPHIC_LESS_HPP

#include <sprout/config.hpp>
#include <sprout/functional/less.hpp>

namespace sprout {
	//
	// less_t
	// less_
	//
	typedef sprout::less<> less_t;
	namespace {
		SPROUT_STATIC_CONSTEXPR sprout::less_t less_ = {};
	}	// anonymous-namespace
}	// namespace sprout

#endif	// #ifndef SPROUT_FUNCTIONAL_POLYMORPHIC_LESS_HPP
