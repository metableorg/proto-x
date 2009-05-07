/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/**************************************************************************************************/

#ifndef TEST_PROTOX_HLA_SOM_HPP
#define TEST_PROTOX_HLA_SOM_HPP

/**************************************************************************************************/

#include <iostream>

#include <RTI.hh>

#include <protox/hla/o_class.hpp>
#include <protox/hla/keywords.hpp>
#include <protox/hla/name.hpp>
#include <protox/hla/som.hpp>
#include <protox/hla/class_handle_to_attr_handle_map.hpp>

/**************************************************************************************************/

namespace test_protox_hla_som {

/**************************************************************************************************/

namespace t1
{
  using namespace protox::hla;

  // Class names 
  struct Class_A { HLA_NAME("Class_A") };
  struct Class_B { HLA_NAME("Class_B") };
  struct Class_C { HLA_NAME("Class_C") };
  struct Class_D { HLA_NAME("Class_D") };
  struct Class_E { HLA_NAME("Class_E") };
  struct Class_F { HLA_NAME("Class_F") };
  struct Class_G { HLA_NAME("Class_G") };
  struct Class_H { HLA_NAME("Class_H") };
  
 
  struct obj_class_table : 
// +-------------------+
     o_class< Class_A,
              none,
//                     +-------------------------+
                         child< o_class< Class_B,
                                         none,
//                                               +--------------------------------+
                                                   child< o_class< Class_E >,
//                                               +--------------------------------+
                                                          o_class< Class_F >,
//                                               +--------------------------------+
                                                          o_class< Class_C > > >,
//                                               +--------------------------------+
//                     +-------------------------+
                               o_class< Class_C,
                                        none,
//                                               +--------------------------------+
                                                   child< o_class< Class_A >,
//                                               +--------------------------------+
                                                          o_class< Class_C > > >,
//                                               +--------------------------------+
//                     +-------------------------+
                               o_class< Class_D,
                                        none,
//                                               +--------------------------------+
                                                   child< o_class< Class_G >,
//                                               +--------------------------------+
                                                          o_class< Class_H > > > > > {};
//                                               +--------------------------------+
//                     +-------------------------+
// +-------------------+
}

BOOST_AUTO_TEST_CASE( test_som_init_class_handles )
{
  using namespace t1;
  using namespace boost;
  using namespace protox;

  typedef hla::som< obj_class_table > som;
  
  RTI::RTIambassador rtiAmb;  
  som::init_handles(rtiAmb);

  BOOST_CHECK( som::get_num_object_classes() == 11 ); 

  BOOST_CHECK( som::get_object_class_handle("Class_A") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_B") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_B.Class_E") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_B.Class_F") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_B.Class_C") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_C") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_C.Class_A") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_C.Class_C") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_D") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_D.Class_G") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_D.Class_H") > 0 );
}

namespace t2
{
  using namespace protox::hla;

//     +------------------------------+-----------+-----------------+-----------------+
//     | Name                         | Attribute | Datatype        | String Name     |
//     +------------------------------+-----------+-----------------+-----------------+
  struct Class_A {HLA_NAME("Class_A")};
//                                    +-----------+-----------------+-----------------+
                                 struct a1        : attr< int >     { HLA_NAME("a1") };
//                                    +-----------+-----------------+-----------------+
                                 struct a2        : attr< int >     { HLA_NAME("a2") };
//     +------------------------------+-----------+-----------------+-----------------+
  struct Class_B { HLA_NAME("Class_B") };
//                                    +-----------+-----------------+-----------------+
                                 struct b1        : attr< int >     { HLA_NAME("b1") };
//     +------------------------------+-----------+-----------------+-----------------+
  struct Class_C { HLA_NAME("Class_C") };
//     +------------------------------+-----------+-----------------+-----------------+
  struct Class_D { HLA_NAME("Class_D") };
//     +------------------------------+-----------+-----------------+-----------------+
  struct Class_E { HLA_NAME("Class_E") };
//     +------------------------------+-----------+-----------------+-----------------+
  struct Class_F { HLA_NAME("Class_F") };
//     +------------------------------+-----------+-----------------+-----------------+
  struct Class_G { HLA_NAME("Class_G") };
//                                    +-----------+-----------------+-----------------+
                                 struct g1        : attr< int >     { HLA_NAME("g1") };
//                                    +-----------+-----------------+-----------------+
                                 struct g2        : attr< int >     { HLA_NAME("g2") };
//     +------------------------------+-----------+-----------------+-----------------+
  struct Class_H { HLA_NAME("Class_H") };
//     +------------------------------+-----------+-----------------+-----------------+
  
 
  struct obj_class_table : 
// +-------------------+
     o_class< Class_A,
     attrs< a1, a2 >,
//                     +-------------------------+
                         child< o_class< Class_B,
                         attrs< b1 >,
//                                               +--------------------------------+
                                                   child< o_class< Class_E >,
//                                               +--------------------------------+
                                                          o_class< Class_F >,
//                                               +--------------------------------+
                                                          o_class< Class_C > > >,
//                                               +--------------------------------+
//                     +-------------------------+
                               o_class< Class_C,
                                        none,
//                                               +--------------------------------+
                                                   child< o_class< Class_A >,
//                                               +--------------------------------+
                                                          o_class< Class_C > > >,
//                                               +--------------------------------+
//                     +-------------------------+
                               o_class< Class_D,
                                        none,
//                                               +--------------------------------+
                                                   child< o_class< Class_G, attrs< g1, g2 > >,
//                                               +--------------------------------+
                                                          o_class< Class_H > > > > > {};
//                                               +--------------------------------+
//                     +-------------------------+
// +-------------------+
}
BOOST_AUTO_TEST_CASE( test_som_init_attr_handles )
{
  using namespace t2;
  using namespace boost;
  using namespace protox;

   typedef hla::som< obj_class_table > som;
  
  RTI::RTIambassador rtiAmb;  
  som::init_handles(rtiAmb);

  BOOST_CHECK( som::get_num_object_classes() == 11 ); 

  BOOST_CHECK( som::get_object_class_handle("Class_A") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_B") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_B.Class_E") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_B.Class_F") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_B.Class_C") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_C") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_C.Class_A") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_C.Class_C") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_D") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_D.Class_G") > 0 );
  BOOST_CHECK( som::get_object_class_handle("Class_A.Class_D.Class_H") > 0 );

  som::print_attr_handle_map();
}

/**************************************************************************************************/

} // namespace test_protox_hla_o_class

/**************************************************************************************************/

#endif

/**************************************************************************************************/