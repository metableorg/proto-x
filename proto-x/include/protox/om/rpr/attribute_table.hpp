/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/**********************************************************************************************************************/

#ifndef PROTOX_OM_RPR_ATTRIBUTE_TABLE_HPP
#define PROTOX_OM_RPR_ATTRIBUTE_TABLE_HPP

/**********************************************************************************************************************/

#include <protox/hla/attr.hpp>
#include <protox/hla/keywords.hpp>
#include <protox/hla/name.hpp>

#include <protox/hla_13/basic_data_representation_table.hpp>

#include <protox/om/rpr/acceleration_vector_struct.hpp>
#include <protox/om/rpr/angular_velocity_vector_struct.hpp>
#include <protox/om/rpr/dead_reckoning_algorithm_enum8.hpp>
#include <protox/om/rpr/entity_type_struct.hpp>
#include <protox/om/rpr/entity_identifier_struct.hpp>
#include <protox/om/rpr/bool_enum8.hpp>
#include <protox/om/rpr/orientation_struct.hpp>
#include <protox/om/rpr/world_location_struct.hpp>
#include <protox/om/rpr/velocity_vector_struct.hpp>
#include <protox/om/rpr/designator_code_name_enum16.hpp>
#include <protox/om/rpr/rti_object_id_struct.hpp>
#include <protox/om/rpr/designator_code_enum16.hpp>
#include <protox/om/rpr/world_location_struct.hpp>
#include <protox/om/rpr/relative_position_struct.hpp>
#include <protox/om/rpr/beam_function_code_enum8.hpp>
#include <protox/om/rpr/event_identifier_struct.hpp>
#include <protox/om/rpr/emitter_function_code_enum8.hpp>
#include <protox/om/rpr/emitter_type_enum16.hpp>

/**********************************************************************************************************************/

