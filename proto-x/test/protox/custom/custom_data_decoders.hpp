/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/**********************************************************************************************************************/

#ifndef TEST_CUSTOM_DATA_DECODERS_HPP
#define TEST_CUSTOM_DATA_DECODERS_HPP

/**********************************************************************************************************************/

#include <protox/hla_1516/basic_data_representation_table.hpp>

/**********************************************************************************************************************/

namespace test { namespace custom {

/**********************************************************************************************************************/

template< typename S >
inline void decode(protox::hla_1516::HLAoctet::value_type &c, const S &s, std::size_t &offset) {
      c = s[(unsigned int) offset];
      ++offset;
}

/**********************************************************************************************************************/

template<
    typename S,                // Source byte buffer
    std::size_t SIZE_IN_BYTES, // Size of value to be decoded in bytes
    bool CONVERT_ENDIAN        // True, if endian conversion is required during decoding
> struct decode_custom;

/**********************************************************************************************************************/

template< typename S >
struct decode_custom< S, 2, false > {
    static inline void unpack(protox::hla_1516::HLAoctet::value_type *value, const S &s, std::size_t &offset) {
        value[0] = s[(unsigned int) (offset + 0)];
        value[1] = s[(unsigned int) (offset + 1)];

        offset += 2;
    }
};

/**********************************************************************************************************************/

template< typename S >
struct decode_custom< S, 4, false > {
    static inline void unpack(protox::hla_1516::HLAoctet::value_type *value, const S &s, std::size_t &offset ) {
        value[0] = s[(unsigned int) (offset + 0)];
        value[1] = s[(unsigned int) (offset + 1)];
        value[2] = s[(unsigned int) (offset + 2)];
        value[3] = s[(unsigned int) (offset + 3)];

        offset += 4;
    }
};

/**********************************************************************************************************************/

template< typename S >
struct decode_custom< S, 8, false > {
    static inline void unpack(protox::hla_1516::HLAoctet::value_type *value, const S &s, std::size_t &offset) {
        value[0] = s[(unsigned int) (offset + 0)];
        value[1] = s[(unsigned int) (offset + 1)];
        value[2] = s[(unsigned int) (offset + 2)];
        value[3] = s[(unsigned int) (offset + 3)];
        value[4] = s[(unsigned int) (offset + 4)];
        value[5] = s[(unsigned int) (offset + 5)];
        value[6] = s[(unsigned int) (offset + 6)];
        value[7] = s[(unsigned int) (offset + 7)];

        offset += 8;
    }
};

/**********************************************************************************************************************/

template< typename S >
struct decode_custom< S, 2, true > {
    static inline void unpack(protox::hla_1516::HLAoctet::value_type *value, const S &s, std::size_t &offset) {
        value[1] = s[(unsigned int) (offset + 0)];
        value[0] = s[(unsigned int) (offset + 1)];

        offset += 2;
    }
};

/**********************************************************************************************************************/

template< typename S >
struct decode_custom< S, 4, true > {
    static inline void unpack(protox::hla_1516::HLAoctet::value_type *value, const S &s, std::size_t &offset) {
        value[3] = s[(unsigned int) (offset + 0)];
        value[2] = s[(unsigned int) (offset + 1)];
        value[1] = s[(unsigned int) (offset + 2)];
        value[0] = s[(unsigned int) (offset + 3)];

        offset += 4;
    }
};

/**********************************************************************************************************************/

template< typename S >
struct decode_custom< S, 8, true > {
    static inline void unpack(protox::hla_1516::HLAoctet::value_type *value, const S &s, std::size_t &offset) {
        value[7] = s[(unsigned int) (offset + 0)];
        value[6] = s[(unsigned int) (offset + 1)];
        value[5] = s[(unsigned int) (offset + 2)];
        value[4] = s[(unsigned int) (offset + 3)];
        value[3] = s[(unsigned int) (offset + 4)];
        value[2] = s[(unsigned int) (offset + 5)];
        value[1] = s[(unsigned int) (offset + 6)];
        value[0] = s[(unsigned int) (offset + 7)];

        offset += 8;
    }
};

/**********************************************************************************************************************/

}}

/**********************************************************************************************************************/

#endif

/**********************************************************************************************************************/
