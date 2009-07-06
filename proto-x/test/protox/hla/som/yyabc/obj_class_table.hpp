/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/******************************************************************************/

#ifndef SOMS_YYABC_OBJ_CLASS_TABLE_HPP
#define SOMS_YYABC_OBJ_CLASS_TABLE_HPP

/******************************************************************************/

#include <protox/hla/o_class.hpp>
#include <protox/hla/keywords.hpp>

#include <test/protox/hla/som/yyabc/attribute_table.hpp>

/******************************************************************************/

namespace soms { namespace yyabc {

/******************************************************************************/

using namespace protox::hla;

//// Object Class Table ////////////////////////////////////////////////////////
struct o_class_table : 
// +-------------------+--------------------------+-------------------------+------------------------+
// | Class 1           | Class 2                  | Class 3                 | Class 4                |
// +-------------------+--------------------------+-------------------------+------------------------+
     o_class< Class_A,                                                                                      attrs< A3 >,
                         child< o_class< Class_B,                                                           attrs< A1, A2, A4 >,
                                                    child< o_class< Class_E >,
//                                                +-------------------------+
                                                           o_class< Class_F >,
//                                                +-------------------------+
                                                           o_class< Class_C > > >,
//                     +--------------------------+-------------------------+
                               o_class< Class_C,                                                            attrs< A1, A2 >,
                                                    child< o_class< Class_A,                                none,
                                                                              child< o_class< Class_E > > >,
//                                                +-------------------------+-------------------------+
                                                           o_class< Class_C >,
//                                                +-------------------------+
                                                           o_class< Class_E > > >,
//                     +--------------------------+-------------------------+
                               o_class< Class_D,                                                            attrs< A1, A2 >,
                                                    child< o_class< Class_G >,
//                                                +-------------------------+
                                                           o_class< Class_H > > > > > {};
// +-------------------+--------------------------+-------------------------+------------------------+

/******************************************************************************/

}}

/******************************************************************************/

#endif

/******************************************************************************/
