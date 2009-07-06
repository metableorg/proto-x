/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/******************************************************************************/

#ifndef SOMS_YYABC_ATTRIBUTE_TABLE_HPP
#define SOMS_YYABC_ATTRIBUTE_TABLE_HPP

/******************************************************************************/

#include <protox/hla/attr.hpp>
#include <protox/hla/keywords.hpp>
#include <protox/hla/name.hpp>

#include <test/protox/hla/som/yyabc/simple_datatype_table.hpp>
#include <test/protox/hla/som/yyabc/r1_record.hpp>

/******************************************************************************/

namespace soms { namespace yyabc {

/******************************************************************************/

using namespace protox::hla;

/******************************************************************************/

////// Attribute Table /////////////////////////////////////////////////////////
//   +--------------------------------+-----------+----------------------------+-------------------+
//   | Name                           | Attribute | Datatype                   | String Name       |
//   +--------------------------------+-----------+----------------------------+-------------------+
struct Class_A {HLA_NAME( "Class_A" )};
                                 struct A3        : attr< R1::type             > {HLA_NAME( "A3" )};
//   +--------------------------------+-----------+----------------------------+-------------------+
struct Class_B {HLA_NAME( "Class_B" )};
                                 struct A1        : attr< SimpleHLAinteger32BE > {HLA_NAME( "A1" )};
//                                    +-----------+----------------------------+-------------------+
                                 struct A2        : attr< SimpleHLAfloat32BE   > {HLA_NAME( "A2" )};
//                                    +-----------+----------------------------+-------------------+
                                 struct A4        : attr< SimpleHLAinteger32BE > {HLA_NAME( "A4" )};
//   +--------------------------------+-----------+----------------------------+-------------------+
struct Class_C {HLA_NAME( "Class_C" )};
                             //  struct A1        : attr< SimpleHLAinteger32BE > {HLA_NAME( "A1" )};
//                                    +-----------+----------------------------+-------------------+
                             //  struct A2        : attr< SimpleHLAfloat32BE   > {HLA_NAME( "A2" )};
//   +--------------------------------+-----------+----------------------------+-------------------+
struct Class_D {HLA_NAME( "Class_D" )};
                             //  struct A1        : attr< SimpleHLAinteger32BE > {HLA_NAME( "A1" )};
//                                    +-----------+----------------------------+-------------------+
                             //  struct A2        : attr< SimpleHLAfloat32BE   > {HLA_NAME( "A2" )};
//   +--------------------------------+-----------+----------------------------+-------------------+
struct Class_E {HLA_NAME( "Class_E" )};
//   +--------------------------------+
struct Class_F {HLA_NAME( "Class_F" )};
//   +--------------------------------+
struct Class_G {HLA_NAME( "Class_G" )};
//   +--------------------------------+
struct Class_H {HLA_NAME( "Class_H" )};
//   +--------------------------------+

}}

/******************************************************************************/

#endif

/******************************************************************************/
