/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/******************************************************************************/

#ifndef SOM_BOCCERBALL_TARGET_STATE_ENUM_HPP
#define SOM_BOCCERBALL_TARGET_STATE_ENUM_HPP

/******************************************************************************/

#include "protox/dtl/enum_pp.hpp"

#include "protox/hla_1516/enumerated.hpp"
#include "protox/hla_1516/basic_data_representation_table.hpp"

/******************************************************************************/

namespace som { namespace boccerball { namespace TargetStateEnum {

/******************************************************************************/

using namespace protox::hla_1516;

/******************************************************************************/

PROTOX_ENUM_TYPE( HLAinteger16BE, enumerated );

/******************************************************************************/

PROTOX_ENUM_VALUE( IN_START_POS, 1 );
PROTOX_ENUM_VALUE( IN_PLAY,      2 );
PROTOX_ENUM_VALUE( IN_RETURN,    3 );

/******************************************************************************/

PROTOX_ENUM_EQUALITY_OPERATOR;
PROTOX_ENUM_DEFAULT( IN_START_POS );

/******************************************************************************/

}}}

#endif