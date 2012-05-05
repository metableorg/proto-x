/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/**********************************************************************************************************************/

#ifndef PROTOX_OM_RPR_REPAIR_RESULT_ENUM8_HPP
#define PROTOX_OM_RPR_REPAIR_RESULT_ENUM8_HPP

/**********************************************************************************************************************/

#include "protox/dtl/enum_pp.hpp"

#include "protox/hla_13/enumerated.hpp"
#include "protox/hla_13/basic_data_representation_table.hpp"

/**********************************************************************************************************************/

namespace protox { namespace om { namespace rpr {

/**********************************************************************************************************************/

using namespace protox;
using namespace protox::hla_13;

/**********************************************************************************************************************/

//      +-------------------+--------------------------------------------------+-----------------------------+--------+
//      | Name              | Representation                                   | Enumerator                  | Values |
//      +-------------------+--------------------------------------------------+-----------------------------+--------+
namespace RepairResultEnum8 { PROTOX_ENUM_TYPE(HLA13octet, hla_13::enumerated) ;
                                                              PROTOX_ENUM_VALUE( Other,                            0 );
                                                              PROTOX_ENUM_VALUE( RepairEnded,                      1 );
                                                              PROTOX_ENUM_VALUE( InvalidRepair,                    2 );
                                                              PROTOX_ENUM_VALUE( RepairInterrupted,                3 );
                                                              PROTOX_ENUM_VALUE( ServiceCanceledByTheSupplier,     4 );
//      +-------------------+--------------------------------------------------+-----------------------------+--------+

PROTOX_ENUM_EQUALITY_OPERATOR;
PROTOX_ENUM_DEFAULT(Other);

}

/**********************************************************************************************************************/

}}}

/**********************************************************************************************************************/

#endif

/**********************************************************************************************************************/
