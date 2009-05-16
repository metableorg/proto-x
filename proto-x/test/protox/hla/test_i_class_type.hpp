/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/******************************************************************************/

#ifndef TEST_PROTOX_HLA_I_CLASS_TYPE_HPP
#define TEST_PROTOX_HLA_I_CLASS_TYPE_HPP

/******************************************************************************/

#include <RTI.hh>

#include <boost/mpl/size.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <boost/mpl/int.hpp>

#include <protox/hla/o_class.hpp>
#include <protox/hla/i_class.hpp>
#include <protox/hla/i_class_type.hpp>
#include <protox/hla/keywords.hpp>
#include <protox/hla/param.hpp>
#include <protox/hla/name.hpp>
#include <protox/hla/som.hpp>

/******************************************************************************/

namespace test_protox_hla_i_class_type {

/******************************************************************************/

using namespace protox::hla;

/******************************************************************************/

namespace t1
{
  // Class names 
  struct Class_A { HLA_NAME("Class_A") };
  struct Class_B { HLA_NAME("Class_B") };
  struct Class_C { HLA_NAME("Class_C") };
  struct Class_D { HLA_NAME("Class_D") };
  struct Class_E { HLA_NAME("Class_E") };
  struct Class_F { HLA_NAME("Class_F") };
  struct Class_G { HLA_NAME("Class_G") };
  struct Class_H { HLA_NAME("Class_H") };

  // Attribute names
  struct A1 : protox::hla::param< int > { HLA_NAME("A1") };
  struct A2 : protox::hla::param< int > { HLA_NAME("A2") };
  struct A3 : protox::hla::param< double > { HLA_NAME("A3") };

  // Structure
  struct i_class_table : 
// +------------------+
    i_class< Class_A,
      params< A3 >,
//                    +-------------------------+
                        child< i_class< Class_B,
                          params< A1, A2 >,
//                                              +--------------------------+
                                                  child< i_class< Class_E >,
//                                              +--------------------------+
                                                         i_class< Class_F >,
//                                              +--------------------------+
                                                         i_class< Class_C > > >,
//                                              +--------------------------+
//                    +-------------------------+
                        i_class< Class_C,
                          params< A1, A2 >,
//                                              +--------------------------+
                                                  child< i_class< Class_A,
                                                    none,
//                                                                         +-------------------------+
                                                                             child< i_class< Class_E > > >,
//                                                                         +-------------------------+
//                                              +--------------------------+
                                                         i_class< Class_C >,
//                                              +--------------------------+
                                                         i_class< Class_E > > >,
//                                              +--------------------------+
//                    +-------------------------+
                        i_class< Class_D,
                          params< A1, A2 >,
//                                              +--------------------------+
                                                  child< i_class< Class_G >,
//                                              +--------------------------+
                                                         i_class< Class_H > > > > > {};
//                                              +--------------------------+
//                    +-------------------------+
// +------------------+

} // t1

/******************************************************************************/

using namespace boost;
using namespace t1;

/******************************************************************************/

BOOST_AUTO_TEST_CASE( test_i_class_type_definition )
{
  typedef protox::hla::som< null_o_class, i_class_table > som;

  RTI::RTIambassador rtiAmb;  
  som::init_handles(rtiAmb);

  typedef i_class_type< som, q_name< Class_C, Class_A, Class_E > > class_type;

  BOOST_CHECK( class_type::type::get_name()
    == "Class_A.Class_C.Class_A.Class_E" );
  BOOST_CHECK( class_type::type::get_handle() > 0 ); 
}

BOOST_AUTO_TEST_CASE( test_i_class_type_ctor )
{
  typedef protox::hla::som< null_o_class, i_class_table > som;

  RTI::RTIambassador rtiAmb;  
  som::init_handles(rtiAmb);

  typedef i_class_type< som, q_name< Class_C, Class_A, Class_E > > class_type;

  class_type::type bObj;

  BOOST_CHECK( bObj.get_param_handle<A1>() > 0 );
  BOOST_CHECK( bObj.get_param_handle<A2>() > 0 );
  BOOST_CHECK( bObj.get_param_handle<A3>() > 0 );
}

BOOST_AUTO_TEST_CASE( test_i_class_type_param_mutators )
{
  typedef protox::hla::som< null_o_class, i_class_table > som;

  RTI::RTIambassador rtiAmb;  
  som::init_handles(rtiAmb);

  typedef i_class_type< som, q_name< Class_C, Class_A, Class_E > > class_type;

  class_type::type bObj;

  bObj.p_<A1>() = 5;
  bObj.p_<A2>() = 10;
  bObj.p_<A3>() = 3.145;

  BOOST_CHECK( bObj.p_<A1>() == 5 );
  BOOST_CHECK( bObj.p_<A2>() == 10 );
  BOOST_CHECK( (bObj.p_<A3>() - 3.145) < 0.00001 );
}

/******************************************************************************/

} // test_protox_hla_i_class_type

/******************************************************************************/

#endif

/******************************************************************************/