namespace protox { namespace om { namespace rpr {

/**********************************************************************************************************************/

using namespace protox;
using namespace protox::hla;

/**********************************************************************************************************************/

//   +------------------------------------------------+------------------------------+-------------------------------------------+-------------------------------------------+
//   | Name                                           | Attribute                    | Datatype                                  | String Name                               |
//   +------------------------------------------------+------------------------------+-------------------------------------------+-------------------------------------------+
struct HLAobjectRoot   { HLA_NAME("HLAobjectRoot")   };
//   +------------------------------------------------+------------------------------+-------------------------------------------+-------------------------------------------+
struct BaseEntity      { HLA_NAME("BaseEntity")      };
                                                 struct AccelerationVector           : attr< AngularVelocityVectorStruct::type > { HLA_NAME("AccelerationVector")           };
                                                 struct AngularVelocityVector        : attr< AngularVelocityVectorStruct::type > { HLA_NAME("AngularVelocityVector")        };
                                                 struct DeadReckoningAlgorithm       : attr< DeadReckoningAlgorithmEnum8::type > { HLA_NAME("DeadReckoningAlgorithm")       };
                                                 struct EntityType                   : attr< EntityTypeStruct::type            > { HLA_NAME("EntityType")                   };
                                                 struct EntityIdentifier             : attr< EntityIdentifierStruct::type      > { HLA_NAME("EntityIdentifier")             };
                                                 struct IsFrozen                     : attr< BoolEnum8::type                   > { HLA_NAME("IsFrozen")                     };
                                                 struct Orientation                  : attr< OrientationStruct::type           > { HLA_NAME("Orientation")                  };
                                                 struct WorldLocation                : attr< WorldLocationStruct::type         > { HLA_NAME("WorldLocation")                };
                                                 struct VelocityVector               : attr< VelocityVectorStruct::type        > { HLA_NAME("VelocityVector")               };
//   +------------------------------------------------+------------------------------+-------------------------------------------+-------------------------------------------+
struct CulturalFeature { HLA_NAME("CulturalFeature") };
                                                 struct ExternalLightsOn             : attr< BoolEnum8::type                   > { HLA_NAME("ExternalLightsOn")             };
                                                 struct InternalHeatSourceOn         : attr< BoolEnum8::type                   > { HLA_NAME("InternalHeatSourceOn")         };
                                                 struct InternalLightsOn             : attr< BoolEnum8::type                   > { HLA_NAME("InternalLightsOn")             };
//   +------------------------------------------------+------------------------------+-------------------------------------------+-------------------------------------------+
struct Designator { HLA_NAME("Designator")           };
                                                 struct CodeName                     : attr< DesignatorCodeNameEnum16::type    > { HLA_NAME("CodeName")                     };
                                                 struct DesignatedObjectIdentifier   : attr< RTIObjectIdStruct::type           > { HLA_NAME("DesignatedObjectIdentifier")   };
                                                 struct DesignatorCode               : attr< DesignatorCodeEnum16::type        > { HLA_NAME("DesignatorCode")               };
                                                 struct DesignatorEmissionWavelength : attr< hla_13::HLA13float                > { HLA_NAME("DesignatorEmissionWavelength") };
                                                 struct DesignatorOutputPower        : attr< hla_13::HLA13float                > { HLA_NAME("DesignatorOutputPower")        };
                                                 struct DesignatorSpotLocation       : attr< WorldLocationStruct::type         > { HLA_NAME("DesignatorSpotLocation")       };
                                              // struct DeadReckoningAlgorithm       : attr< DeadReckoningAlgorithmEnum8::type > { HLA_NAME("DeadReckoningAlgorithm")       };
                                                 struct RelativeSpotLocation         : attr< RelativePositionStruct::type      > { HLA_NAME("RelativeSpotLocation")         };
                                                 struct SpotLinearAccelerationVector : attr< AccelerationVectorStruct::type    > { HLA_NAME("SpotLinearAccelerationVector") };
//   +------------------------------------------------+------------------------------+-------------------------------------------+-------------------------------------------+
struct EmbeddedSystem { HLA_NAME("EmbeddedSystem")   };
                                              // struct EntityIdentifier             : attr< EntityIdentifierStruct::type      > { HLA_NAME("EntityIdentifier")             };
                                                 struct HostObjectIdentifier         : attr< RTIObjectIdStruct::type           > { HLA_NAME("HostObjectIdentifier")         };
                                                 struct RelativePosition             : attr< RelativePositionStruct::type      > { HLA_NAME("RelativePosition")             };
//   +------------------------------------------------+------------------------------+-------------------------------------------+-------------------------------------------+
struct EmitterBeam { HLA_NAME("EmitterBeam")         };
                                                 struct BeamAzimuthCenter            : attr< hla_13::HLA13float                > { HLA_NAME("BeamAzimuthCenter")            };
                                                 struct BeamAzimuthSweep             : attr< hla_13::HLA13float                > { HLA_NAME("BeamAzimuthSweep")             };
                                                 struct BeamElevationCenter          : attr< hla_13::HLA13float                > { HLA_NAME("BeamElevationCenter")          };
                                                 struct BeamElevationSweep           : attr< hla_13::HLA13float                > { HLA_NAME("BeamElevationSweep")           };
                                                 struct BeamFunctionCode             : attr< BeamFunctionCodeEnum8::type       > { HLA_NAME("BeamFunctionCode")             };
                                                 struct BeamIdentifier               : attr< hla_13::HLA13octet                > { HLA_NAME("BeamIdentifier")               };
                                                 struct BeamParameterIndex           : attr< hla_13::HLA13unsigned_short       > { HLA_NAME("BeamParameterIndex")           };
                                                 struct EffectiveRadiatedPower       : attr< hla_13::HLA13float                > { HLA_NAME("EffectiveRadiatedPower")       };
                                                 struct EmissionFrequency            : attr< hla_13::HLA13float                > { HLA_NAME("EmissionFrequency")            };
                                                 struct EmitterSystemIdentifier      : attr< RTIObjectIdStruct::type           > { HLA_NAME("EmitterSystemIdentifier")      };
                                                 struct EventIdentifier              : attr< EventIdentifierStruct::type       > { HLA_NAME("EventIdentifier")              };
                                                 struct FrequencyRange               : attr< hla_13::HLA13float                > { HLA_NAME("FrequencyRange")               };
                                                 struct PulseRepetitionFrequency     : attr< hla_13::HLA13float                > { HLA_NAME("PulseRepetitionFrequency")     };
                                                 struct PulseWidth                   : attr< hla_13::HLA13float                > { HLA_NAME("PulseWidth")                   };
                                                 struct SweepSynch                   : attr< hla_13::HLA13float                > { HLA_NAME("SweepSynch")                   };
//   +------------------------------------------------+------------------------------+-------------------------------------------+-------------------------------------------+
struct EmitterSystem { HLA_NAME("EmitterSystem")     };
                                                struct EmitterFunctionCode           : attr< BeamFunctionCodeEnum8::type       > { HLA_NAME("EmitterFunctionCode")          };
                                                struct EmitterType                   : attr< EmitterTypeEnum16::type           > { HLA_NAME("EmitterType")                  };
                                                struct EmitterIndex                  : attr< hla_13::HLA13octet                > { HLA_NAME("EmitterIndex")                 };
                                            //  struct EventIdentifier               : attr< EventIdentifierStruct::type       > { HLA_NAME("EventIdentifier")              };

/**********************************************************************************************************************/

}}}

/**********************************************************************************************************************/

#endif

/**********************************************************************************************************************/
