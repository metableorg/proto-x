
/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/******************************************************************************/

#ifndef PROTOX_EXAMPLES_RGB_FED_AMB
#define PROTOX_EXAMPLES_RGB_FED_AMB

/******************************************************************************/

#include <iostream>
#include <string>

#include <fedtime.hh>
#include <RTI.hh>
#include <NullFederateAmbassador.hh>

#include "inter_fed_amb.hpp"

/******************************************************************************/

class rgb_fed_amb : public NullFederateAmbassador
{
private:
  inter_amb_type &inter_amb;
  
private:
  static double convert_time( const RTI::FedTime &the_time )
  {
	  return ((RTIfedTime) the_time).getTime();
  }

public:
  double fed_time;
  double fed_lookahead_time;

  bool is_announced;
  bool is_ready_to_run;
  bool is_regulating;
  bool is_constrained;
  bool is_advancing;
  
  rgb_fed_amb( inter_amb_type &inter_amb ) :
    inter_amb( inter_amb ),
    fed_time( 0.0 ),
    fed_lookahead_time( 1.0 ),
    is_announced( false ),
    is_ready_to_run( false ),
    is_regulating( false ),
    is_constrained( false ),
    is_advancing( false )
  {}

  virtual ~rgb_fed_amb() throw( RTI::FederateInternalError ) {} 
  
  virtual void announceSynchronizationPoint( const char *label, const char *tag )
    //throw( RTI::FederateInternalError )
  {
	  std::cout << "Synchronization point announced: " << label << std::endl;

    if( std::string(label) == "ReadyToRun" )	
	  {
		  is_announced = true;
    }
  }

  virtual void federationSynchronized( const char *label )
  {
	  std::cout << "Federation Synchronized: " << label << std::endl;
    if( std::string(label) == "ReadyToRun" )
    {
	  	is_ready_to_run = true;
    }
  }

  ///////////////////////////////////////////////////////////////////////////////
  //////////////////////////////// Time Callbacks ///////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////
  virtual void timeRegulationEnabled( const RTI::FedTime &theFederateTime )
  {
  	is_regulating = true;
  	fed_time = convert_time( theFederateTime );
  }

  virtual void timeConstrainedEnabled( const RTI::FedTime &theFederateTime )
  {
  	is_constrained = true;
  	fed_time = convert_time( theFederateTime );
  }

  virtual void timeAdvanceGrant( const RTI::FedTime &theTime )
  {
  	is_advancing = false;
  	fed_time = convert_time( theTime );
  }

    virtual void receiveInteraction
    ( RTI::InteractionClassHandle theInteraction,
      const RTI::ParameterHandleValuePairSet &theParameters,
      const RTI::FedTime &theTime,
      const char *theTag,
      RTI::EventRetractionHandle        theHandle )
  {
    inter_amb.recv_interaction( theInteraction, theParameters, &theTime, theTag );
  }

  virtual void receiveInteraction
  ( RTI::InteractionClassHandle theInteraction,
    const RTI::ParameterHandleValuePairSet& theParameters,
    const char *theTag )
  {
    unsigned count = theParameters.size();

    inter_amb.recv_interaction( theInteraction, theParameters, 0, theTag );
  }
};

/******************************************************************************/

#endif

/******************************************************************************/
