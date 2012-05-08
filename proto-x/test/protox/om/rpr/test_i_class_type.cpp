/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/**********************************************************************************************************************/

#define BOOST_AUTO_TEST_MAIN

#include <boost/test/included/unit_test_framework.hpp>
#include <boost/test/auto_unit_test.hpp>

#include <boost/type_traits.hpp>

/**********************************************************************************************************************/

#include <protox/hla/som.hpp>
#include <protox/hla/i_class_type.hpp>

#include <protox/om/rpr/obj_class_table.hpp>
#include <protox/om/rpr/inter_class_table.hpp>

/**********************************************************************************************************************/

BOOST_AUTO_TEST_CASE(test_i_abc) {
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(test_i_class_static_attributes) {
    using namespace protox::om::rpr;

    typedef protox::hla::som< obj_class_table, inter_class_table > som;

    typedef i_class_type< som, q_name< Acknowledge > >::type acknowledge_type;
    BOOST_CHECK(acknowledge_type::get_name() == "HLAinteractionRoot.Acknowledge");
    BOOST_CHECK(acknowledge_type::get_num_params() == 5);

    typedef i_class_type< som, q_name< ActionRequest > >::type action_request_type;
    BOOST_CHECK(action_request_type::get_name() == "HLAinteractionRoot.ActionRequest");
    BOOST_CHECK(action_request_type::get_num_params() == 6);
}
