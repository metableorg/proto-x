/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/**********************************************************************************************************************/

#ifndef SOM_S008_ATTRIBUTE_TABLE_HPP
#define SOM_S008_ATTRIBUTE_TABLE_HPP

/**********************************************************************************************************************/

#include <protox/hla/keywords.hpp>
#include <protox/hla/name.hpp>
#include <protox/hla/param.hpp>

/**********************************************************************************************************************/

namespace som_s008 {

/**********************************************************************************************************************/

using namespace protox::hla;

/**********************************************************************************************************************/

////// Parameter Table /////////////////////////////////////////////////////////////////////////////////////////////////
//   +--------------------------------+-----------+--------------+-----------------+
//   | Name                           | Attribute | Datatype     | String Name     |
//   +--------------------------------+-----------+--------------+-----------------+
struct Class_A { HLA_NAME("Class_A") };
                                 struct A1        : param< int > { HLA_NAME("A1") };
                                 struct A2        : param< int > { HLA_NAME("A2") };
//   +--------------------------------+-----------+--------------+-----------------+

/**********************************************************************************************************************/

}

/**********************************************************************************************************************/

#endif

/**********************************************************************************************************************/
