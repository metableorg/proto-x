
/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/**********************************************************************************************************************/

#ifndef PROTOX_OM_RPR_ANTENNA_PATTERN_STRUCT_ARRAY_HPP
#define PROTOX_OM_RPR_ANTENNA_PATTERN_STRUCT_ARRAY_HPP

/**********************************************************************************************************************/

#include <vector>

#include <protox/hla_13/variable_array.hpp>

#include <protox/om/rpr/antenna_pattern_struct.hpp>

/**********************************************************************************************************************/

namespace protox { namespace om { namespace rpr {

/**********************************************************************************************************************/

//   +---------------------------+------------------------------------+----------------------------------+-------------+
//   | Name                      | Encoding                           | Element type                     | Cardinality |
//   +---------------------------+------------------------------------+----------------------------------+-------------+
struct AntennaPatternStructArray : hla_13::variable_array< std::vector< AntennaPatternStruct::type > > {}; // 0+       |
//   +---------------------------+------------------------------------+----------------------------------+-------------+

/**********************************************************************************************************************/

}}}

/**********************************************************************************************************************/

#endif

/**********************************************************************************************************************/
