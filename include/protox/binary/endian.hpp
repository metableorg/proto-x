/******************************************************************************************************************************************/
// (c) 2009 - 2019 Jay Graham
//
// Distributed under the MIT License
// (see accompanying file LICENSE_1_0_0.txt or http://www.opensource.org/licenses/mit-license.php)
/******************************************************************************************************************************************/

#ifndef PROTOX_BINARY_ENDIAN_HPP
#define PROTOX_BINARY_ENDIAN_HPP

#include <protox/platform.hpp>

/******************************************************************************************************************************************/

namespace protox {
namespace binary {

/******************************************************************************************************************************************/

enum ByteEndian {BYTE_BIG_ENDIAN = PROTOX_DTL_BIG_ENDIAN, BYTE_LITTLE_ENDIAN = PROTOX_DTL_LITTLE_ENDIAN};
enum BitEndian {BIT_LITTLE_ENDIAN = 11, BIT_BIG_ENDIAN = 17};

/******************************************************************************************************************************************/

}
}

/******************************************************************************************************************************************/

#endif

/******************************************************************************************************************************************/
