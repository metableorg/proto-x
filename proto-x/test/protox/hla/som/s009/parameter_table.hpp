/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/******************************************************************************/

#ifndef SOM_S009_ATTRIBUTE_TABLE_HPP
#define SOM_S009_ATTRIBUTE_TABLE_HPP

/******************************************************************************/

#include <protox/hla/param.hpp>
#include <protox/hla/keywords.hpp>
#include <protox/hla/name.hpp>

#include <test/protox/hla/som/s009/simple_datatype_table.hpp>

/******************************************************************************/

namespace som_s009 {

/******************************************************************************/

using namespace protox::hla;

/******************************************************************************/

////// Parameter Table /////////////////////////////////////////////////////////
//     +-------------------------------------+-----------+----------------------------+-------------------+
//     | Name                                | Parameter | Datatype                   | String Name       |
//     +-------------------------------------+-----------+----------------------------+-------------------+
  struct Class_A {HLA_NAME( "Class_A" )};
                                        struct A3        : param< simple_float >      {HLA_NAME( "A3" )};
//     +-------------------------------------+-----------+----------------------------+-------------------+
  struct Class_B {HLA_NAME( "Class_B" )};
                                        struct A1        : param< simple_int >        {HLA_NAME( "A1" )};
//                                           +-----------+----------------------------+-------------------+
                                        struct A2        : param< simple_float >      {HLA_NAME( "A2" )};
//     +-------------------------------------+-----------+----------------------------+-------------------+
  struct Class_C {HLA_NAME( "Class_C" )};
                                        //     A1        |  simple_int 
//                                           +-----------+----------------------------+-------------------+
                                        //     A2        |  simple_float
//     +-------------------------------------+-----------+----------------------------+-------------------+
  struct Class_D {HLA_NAME( "Class_D" )};
                                        //     A1        |  simple_int 
//                                           +-----------+----------------------------+-------------------+
                                        //     A2        |  simple_float
//     +-------------------------------------+-----------+----------------------------+-------------------+
  struct Class_E {HLA_NAME( "Class_E" )};
//     +-------------------------------------+-----------+----------------------------+-------------------+
  struct Class_F {HLA_NAME( "Class_F" )};
//     +-------------------------------------+-----------+----------------------------+-------------------+
  struct Class_G {HLA_NAME( "Class_G" )};
//     +-------------------------------------+-----------+----------------------------+-------------------+
  struct Class_H {HLA_NAME( "Class_H" )};
//     +-------------------------------------+-----------+----------------------------+-------------------+

}

/******************************************************************************/

#endif

/******************************************************************************/