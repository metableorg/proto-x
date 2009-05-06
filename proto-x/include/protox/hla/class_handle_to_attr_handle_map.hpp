/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/**************************************************************************************************/
 
#ifndef PROTOX_HLA_CLASS_HANDLE_TO_ATTR_HANDLE_MAP_HPP
#define PROTOX_HLA_CLASS_HANDLE_TO_ATTR_HANDLE_MAP_HPP

/**************************************************************************************************/

#include <map>
#include <string>
#include <RTI.hh>

/**************************************************************************************************/

namespace protox { namespace hla {

/**************************************************************************************************/

typedef std::map<
  std::string,
  RTI::AttributeHandle >
class_handle_to_attr_handle_map;

/**************************************************************************************************/

}} // namespace protox::hla

/**************************************************************************************************/

#endif

/**************************************************************************************************/