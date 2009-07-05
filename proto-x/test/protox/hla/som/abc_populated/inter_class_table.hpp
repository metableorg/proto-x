/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/******************************************************************************/

#ifndef SOM_ABC_POPULATED_INTER_CLASS_TABLE_HPP
#define SOM_ABC_POPULATED_INTER_CLASS_TABLE_HPP

/******************************************************************************/

#include <protox/hla/i_class.hpp>
#include <protox/hla/keywords.hpp>

#include <test/protox/hla/som/abc_populated/parameter_table.hpp>

/******************************************************************************/

namespace som { namespace abc_populated {

/******************************************************************************/

using namespace protox::hla;

// +-------------------+-------------------------+--------------------------------+
// | Class 1           | Class 2                 | Class 3                        |
// +-------------------+-------------------------+--------------------------------+
  struct inter_class_table :
// +-------------------+
     i_class< IClass_A,
     params< pa1, pa2 >,
//                     +-------------------------+
                         child< i_class< IClass_B,
                         params< pb1 >,
//                                               +--------------------------------+
                                                   child< i_class< IClass_E >,
//                                               +--------------------------------+
                                                          i_class< IClass_F >,
//                                               +--------------------------------+
                                                          i_class< IClass_C > > >,
//                                               +--------------------------------+
//                     +-------------------------+
                               i_class< IClass_C,
                                        none,
//                                               +--------------------------------+
                                                   child< i_class< IClass_A >,
//                                               +--------------------------------+
                                                          i_class< IClass_C > > >,
//                                               +--------------------------------+
//                     +-------------------------+
                               i_class< IClass_D,
                                        none,
//                                               +--------------------------------+
                                                   child< i_class< IClass_G, params< pg1, pg2 > >,
//                                               +--------------------------------+
                                                          i_class< IClass_H > > > > > {};
//                                               +--------------------------------+
//                     +-------------------------+
// +-------------------+

/******************************************************************************/

}}

/******************************************************************************/

#endif

/******************************************************************************/