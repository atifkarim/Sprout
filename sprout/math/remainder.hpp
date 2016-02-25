/*=============================================================================
  Copyright (c) 2011-2016 Bolero MURAKAMI
  https://github.com/bolero-MURAKAMI/Sprout

  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
=============================================================================*/
#ifndef SPROUT_MATH_REMAINDER_HPP
#define SPROUT_MATH_REMAINDER_HPP

#include <type_traits>
#include <sprout/config.hpp>
#include <sprout/limits.hpp>
#include <sprout/math/detail/config.hpp>
#include <sprout/math/isnan.hpp>
#include <sprout/math/signbit.hpp>
#include <sprout/math/rem_quo.hpp>
#include <sprout/type_traits/enabler_if.hpp>
#include <sprout/type_traits/float_promote.hpp>

namespace sprout {
	namespace math {
		namespace detail {
#if SPROUT_USE_BUILTIN_CMATH_FUNCTION
			inline SPROUT_CONSTEXPR float
			builtin_remainder(float x, float y) {
				return __builtin_remainderf(x, y);
			}
			inline SPROUT_CONSTEXPR double
			builtin_remainder(double x, double y) {
				return __builtin_remainder(x, y);
			}
			inline SPROUT_CONSTEXPR long double
			builtin_remainder(long double x, long double y) {
				return __builtin_remainderl(x, y);
			}
#endif
		}	// namespace detail
		//
		// remainder
		//
		// issue:
		//	remainder(-NaN, -NaN) returns -NaN .
		//		# returns +NaN . ( same as remainder(+NaN, +NaN) )
		//
		template<
			typename FloatType,
			typename sprout::enabler_if<std::is_floating_point<FloatType>::value>::type = sprout::enabler
		>
		inline SPROUT_CONSTEXPR FloatType
		remainder(FloatType x, FloatType y) {
			return y == 0 ? -sprout::numeric_limits<FloatType>::quiet_NaN()
				: sprout::math::isnan(y)
					? sprout::math::isnan(x)
						? sprout::math::signbit(y) && sprout::math::signbit(x) ? -sprout::numeric_limits<FloatType>::quiet_NaN()
							: sprout::numeric_limits<FloatType>::quiet_NaN()
						: y
				: sprout::math::isnan(x) ? x
				: x == sprout::numeric_limits<FloatType>::infinity() || x == -sprout::numeric_limits<FloatType>::infinity()
					? -sprout::numeric_limits<FloatType>::quiet_NaN()
				: x == 0 ? x
				: y == sprout::numeric_limits<FloatType>::infinity() || y == -sprout::numeric_limits<FloatType>::infinity() ? x
#if SPROUT_USE_BUILTIN_CMATH_FUNCTION
				: sprout::math::detail::builtin_remainder(x, y)
#else
				: sprout::math::rem_quo(x, y).first
#endif
				;
		}
		template<
			typename ArithmeticType1,
			typename ArithmeticType2,
			typename sprout::enabler_if<
				std::is_arithmetic<ArithmeticType1>::value && std::is_arithmetic<ArithmeticType2>::value
			>::type = sprout::enabler
		>
		inline SPROUT_CONSTEXPR typename sprout::float_promote<ArithmeticType1, ArithmeticType2>::type
		remainder(ArithmeticType1 x, ArithmeticType2 y) {
			typedef typename sprout::float_promote<ArithmeticType1, ArithmeticType2>::type type;
			return sprout::math::remainder(static_cast<type>(x), static_cast<type>(y));
		}
	}	// namespace math

	using sprout::math::remainder;
}	// namespace sprout

#endif	// #ifndef SPROUT_MATH_REMAINDER_HPP
