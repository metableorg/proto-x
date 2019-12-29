/******************************************************************************************************************************************/
// (c) 2009 - 2019 Jay Graham
//
// Distributed under the MIT License
// (see accompanying file LICENSE_1_0_0.txt or http://www.opensource.org/licenses/mit-license.php)
/******************************************************************************************************************************************/

#ifndef PROTOX_BEE_CODEC_TAGS_HPP
#define PROTOX_BEE_CODEC_TAGS_HPP

/******************************************************************************************************************************************/

namespace protox {
namespace bee {

/******************************************************************************************************************************************/

/* @formatter:off */

struct boolean {}; // 1 bit logical value (0 = false, 1 = true)

struct number {};  // multi-bit 2s-complement integer value read left to right (higher bit # to
                   // lower bit #), with the most significant bit on the left.

struct record {};  // A vector of boolean or number data elements.

/******************************************************************************************************************************************/

/* @formatter:on */

}
}

/******************************************************************************************************************************************/

#endif

/******************************************************************************************************************************************/