
/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/******************************************************************************/

#ifndef SOM_BOCCERBALL_ASCII_CHAR_ARRAY_HPP
#define SOM_BOCCERBALL_ASCII_CHAR_ARRAY_HPP

/******************************************************************************/
#include <vector>

#include <protox/hla_1516/variable_array.hpp>
#include <test/protox/hla/som/boccerball/simple_datatype_table.hpp>

/******************************************************************************/

namespace som { namespace boccerball {

/******************************************************************************/

using namespace protox;

/******************************************************************************/

//   +-------------+--------------------------------------+-----------------+-------------+
//   | Name        | Encoding                             | Element type    | Cardinality |
//   +-------------+--------------------------------------+-----------------+-------------+
struct ASCIIString : hla_1516::variable_array< std::vector< ASCIIchar > > {}; // Dynamic  |
//   +-------------+--------------------------------------+-----------------+-------------+

/******************************************************************************/

}}

/******************************************************************************/

#endif

/******************************************************************************/
