/*
 Copyright 2009 Jay Graham

 Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
 or http://www.opensource.org/licenses/mit-license.php)
 */

/**********************************************************************************************************************/

#include <boost/test/unit_test.hpp>

/**********************************************************************************************************************/

#include <boost/mpl/sizeof.hpp>
#include <boost/dynamic_bitset.hpp>

#include <protox/dtl/endian_enum.hpp>
#include <protox/dtl/basic.hpp>
#include <protox/codec/codecs.hpp>
#include <protox/bee/codec_tags.hpp>

#include <protox/platform.hpp>

/**********************************************************************************************************************/

namespace test_bee_policy_basic_data {

using namespace boost;
using namespace protox::dtl;
using namespace protox::bee;

/* @formatter:off */
struct na {};


struct Boolean   : basic<bool,            1, endian::big,    boolean> {PROTOX_BASIC(Boolean  )};
struct Int02bit  : basic<char,            2, endian::big,    number > {PROTOX_BASIC(Int02bit )};
struct UInt02bit : basic<unsigned char,   2, endian::big,    number > {PROTOX_BASIC(UInt02bit)};
struct Int03bit  : basic<char,            3, endian::big,    number > {PROTOX_BASIC(Int03bit )};
struct UInt03bit : basic<unsigned char,   3, endian::big,    number > {PROTOX_BASIC(UInt03bit)};
struct UInt13bit : basic<unsigned short, 13, endian::big,    number > {PROTOX_BASIC(UInt13bit)};

/* @formatter:on */

/**********************************************************************************************************************/

//BOOST_AUTO_TEST_CASE(test_basic_data_representation_table) {
//
//    typedef protox::dtl::codec codec;
//
//    // Check static byte sizes for all basic data types.
//    BOOST_CHECK(1 == codec::static_size_in_bytes< HLAoctet       >::value);
//    BOOST_CHECK(2 == codec::static_size_in_bytes< HLAoctetPairBE >::value);
//    BOOST_CHECK(2 == codec::static_size_in_bytes< HLAinteger16BE >::value);
//    BOOST_CHECK(4 == codec::static_size_in_bytes< HLAinteger32BE >::value);
//    BOOST_CHECK(8 == codec::static_size_in_bytes< HLAinteger64BE >::value);
//    BOOST_CHECK(4 == codec::static_size_in_bytes< HLAfloat32BE   >::value);
//    BOOST_CHECK(8 == codec::static_size_in_bytes< HLAfloat64BE   >::value);
//
//    BOOST_CHECK(2 == codec::static_size_in_bytes< HLAoctetPairLE >::value);
//    BOOST_CHECK(2 == codec::static_size_in_bytes< HLAinteger16LE >::value);
//    BOOST_CHECK(4 == codec::static_size_in_bytes< HLAinteger32LE >::value);
//    BOOST_CHECK(8 == codec::static_size_in_bytes< HLAinteger64LE >::value);
//    BOOST_CHECK(4 == codec::static_size_in_bytes< HLAfloat32LE   >::value);
//    BOOST_CHECK(8 == codec::static_size_in_bytes< HLAfloat64LE   >::value);
//
//    BOOST_CHECK((unsigned) mpl::sizeof_<HLAoctet::value_type      >::value == codec::static_size_in_bytes< HLAoctet       >::value);
//    BOOST_CHECK((unsigned) mpl::sizeof_<HLAoctetPairBE::value_type>::value == codec::static_size_in_bytes< HLAoctetPairBE >::value);
//    BOOST_CHECK((unsigned) mpl::sizeof_<HLAinteger16BE::value_type>::value == codec::static_size_in_bytes< HLAinteger16BE >::value);
//    BOOST_CHECK((unsigned) mpl::sizeof_<HLAinteger32BE::value_type>::value == codec::static_size_in_bytes< HLAinteger32BE >::value);
//    BOOST_CHECK((unsigned) mpl::sizeof_<HLAinteger64BE::value_type>::value == codec::static_size_in_bytes< HLAinteger64BE >::value);
//    BOOST_CHECK((unsigned) mpl::sizeof_<HLAfloat32BE::value_type  >::value == codec::static_size_in_bytes< HLAfloat32BE   >::value);
//    BOOST_CHECK((unsigned) mpl::sizeof_<HLAfloat64BE::value_type  >::value == codec::static_size_in_bytes< HLAfloat64BE   >::value);
//
//    BOOST_CHECK((unsigned) mpl::sizeof_<HLAoctetPairLE::value_type>::value == codec::static_size_in_bytes< HLAoctetPairLE >::value);
//    BOOST_CHECK((unsigned) mpl::sizeof_<HLAinteger16LE::value_type>::value == codec::static_size_in_bytes< HLAinteger16LE >::value);
//    BOOST_CHECK((unsigned) mpl::sizeof_<HLAinteger32LE::value_type>::value == codec::static_size_in_bytes< HLAinteger32LE >::value);
//    BOOST_CHECK((unsigned) mpl::sizeof_<HLAinteger64LE::value_type>::value == codec::static_size_in_bytes< HLAinteger64LE >::value);
//    BOOST_CHECK((unsigned) mpl::sizeof_<HLAfloat32LE::value_type  >::value == codec::static_size_in_bytes< HLAfloat32LE   >::value);
//    BOOST_CHECK((unsigned) mpl::sizeof_<HLAfloat64LE::value_type  >::value == codec::static_size_in_bytes< HLAfloat64LE   >::value);
//
//    BOOST_CHECK(codec::octet_boundary< HLAoctet       >::value == 1UL);
//    BOOST_CHECK(codec::octet_boundary< HLAoctetPairBE >::value == 2UL);
//    BOOST_CHECK(codec::octet_boundary< HLAinteger16BE >::value == 2UL);
//    BOOST_CHECK(codec::octet_boundary< HLAinteger32BE >::value == 4UL);
//    BOOST_CHECK(codec::octet_boundary< HLAinteger64BE >::value == 8UL);
//    BOOST_CHECK(codec::octet_boundary< HLAfloat32BE   >::value == 4UL);
//    BOOST_CHECK(codec::octet_boundary< HLAfloat64BE   >::value == 8UL);
//
//    BOOST_CHECK(codec::octet_boundary< HLAoctetPairLE >::value == 2UL);
//    BOOST_CHECK(codec::octet_boundary< HLAinteger16LE >::value == 2UL);
//    BOOST_CHECK(codec::octet_boundary< HLAinteger32LE >::value == 4UL);
//    BOOST_CHECK(codec::octet_boundary< HLAinteger64LE >::value == 8UL);
//    BOOST_CHECK(codec::octet_boundary< HLAfloat32LE   >::value == 4UL);
//    BOOST_CHECK(codec::octet_boundary< HLAfloat64LE   >::value == 8UL);
//}
//
///**********************************************************************************************************************/
//
//BOOST_AUTO_TEST_CASE(test_basic_data_dynamic_size) {
//    BOOST_CHECK((unsigned) codec::dynamic_size(HLAoctet()      ) == (unsigned) codec::static_size_in_bytes< HLAoctet       >::value);
//    BOOST_CHECK((unsigned) codec::dynamic_size(HLAoctetPairBE()) == (unsigned) codec::static_size_in_bytes< HLAoctetPairBE >::value);
//    BOOST_CHECK((unsigned) codec::dynamic_size(HLAinteger16BE()) == (unsigned) codec::static_size_in_bytes< HLAinteger16BE >::value);
//    BOOST_CHECK((unsigned) codec::dynamic_size(HLAinteger32BE()) == (unsigned) codec::static_size_in_bytes< HLAinteger32BE >::value);
//    BOOST_CHECK((unsigned) codec::dynamic_size(HLAinteger64BE()) == (unsigned) codec::static_size_in_bytes< HLAinteger64BE >::value);
//    BOOST_CHECK((unsigned) codec::dynamic_size(HLAfloat32BE()  ) == (unsigned) codec::static_size_in_bytes< HLAfloat32BE   >::value);
//    BOOST_CHECK((unsigned) codec::dynamic_size(HLAfloat64BE()  ) == (unsigned) codec::static_size_in_bytes< HLAfloat64BE   >::value);
//
//    BOOST_CHECK((unsigned) codec::dynamic_size(HLAoctetPairLE()) == (unsigned) codec::static_size_in_bytes< HLAoctetPairLE >::value);
//    BOOST_CHECK((unsigned) codec::dynamic_size(HLAinteger16LE()) == (unsigned) codec::static_size_in_bytes< HLAinteger16LE >::value);
//    BOOST_CHECK((unsigned) codec::dynamic_size(HLAinteger32LE()) == (unsigned) codec::static_size_in_bytes< HLAinteger32LE >::value);
//    BOOST_CHECK((unsigned) codec::dynamic_size(HLAinteger64LE()) == (unsigned) codec::static_size_in_bytes< HLAinteger64LE >::value);
//    BOOST_CHECK((unsigned) codec::dynamic_size(HLAfloat32LE()  ) == (unsigned) codec::static_size_in_bytes< HLAfloat32LE   >::value);
//    BOOST_CHECK((unsigned) codec::dynamic_size(HLAfloat64LE()  ) == (unsigned) codec::static_size_in_bytes< HLAfloat64LE   >::value);
//}
/**********************************************************************************************************************/

BOOST_AUTO_TEST_CASE(test_encode_unsigned_13_bit_value_of_8191) {

    // Arrang.e
    boost::dynamic_bitset<> bit_sink;
    UInt13bit value = 8191;

    // Act.
    protox::dtl::codec::encode(bit_sink, value);

    // Assert.
    BOOST_CHECK_EQUAL(13, bit_sink.size());
    // BOOST_CHECK_EQUAL(0, bit_sink[0]);
    // BOOST_CHECK_EQUAL(0, bit_sink[1]);
}

BOOST_AUTO_TEST_CASE(test_encode_boolean_true) {

    // Arrang.e
    boost::dynamic_bitset<> bit_sink;
    Boolean value = true;

    // Act.
    protox::dtl::codec::encode(bit_sink, value);

    // Assert.
    BOOST_CHECK_EQUAL(1, bit_sink.size());
    BOOST_CHECK_EQUAL(1, bit_sink[0]);
}

BOOST_AUTO_TEST_CASE(test_encode_boolean_false) {

    // Arrang.e
    boost::dynamic_bitset<> bit_sink;
    Boolean value = false;

    // Act.
    protox::dtl::codec::encode(bit_sink, value);

    // Assert.
    BOOST_CHECK_EQUAL(1, bit_sink.size());
    BOOST_CHECK_EQUAL(0, bit_sink[0]);
}

BOOST_AUTO_TEST_CASE(test_encode_unsigned_2_bit_value_of_00) {

    // Arrang.e
    boost::dynamic_bitset<> bit_sink;
    UInt02bit value = 0b00;

    // Act.
    protox::dtl::codec::encode(bit_sink, value);

    // Assert.
    BOOST_CHECK_EQUAL(2, bit_sink.size());
    BOOST_CHECK_EQUAL(0, bit_sink[0]);
    BOOST_CHECK_EQUAL(0, bit_sink[1]);
}

BOOST_AUTO_TEST_CASE(test_encode_unsigned_2_bit_value_of_01) {

    // Arrang.e
    boost::dynamic_bitset<> bit_sink;
    UInt02bit value = 0b01;

    // Act.
    protox::dtl::codec::encode(bit_sink, value);

    // Assert.
    BOOST_CHECK_EQUAL(2, bit_sink.size());
    BOOST_CHECK_EQUAL(1, bit_sink[0]);
    BOOST_CHECK_EQUAL(0, bit_sink[1]);
}

BOOST_AUTO_TEST_CASE(test_encode_unsigned_2_bit_value_of_10) {

    // Arrang.e
    boost::dynamic_bitset<> bit_sink;
    UInt02bit value = 0b10;

    // Act.
    protox::dtl::codec::encode(bit_sink, value);

    // Assert.
    BOOST_CHECK_EQUAL(2, bit_sink.size());
    BOOST_CHECK_EQUAL(0, bit_sink[0]);
    BOOST_CHECK_EQUAL(1, bit_sink[1]);
}

BOOST_AUTO_TEST_CASE(test_encode_unsigned_2_bit_value_of_11) {

    // Arrang.e
    boost::dynamic_bitset<> bit_sink;
    UInt02bit value = 0b11;

    // Act.
    protox::dtl::codec::encode(bit_sink, value);

    // Assert.
    BOOST_CHECK_EQUAL(2, bit_sink.size());
    BOOST_CHECK_EQUAL(1, bit_sink[0]);
    BOOST_CHECK_EQUAL(1, bit_sink[1]);
}

BOOST_AUTO_TEST_CASE(test_encode_signed_2_bit_value_of_11) {

    // Arrang.e
    boost::dynamic_bitset<> bit_sink;
    Int02bit value = 0b11;

    // Act.
    protox::dtl::codec::encode(bit_sink, value);

    // Assert.
    BOOST_CHECK_EQUAL(2, bit_sink.size());
    BOOST_CHECK_EQUAL(1, bit_sink[0]);
    BOOST_CHECK_EQUAL(1, bit_sink[1]);
}

///**********************************************************************************************************************/
//
//BOOST_AUTO_TEST_CASE(test_encode_HLAoctetPairBE) {
//
//    protox::io::byte_data_sink sink;
//
//    HLAoctetPairBE octet_pair = 'X';
//    sink.encode(octet_pair);
//
//    BOOST_CHECK(sink.size() == 2);
//
//    BOOST_CHECK(sink.getDataBuffer()[0] ==  0 );
//    BOOST_CHECK(sink.getDataBuffer()[1] == 'X');
//}
//
///**********************************************************************************************************************/
//
//BOOST_AUTO_TEST_CASE(test_encode_HLAinteger16BE) {
//
//    protox::io::byte_data_sink sink;
//
//    HLAinteger16BE int16BE = 23171;
//    sink.encode(int16BE);
//
//    BOOST_CHECK(sink.size() == 2);
//    BOOST_CHECK(ntohs(*((HLAinteger16BE *) sink.getDataBuffer())) == 23171);
//}
//
///**********************************************************************************************************************/
//
//BOOST_AUTO_TEST_CASE(test_encode_HLAinteger32BE) {
//
//    protox::io::byte_data_sink sink;
//
//    HLAinteger32BE int32BE = -36894;
//    sink.encode(int32BE);
//
//    BOOST_CHECK(sink.size() == 4);
//    HLAinteger32BE value = SYS_NTOHL(*((HLAinteger32BE *) sink.getDataBuffer()));
//    BOOST_CHECK(value == -36894);
//}
//
///**********************************************************************************************************************/
//
//BOOST_AUTO_TEST_CASE(test_encode_HLAinteger64BE) {
//
//    protox::io::byte_data_sink sink;
//
//    HLAinteger64BE int64BE = -36894;
//    sink.encode(int64BE);
//
//    BOOST_CHECK(sink.size() == 8);
//
//    HLAinteger32BE lowBytes  = SYS_NTOHL(*((HLAinteger32BE *) (sink.getDataBuffer() + 4)));
//    HLAinteger32BE highBytes = SYS_NTOHL(*((HLAinteger32BE *)  sink.getDataBuffer()     ));
//
//    HLAinteger64BE value = 0;
//
//    char *vp = (char *) &value;
//
//    vp[0] = sink.getDataBuffer()[7];
//    vp[1] = sink.getDataBuffer()[6];
//    vp[2] = sink.getDataBuffer()[5];
//    vp[3] = sink.getDataBuffer()[4];
//    vp[4] = sink.getDataBuffer()[3];
//    vp[5] = sink.getDataBuffer()[2];
//    vp[6] = sink.getDataBuffer()[1];
//    vp[7] = sink.getDataBuffer()[0];
//
//    BOOST_CHECK(value == -36894);
//}
//
///**********************************************************************************************************************/
//
//BOOST_AUTO_TEST_CASE(test_encode_HLAfloat32BE) {
//
//    protox::io::byte_data_sink sink;
//
//    HLAfloat32BE float32BE = 5.67e-3f;
//    sink.encode(float32BE);
//
//    BOOST_CHECK(sink.size() == 4);
//    HLAinteger32BE leValue = SYS_NTOHL(*((HLAinteger32BE *) sink.getDataBuffer()));
//
//    HLAfloat32BE *value = (HLAfloat32BE *) &leValue;
//
//    BOOST_CHECK(((*value) - 5.67e-3) <= 0.00001);
//}
//
///**********************************************************************************************************************/
//
//BOOST_AUTO_TEST_CASE(test_encode_HLAfloat64BE) {
//
//    protox::io::byte_data_sink sink;
//
//    HLAfloat64BE float64BE = 5.67e-3;
//    sink.encode(float64BE);
//
//    BOOST_CHECK(sink.size() == 8);
//
//    HLAfloat64BE value;
//    char *vp = (char *) &value;
//
//    vp[0] = sink.getDataBuffer()[7];
//    vp[1] = sink.getDataBuffer()[6];
//    vp[2] = sink.getDataBuffer()[5];
//    vp[3] = sink.getDataBuffer()[4];
//    vp[4] = sink.getDataBuffer()[3];
//    vp[5] = sink.getDataBuffer()[2];
//    vp[6] = sink.getDataBuffer()[1];
//    vp[7] = sink.getDataBuffer()[0];
//
//    BOOST_CHECK((value - 5.67e-3) <= 0.00001);
//}
//
///**********************************************************************************************************************/
//
//BOOST_AUTO_TEST_CASE(test_decode_HLAoctet) {
//
//    protox::io::byte_data_sink sink;
//
//    HLAoctet octet = 'Q';
//    sink.encode(octet);
//
//    BOOST_CHECK(sink.size()             ==  1 );
//    BOOST_CHECK(sink.getDataBuffer()[0] == 'Q');
//
//    protox::io::byte_data_source source(sink);
//
//    HLAoctet octet_d = 0;
//    source.decode(octet_d);
//
//    BOOST_CHECK(octet_d == 'Q');
//}
//
///**********************************************************************************************************************/
//
//BOOST_AUTO_TEST_CASE(test_decode_HLAoctetPairBE) {
//
//    protox::io::byte_data_sink sink;
//
//    HLAoctetPairBE octet_pair = 'X';
//    sink.encode(octet_pair);
//
//    BOOST_CHECK(sink.size()             == 2);
//    BOOST_CHECK(sink.getDataBuffer()[0] == 0);
//
//    BOOST_CHECK(sink.getDataBuffer()[1] == 'X');
//
//    protox::io::byte_data_source source(sink);
//
//    HLAoctetPairBE octet_pair_d = 0;
//    source.decode(octet_pair_d);
//
//    BOOST_CHECK(octet_pair_d == 'X');
//}
//
///**********************************************************************************************************************/
//
//BOOST_AUTO_TEST_CASE( test_decode_HLAinteger16BE ) {
//
//    protox::io::byte_data_sink sink;
//
//    HLAinteger16BE int16BE = 23171;
//    sink.encode(int16BE);
//
//    BOOST_CHECK(sink.size() == 2);
//    BOOST_CHECK(ntohs(*((HLAinteger16BE *) sink.getDataBuffer())) == 23171);
//
//    protox::io::byte_data_source source(sink);
//    HLAinteger16BE int16BE_d = 0;
//    source.decode(int16BE_d);
//
//    BOOST_CHECK(int16BE_d == 23171);
//}
//
///**********************************************************************************************************************/
//
//BOOST_AUTO_TEST_CASE(test_decode_HLAinteger32BE) {
//
//    protox::io::byte_data_sink sink;
//
//    HLAinteger32BE int32BE = -36894;
//    sink.encode(int32BE);
//
//    BOOST_CHECK(sink.size() == 4);
//    HLAinteger32BE value = SYS_NTOHL(*((HLAinteger32BE *) sink.getDataBuffer()));
//    BOOST_CHECK(value == -36894);
//
//    protox::io::byte_data_source source(sink);
//    HLAinteger32BE int32BE_d = 0;
//    source.decode(int32BE_d);
//
//    BOOST_CHECK(int32BE_d == -36894);
//}
//
///**********************************************************************************************************************/
//
//BOOST_AUTO_TEST_CASE(test_decode_HLAinteger64BE) {
//
//    protox::io::byte_data_sink sink;
//
//    HLAinteger64BE int64BE = -36894;
//    sink.encode(int64BE);
//
//    BOOST_CHECK(sink.size() == 8);
//
//    protox::io::byte_data_source source(sink);
//    HLAinteger64BE int64BE_d = 0;
//    source.decode(int64BE_d);
//
//    BOOST_CHECK(int64BE_d == -36894);
//}
//
///**********************************************************************************************************************/
//
//BOOST_AUTO_TEST_CASE(test_decode_HLAfloat32BE) {
//
//    protox::io::byte_data_sink sink;
//
//    HLAfloat32BE float32BE = 5.67e-3f;
//    sink.encode(float32BE);
//
//    BOOST_CHECK(sink.size() == 4);
//    HLAinteger32BE leValue = SYS_NTOHL(*((HLAinteger32BE *) sink.getDataBuffer()));
//
//    HLAfloat32BE *value = (HLAfloat32BE *) &leValue;
//
//    BOOST_CHECK(((*value) - 5.67e-3) <= 0.00001);
//
//    protox::io::byte_data_source source(sink);
//    HLAfloat32BE float32BE_d = 0.0f;
//    source.decode(float32BE_d);
//
//    BOOST_CHECK(fabs(float32BE_d - 5.67e-3) <= 0.00001);
//}
//
///**********************************************************************************************************************/
//
//BOOST_AUTO_TEST_CASE(test_decode_HLAfloat64BE) {
//
//    protox::io::byte_data_sink sink;
//
//    HLAfloat64BE float64BE = 5.67e-3;
//    sink.encode(float64BE);
//
//    BOOST_CHECK(sink.size() == 8);
//
//    protox::io::byte_data_source source(sink);
//    HLAfloat64BE float64BE_d = 0.0;
//    source.decode(float64BE_d);
//
//    BOOST_CHECK(fabs(float64BE_d - 5.67e-3) <= 0.00001);
//}

}
