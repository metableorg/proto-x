/*
    Copyright 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/******************************************************************************/

#ifndef TEST_PROTOX_DTL_BASIC_DATA_TABLE_HPP
#define TEST_PROTOX_DTL_BASIC_DATA_TABLE_HPP

/******************************************************************************/

#include <protox/dtl/endian_enum.hpp>
#include <protox/dtl/basic.hpp>

/******************************************************************************/

namespace test { namespace protox_dtl { 

/******************************************************************************/

using namespace protox::dtl;

/******************************************************************************/

struct na {};

/******************************************************************************/

typedef basic< long,  32, endian::little, na > Integer32LE;
typedef basic< short, 16, endian::big,    na > Integer16BE;
typedef basic< float, 32, endian::little, na > Float32LE;

}}

/******************************************************************************/

#endif

/******************************************************************************/
