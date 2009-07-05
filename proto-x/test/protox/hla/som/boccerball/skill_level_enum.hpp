/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/******************************************************************************/

#ifndef SOM_BOCCERBALL_SKILL_LEVEL_ENUM_HPP
#define SOM_BOCCERBALL_SKILL_LEVEL_ENUM_HPP

/******************************************************************************/

#include "protox/dtl/enum_pp.hpp"

#include "protox/hla_1516/enumerated.hpp"
#include "protox/hla_1516/basic_data_representation_table.hpp"

/******************************************************************************/

namespace som { namespace boccerball { namespace SkillLevelEnum {

/******************************************************************************/

using namespace protox::hla_1516;

/******************************************************************************/

PROTOX_ENUM_TYPE( HLAinteger16BE, enumerated );

/******************************************************************************/

PROTOX_ENUM_VALUE( POOR,      1 );
PROTOX_ENUM_VALUE( GOOD,      2 );
PROTOX_ENUM_VALUE( EXCELLENT, 3 );

/******************************************************************************/

PROTOX_ENUM_EQUALITY_OPERATOR;
PROTOX_ENUM_DEFAULT( GOOD );

/******************************************************************************/

}}}

#endif
