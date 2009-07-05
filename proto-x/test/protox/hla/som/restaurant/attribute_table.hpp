/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/******************************************************************************/

#ifndef SOM_RESTAURANT_ATTRIBUTE_TABLE_HPP
#define SOM_RESTAURANT_ATTRIBUTE_TABLE_HPP

/******************************************************************************/

#include <protox/hla/attr.hpp>
#include <protox/hla/keywords.hpp>
#include <protox/hla/name.hpp>

/******************************************************************************/

namespace som { namespace restaurant {

/******************************************************************************/

using namespace protox::hla;

/******************************************************************************/

////// Attribute Table ////////////////////////////
//     +------------------------------------------+----------------------------+--------------+----------------------------------------+
//     | Name                                     | Attribute                  | Datatype     | String Name                            |
//     +------------------------------------------+----------------------------+--------------+----------------------------------------+
  struct HLAobjectRoot {HLA_NAME("HLAobjectRoot")};
                                             struct HLAprivilegeToDeleteObject : attr< int >  { HLA_NAME("HLAprivilegeToDeleteObject")};
//     +------------------------------------------+----------------------------+--------------+----------------------------------------+
  struct Employee      {HLA_NAME("Employee")};
                                             struct PayRate                    : attr< int >  { HLA_NAME("PayRate")};
                                             struct YearsOfService             : attr< int >  { HLA_NAME("YearsOfService")};
                                             struct HomeNumber                 : attr< int >  { HLA_NAME("HomeNumber")};
                                             struct HomeAddress                : attr< int >  { HLA_NAME("HomeAddress")};
//     +------------------------------------------+----------------------------+--------------+----------------------------------------+
  struct Waiter        {HLA_NAME("Waiter")};
                                             struct Efficiency                 : attr< int >  { HLA_NAME("Efficiency")};
                                             struct Cheerfulness               : attr< int >  { HLA_NAME("Cheerfulness")};
                                             struct State                      : attr< int >  { HLA_NAME("State")};
//     +------------------------------------------+----------------------------+--------------+----------------------------------------+
  struct DishWasher    {HLA_NAME("DishWasher")};
                                             struct CleaningRate               : attr< int >  { HLA_NAME("CleaningRate")};
//     +------------------------------------------+----------------------------+--------------+----------------------------------------+
  struct Food          {HLA_NAME("Food")};
                                             struct Price                      : attr< int >  { HLA_NAME("Price")};
//     +------------------------------------------+----------------------------+--------------+----------------------------------------+
  struct Entree        {HLA_NAME("Entree")};
                                             struct MenuItem                   : attr< int >  { HLA_NAME("MenuItem")};
//     +------------------------------------------+----------------------------+--------------+----------------------------------------+
  struct Beef          {HLA_NAME("Beef")};
                                             struct TypeOfCut                  : attr< int >  { HLA_NAME("TypeOfCut")};
//     +------------------------------------------+----------------------------+--------------+----------------------------------------+
  struct Seafood       {HLA_NAME("Seafood")};
//     +------------------------------------------+----------------------------+--------------+----------------------------------------+
  struct Dessert       {HLA_NAME("Dessert")};
//     +------------------------------------------+----------------------------+--------------+----------------------------------------+

/******************************************************************************/

}}

/******************************************************************************/

#endif

/******************************************************************************/