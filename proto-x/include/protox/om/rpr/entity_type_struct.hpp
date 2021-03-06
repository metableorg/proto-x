/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/**********************************************************************************************************************/

#ifndef PROTOX_OM_RPR_ENTITY_TYPE_STRUCT_HPP
#define PROTOX_OM_RPR_ENTITY_TYPE_STRUCT_HPP

/**********************************************************************************************************************/

#include <boost/mpl/vector.hpp>

#include <protox/hla_13/complex_type.hpp>
#include <protox/hla_13/basic_data_representation_table.hpp>

/**********************************************************************************************************************/

using namespace boost;
using namespace protox;
using namespace protox::dtl;
using namespace protox::hla_13;

/**********************************************************************************************************************/

namespace protox { namespace om { namespace rpr {

/**********************************************************************************************************************/

//      +------------------+----------------------------------------------+----------------------+
//      |                  | Field                                        |                      |
//      | Record Name      +-------------+--------------------------------+ Encoding             |
//      |                  | Name        | Type                           |                      |
//      +------------------+-------------+--------------------------------+----------------------+
namespace EntityTypeStruct {
                      struct EntityKind  : field< HLA13octet          > {};
                      struct Domain      : field< HLA13octet          > {};
                      struct CountryCode : field< HLA13unsigned_short > {};
                      struct Category    : field< HLA13octet          > {};
                      struct Subcategory : field< HLA13octet          > {};
                      struct Specific    : field< HLA13octet          > {};
                      struct Extra       : field< HLA13octet          > {};
//      +------------------+-------------+--------------------------------+
                                                              struct type : hla_13::complex_type < mpl::vector< EntityKind, Domain, CountryCode, Category, Subcategory, Specific, Extra > > {};}
//      +-----------------------------------------------------------------+----------------------+

/**********************************************************************************************************************/

}}}

/**********************************************************************************************************************/

#endif

/**********************************************************************************************************************/

