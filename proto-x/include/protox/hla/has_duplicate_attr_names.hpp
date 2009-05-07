/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/**************************************************************************************************/

#ifndef PROTOX_HLA_HAS_DUPICATE_ATTR_NAMES_HPP
#define PROTOX_HLA_HAS_DUPICATE_ATTR_NAMES_HPP

/**************************************************************************************************/

#include <boost/mpl/count.hpp>
#include <boost/mpl/transform_view.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/max_element.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/equal_to.hpp>

#include <protox/hla/element_counter.hpp>

/**************************************************************************************************/

namespace protox { namespace hla {

/**************************************************************************************************/

using namespace boost;

/**************************************************************************************************/

template< bool EMPTY_SET, typename SET > struct has_duplicate_attr_names_impl;

template< typename SET >
struct has_duplicate_attr_names_impl< true, SET >
{
  // Empty sets do not have duplicate names.
  typedef typename mpl::bool_< false >::type type;
};

template< typename SET >
struct has_duplicate_attr_names_impl< false, SET >
{
  // Count each unique attr name.
  typedef typename mpl::transform_view<
    SET,
    typename element_counter<SET>::template op< mpl::placeholders::_1 >
  >::type name_counts;

  // Get the max number of occurances of any name in SET.
  typedef typename mpl::deref< typename mpl::max_element< name_counts >::type >::type max_count;

  // No duplicate names (i.e., max_count is 1)?
  typedef typename mpl::equal_to< max_count, mpl::int_<1> >::type no_duplicates;

  // Has duplicates = !no_duplicates.
  typedef typename mpl::bool_< !no_duplicates::value >::type type;
};

template< typename SET >
struct has_duplicate_attr_names
{
  typedef typename has_duplicate_attr_names_impl< mpl::empty<SET>::value, SET >::type type;
};

/**************************************************************************************************/

}} // namespace protox.hla

/**************************************************************************************************/

#endif

/**************************************************************************************************/