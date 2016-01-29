#ifndef __CPP_STDINT_HPP__
#define __CPP_STDINT_HPP__
/*
 * A cleaner templated solution to using primitive integral types of different
 * widths.
 *
 * Integer types are templated by "bit widths" _not_ byte widths, so if you need
 * to create an integer of width the same as a pointer type then the following
 * template specialization will need to be used
 *      Int<sizeof(void*) * 8, UNSIGNED>::type
 *
 * Templates rarely every make any visible change to a program's functionality
 * that cannot be achieved by simply typing different code.  But keeping true to
 * the template philosophy, this class is intended to be a suitable replacement
 * for different integral specializations
 *
 * Written by Aaryaman Sagar
 * rmn100@gmail.com
 */

namespace Cppstdint {

const bool UNSIGNED = false;
const bool SIGNED = true;

template <size_t WIDTH, bool UNSIGNED>
class Int {
public:
    using type = int;
};

/*
 * UNSIGNED INTEGER TEMPLATES
 */
template<> class Int<8, false> {
public:
    using type = uint8_t;
};
template<> class Int<16, false> {
public:
    using type = uint16_t;
};
template<> class Int<32, false> {
public:
    using type = uint32_t;
};
template<> class Int<64, false> {
public:
    using type = uint64_t;
};

/*
 * SIGNED INTEGER DEFINITIONS
 */
template<> class Int<8, true> {
public:
    using type = int8_t;
};
template<> class Int<16, true> {
public:
    using type = int16_t;
};
template<> class Int<32, true> {
public:
    using type = int32_t;
};
template<> class Int<64, true> {
public:
    using type = int64_t;
};

}

#endif
