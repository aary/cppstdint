#ifndef __CPP_STDINT_HPP__
#define __CPP_STDINT_HPP__
/*
 * A cleaner templated solution to using primitive integral types of different
 * widths.
 *
 * Integer types are templated by "bit widths" _not_ byte widths, so if you need
 * to create an integer of width the same as a pointer type then the following
 * template specialization will need to be used
 *      Int<sizeof(void*) * 8, SignType::UNSIGNED>::type
 *
 * Templates rarely every make any visible change to a program's functionality
 * that cannot be achieved by simply typing different code.  But keeping true to
 * the template philosophy, this class is intended to be a suitable replacement
 * for different integral specializations
 *
 * Written by Aaryaman Sagar
 * rmn100@gmail.com
 */
#include <cstdint>
#include <limits>

namespace Cppstdint {


/*
 * Used to denote the choice of whether the int type should be signed or
 * unsigned
 */
enum class SignType {UNSIGNED, SIGNED};

/*
 * Used to denote the maximum width int that can be used
 */
const size_t MAX = std::numeric_limits<decltype(MAX)>::max();


template <size_t WIDTH, SignType SIGN>
class Int {
public:
    using type = int;
};

/*
 * UNSIGNED INTEGER TEMPLATES
 */
template<> class Int<8, SignType::UNSIGNED> {
public:
    using type = uint8_t;
};
template<> class Int<16, SignType::UNSIGNED> {
public:
    using type = uint16_t;
};
template<> class Int<32, SignType::UNSIGNED> {
public:
    using type = uint32_t;
};
template<> class Int<64, SignType::UNSIGNED> {
public:
    using type = uint64_t;
};
template<> class Int<MAX, SignType::UNSIGNED> {
public:
    using type = uintmax_t;
};

/*
 * SIGNED INTEGER DEFINITIONS
 */
template<> class Int<8, SignType::SIGNED> {
public:
    using type = int8_t;
};
template<> class Int<16, SignType::SIGNED> {
public:
    using type = int16_t;
};
template<> class Int<32, SignType::SIGNED> {
public:
    using type = int32_t;
};
template<> class Int<64, SignType::SIGNED> {
public:
    using type = int64_t;
};
template<> class Int<MAX, SignType::SIGNED> {
public:
    using type = intmax_t;
};

}

#endif
