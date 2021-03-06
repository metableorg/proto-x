/*
    Copyright (C) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/**********************************************************************************************************************/

#ifndef PROTOX_DTL_FIELD_HPP
#define PROTOX_DTL_FIELD_HPP

/**********************************************************************************************************************/

namespace protox {
namespace dtl {

/**********************************************************************************************************************/

/// \cond
template< typename T >
struct field_base {
    typename T::value_type value;
};
/// \endcond

/**
 * Defines a field used in the definition of a fixed record.
 *
 * \tparam T The field's datatype.
 *
 * \sa protox::dtl::fixed_record
 */
template< typename T >
struct field {
    typedef T value_type;
};

/**********************************************************************************************************************/

}}

/**********************************************************************************************************************/

#endif

/**********************************************************************************************************************/
