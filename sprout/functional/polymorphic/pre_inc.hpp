/*=============================================================================
  Copyright (c) 2011-2016 Bolero MURAKAMI
  https://github.com/bolero-MURAKAMI/Sprout

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef SPROUT_FUNCTIONAL_POLYMORPHIC_PRE_INC_HPP
#define SPROUT_FUNCTIONAL_POLYMORPHIC_PRE_INC_HPP

#include <sprout/config.hpp>
#include <sprout/functional/pre_inc.hpp>

namespace sprout {
	//
	// pre_inc_t
	// pre_inc_
	//
	typedef sprout::pre_inc<> pre_inc_t;
	namespace {
		SPROUT_STATIC_CONSTEXPR sprout::pre_inc_t pre_inc_ = {};
	}	// anonymous-namespace
}	// namespace sprout

#endif	// #ifndef SPROUT_FUNCTIONAL_POLYMORPHIC_PRE_INC_HPP
