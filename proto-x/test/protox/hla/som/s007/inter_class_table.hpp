/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/******************************************************************************/

#ifndef SOM_S007_OBJ_CLASS_TABLE_HPP
#define SOM_S007_OBJ_CLASS_TABLE_HPP

/******************************************************************************/

#include <protox/hla/i_class.hpp>
#include <protox/hla/keywords.hpp>

#include <test/protox/hla/som/s007/param_table.hpp>

/******************************************************************************/

namespace som_s007 {

/******************************************************************************/

using namespace protox::hla;

//// Interaction Class Table ///////////////////////////////////////////////////
  struct inter_class_table :
// +----------------+-----------------+------------------+
// | Class 1        | Class 2         | Class 3          |
// +----------------+-----------------+------------------+
    i_class< Class_A,
               none,
               child< i_class< Class_B,
//                  +-----------------+------------------+
                                 none,
                                 child< i_class< Class_E >,
//                                    +------------------+
                                        i_class< Class_F >,
//                                    +------------------+
                                        i_class< Class_C > > >,
//                  +-----------------+------------------+
                      i_class< Class_C,
//                  +-----------------+------------------+
                                 none,
                                 child< i_class< Class_A >,
//                                    +------------------+
                                        i_class< Class_C > > >,
//                  +-----------------+------------------+
                      i_class< Class_D,
//                  +-----------------+------------------+
                                 none,
                                 child< i_class< Class_G >,
//                                    +------------------+
                                        i_class< Class_H > > > > > {};
// +-----------------+----------------+------------------+

/******************************************************************************/

}

/******************************************************************************/

#endif

/******************************************************************************/