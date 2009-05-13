/*
    Copyright (C) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/******************************************************************************/

#ifndef PROTOX_HLA_O_CLASS_VECTOR_HPP
#define PROTOX_HLA_O_CLASS_VECTOR_HPP

/******************************************************************************/

#include <boost/mpl/vector.hpp>
#include <boost/mpl/size.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/find_if.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/prior.hpp>
#include <boost/mpl/or.hpp>
#include <boost/type_traits/is_same.hpp>

/******************************************************************************/

namespace protox { namespace hla {

/******************************************************************************/

// Get T's name type
template< typename T >
struct get_name_type
{
  typedef typename T::name_type type;
};

/******************************************************************************/

// Use the given qualified name vector NAME_VECTOR to construct another vector
// of object classes (CLASS_VECTOR) from the given root class O_CLASS.
template<
  bool NAME_VECTOR_IS_EMPTY,
  typename O_CLASS,
  typename NAME_VECTOR, // Qualified name
  typename CLASS_VECTOR
> struct o_class_vector_impl;

/******************************************************************************/

// Empty class_vector case.
template<
  typename O_CLASS,
  typename NAME_VECTOR,
  typename CLASS_VECTOR
> struct o_class_vector_impl< true, O_CLASS, NAME_VECTOR, CLASS_VECTOR >
{
  BOOST_STATIC_ASSERT(( boost::mpl::size< NAME_VECTOR >::value == 0 ));
  typedef CLASS_VECTOR type;
};

/******************************************************************************/

// Non-empty class_vector case.
template<
  typename O_CLASS,
  typename NAME_VECTOR,
  typename CLASS_VECTOR
> struct o_class_vector_impl< false, O_CLASS, NAME_VECTOR, CLASS_VECTOR >
{
  BOOST_STATIC_ASSERT(( boost::mpl::size< NAME_VECTOR >::value > 0 ));
    
  typedef typename boost::mpl::front< NAME_VECTOR >::type front_name; 
  
  typedef typename boost::mpl::find_if<
    typename O_CLASS::child_list_type,
    boost::is_same<
      front_name,
      boost::mpl::lambda< get_name_type< boost::mpl::placeholders::_ > > >
  >::type it;

  // Undefined qualified name? i.e., Didn't find the class we were looking for
  // in O_CLASS's children?
  BOOST_STATIC_ASSERT((
    !boost::is_same<
      typename boost::mpl::end< typename O_CLASS::child_list_type >::type,
      it
    >::value
  ));

  typedef typename boost::mpl::deref< it >::type obj_class_type;

  typedef typename boost::mpl::push_back<
    CLASS_VECTOR,
    obj_class_type
  >::type class_vector_type;

  typedef typename boost::mpl::pop_front< NAME_VECTOR >::type name_vector_tail;

  typedef typename o_class_vector_impl<
    (boost::mpl::empty<name_vector_tail>::value),
    obj_class_type,
    name_vector_tail,
    class_vector_type
  >::type type;
};

/******************************************************************************/
  
template< typename O_CLASS, typename NAME_VECTOR >
struct o_class_vector
{
  typedef typename o_class_vector_impl<
    (boost::mpl::empty< NAME_VECTOR >::value),
    O_CLASS,
    NAME_VECTOR,
    boost::mpl::vector< O_CLASS >
  >::type type;
};

/******************************************************************************/
  
}} // protox.hla

/******************************************************************************/

#endif

/******************************************************************************/
