/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/**********************************************************************************************************************/

#ifndef PROTOX_OM_RPR_RTI_OBJECT_ID_STRUCT_HPP
#define PROTOX_OM_RPR_RTI_OBJECT_ID_STRUCT_HPP

/**********************************************************************************************************************/

#include <boost/mpl/vector.hpp>

#include <protox/hla_13/complex_type.hpp>
#include <protox/hla_13/hla13_string.hpp>

/**********************************************************************************************************************/

namespace protox { namespace om { namespace rpr {

/**********************************************************************************************************************/

using namespace boost;
using namespace protox;
using namespace protox::dtl;
using namespace protox::hla_13;

/**********************************************************************************************************************/

//      +-------------------+-------------------------------+----------------------+
//      |                   | Field                         |                      |
//      | Record Name       +-------------------------------+ Encoding             |
//      |                   | Name | Type                   |                      |
//      +-------------------+------+------------------------+----------------------+
namespace RTIObjectIdStruct {
                       struct ID   : field< HLA13string > {};
//      +-------------------+-------------------------------+----------------------+
                                                struct type : hla_13::complex_type < mpl::vector< ID > > {}; }
//      +---------------------------------------------------+----------------------+

/**********************************************************************************************************************/

}}}

/**********************************************************************************************************************/

#endif

/**********************************************************************************************************************/
