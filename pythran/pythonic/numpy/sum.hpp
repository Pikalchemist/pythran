#ifndef PYTHONIC_NUMPY_SUM_HPP
#define PYTHONIC_NUMPY_SUM_HPP

#include "pythonic/utils/proxy.hpp"
#include "pythonic/numpy/reduce.hpp"

#ifdef USE_BOOST_SIMD
#include <boost/simd/include/functions/sum.hpp>
#endif

#include <algorithm>

namespace pythonic {

    namespace numpy {

        template<class E>
          auto sum(E&& e) -> decltype(reduce<operator_::proxy::iadd>(std::forward<E>(e))) {
            return reduce<operator_::proxy::iadd>(std::forward<E>(e));
          }
        template<class E, class Opt>
          auto sum(E&& e, Opt&& opt) -> decltype(reduce<operator_::proxy::iadd>(std::forward<E>(e), std::forward<Opt>(opt))) {
            return reduce<operator_::proxy::iadd>(std::forward<E>(e), std::forward<Opt>(opt));
          }

        PROXY(pythonic::numpy, sum);

    }

}

#endif

