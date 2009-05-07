/*
    Copyright (c) 2009 Jay Graham

    Distributed under the MIT License (see accompanying file LICENSE_1_0_0.txt
    or http://www.opensource.org/licenses/mit-license.php)
*/

/**************************************************************************************************/
 
#ifndef PROTOX_HLA_SOM_HPP
#define PROTOX_HLA_SOM_HPP

/**************************************************************************************************/

#include <RTI.hh>

#include <string>
#include <vector>
#include <map>
#include <assert.h>
#include <iostream>

#include <boost/mpl/vector.hpp>
#include <boost/mpl/set.hpp>
#include <boost/mpl/erase.hpp>
#include <boost/mpl/push_back.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/for_each.hpp>
#include <boost/mpl/find_if.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/inherit.hpp>
#include <boost/mpl/inherit_linearly.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/transform_view.hpp>
#include <boost/mpl/back_inserter.hpp>
#include <boost/mpl/map.hpp>
#include <boost/mpl/lambda.hpp>
#include <boost/mpl/copy.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/back_inserter.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

#include <protox/hla/name_to_o_class_handle_map.hpp>
#include <protox/hla/class_handle_to_attr_handle_map.hpp>

/**************************************************************************************************/

namespace protox { namespace hla {

/**************************************************************************************************/

using namespace boost;
using namespace protox;

/**************************************************************************************************/

struct print_stack
{
  print_stack() {}

  template< typename N >
  void operator()(N)
  {
    std::cout << N::name_type::name() << ".";
  }
};

struct build_full_name
{
  std::string &full_name;
  
  build_full_name(std::string &fn) : full_name(fn) {}

  template< typename N >
  void operator()(N)
  {
    if (full_name.empty())
      full_name = std::string(N::name_type::name()); 
    else
      full_name = std::string(N::name_type::name()) + "." + full_name; 
  }
};

struct init_attr_handle
{
  RTI::RTIambassador &rtiAmb;
  RTI::ObjectClassHandle class_handle;
  o_class_handle_to_attr_map &map;
  
  init_attr_handle(
    RTI::RTIambassador &rtiAmb,
    RTI::ObjectClassHandle ch,
    o_class_handle_to_attr_map &m
  ) :
    rtiAmb(rtiAmb),
    class_handle(ch),
    map(m)
  {}

  template< typename N >
  void operator()(N)
  {
    std::cout << "   class handle : " << class_handle << " attr : " << N::name() << "\n";
    // Find the class handle entry
    o_class_handle_to_attr_map::iterator i = map.find(class_handle);

    if (i == map.end())
    {
      map[class_handle] = attr_name_to_handle_map();
    }

    // Find the attribute handle by name
    attr_name_to_handle_map::iterator j = map[class_handle].find(N::name());

    // No entry for the attribute name?
    if (j == map[class_handle].end())
    {
      map[class_handle][N::name()] = rtiAmb.getAttributeHandle(N::name(), class_handle);
    }
  }
};

template< typename T, typename Stack > struct dfs; // forward declaration

template< bool empty, typename Children, typename Stack > struct dfs_children;

/**
 *
 */
template< typename Children, typename Stack >
struct dfs_children< false, Children, Stack >
{
  // Separate the first child from the rest.
  typedef typename mpl::front< Children >::type first_child;

  // Get the remaining children (i.e, the tail of the child vector)
  typedef typename mpl::erase< Children, mpl::front< Children > >::type tail;

  // Traverse the first child of the given Children vector.
  typedef dfs< first_child, Stack > stack;

  // Traverse the remaining children.
  typedef dfs_children< mpl::empty<tail>::value, tail, typename stack::type > result;
  typedef typename result::type type;

  static void dump_stack()
  {
    stack::dump_stack();
    result::dump_stack();
  };
  
  static void init_o_class_handles(RTI::RTIambassador &rtiAmb,
    name_to_o_class_handle_map &class_map,
    o_class_handle_to_attr_map &attr_map)
  {
    stack::init_o_class_handles(rtiAmb, class_map, attr_map);
    result::init_o_class_handles(rtiAmb, class_map, attr_map);
  }
};

template< typename Children, typename Stack >
struct dfs_children< true, Children, Stack >
{
  typedef typename mpl::pop_front< Stack >::type type;

  static void dump_stack()
  {
    mpl::for_each< Stack >( print_stack() );
    std::cout << "null\n";
  }
  
  static void init_o_class_handles(
    RTI::RTIambassador &rtiAmb,
    name_to_o_class_handle_map &class_map,
    o_class_handle_to_attr_map &attr_map)
  {
    std::string full_name;
    mpl::for_each< Stack >(build_full_name(full_name));
    
    //std::cout << "full name : " << full_name.c_str() << "\n";
    
    RTI::ObjectClassHandle class_handle = rtiAmb.getObjectClassHandle(full_name.c_str());
    class_map[full_name] = class_handle;
    
    typedef typename mpl::front< Stack >::type child;
    
    mpl::for_each< typename child::attr_list_type >
      (init_attr_handle(rtiAmb, class_handle, attr_map));
  }
};

/**
 * Perform a depth first traversal of the given tree T.  
 */
template< typename T, typename Stack = mpl::vector<> >
struct dfs
{
  // Push the root of the tree onto a stack.  
  typedef typename mpl::push_front< Stack, T >::type stack;

  // Continue the traversl by recursively looping over the children of T.
  typedef dfs_children<
    mpl::empty< typename T::child_list_type >::value,
    typename T::child_list_type,
    stack
  > result;
  
  typedef typename result::type type;

  static void dump_stack()
  {
    result::dump_stack();
  }
  
  static void init_o_class_handles(
    RTI::RTIambassador &rtiAmb,
    name_to_o_class_handle_map &class_map,
    o_class_handle_to_attr_map &attr_map)
  {
    result::init_o_class_handles(rtiAmb, class_map, attr_map);
  }
};
  
template< typename ROOT_O_CLASS >
struct som
{
private:
  typedef dfs< ROOT_O_CLASS > dfs_type;
    
  static hla::name_to_o_class_handle_map &
  get_name_to_o_class_handle_map()
  {
    static protox::hla::name_to_o_class_handle_map map;
    return map;
  }

  static hla::o_class_handle_to_attr_map &
  get_o_class_handle_to_attr_map()
  {
    static hla::o_class_handle_to_attr_map map;
    return map;
  }

  static void init_o_class_handles(RTI::RTIambassador &rtiAmb)
  {
    hla::name_to_o_class_handle_map &o_class_map = get_name_to_o_class_handle_map();
      
    // Maps is already populated? 
    if (!o_class_map.empty())
      return;
      
    hla::o_class_handle_to_attr_map &attr_map = get_o_class_handle_to_attr_map();

    assert(attr_map.empty());
      
    dfs_type::init_o_class_handles(rtiAmb, o_class_map, attr_map);
  }
  
public: 
  static RTI::ObjectClassHandle get_object_class_handle(std::string const &name)
  {
    name_to_o_class_handle_map &class_map = get_name_to_o_class_handle_map();
    name_to_o_class_handle_map::const_iterator it = class_map.find(name);

    // Not found
    if (it == class_map.end())
    {
      // TODO : throw an exception
      return -1;
    }

    return ((*it).second);
  }

  static std::size_t get_num_object_classes()
  {
    name_to_o_class_handle_map &class_map = get_name_to_o_class_handle_map();
    return class_map.size();
  }

  static void init_handles(RTI::RTIambassador &rtiAmb)
  {
    init_o_class_handles(rtiAmb);

#if 0
    name_to_o_class_handle_map::const_iterator it;
    name_to_o_class_handle_map &class_map = get_name_to_o_class_handle_map();
    for(it = class_map.begin(); it != class_map.end(); ++it) 
    {
      std::cout << (*it).first << " -> " << (*it).second << "\n";
    }
    
    class_handle_to_attr_handle_map::const_iterator it2;
    class_handle_to_attr_handle_map &attr_map = get_class_handle_to_attr_handle_map();
    for(it2 = attr_map.begin(); it2 != attr_map.end(); ++it2)
    {
      std::cout << (*it2).first << " -> " << (*it2).second << "\n";
    }
#endif
  }
 
  // Debug methods
  static void dump_stack()
  {
    //typedef dfs< ROOT_O_CLASS > dfs_type;
    dfs_type::dump_stack();
  }

  static void print_object_class_handle_map()
  {
    name_to_o_class_handle_map &class_map = get_name_to_o_class_handle_map();
    name_to_o_class_handle_map::const_iterator it;
    for(it = class_map.begin(); it != class_map.end(); ++it) 
    {
      std::cout << (*it).first << " -> " << (*it).second << "\n";
    }
  }

  static void print_attr_handle_map()
  {
    o_class_handle_to_attr_map &class_map = get_o_class_handle_to_attr_map();
    o_class_handle_to_attr_map::const_iterator i;

    for (i = class_map.begin(); i != class_map.end(); ++i) 
    {
      std::cout << (*i).first << " : " << "\n";

      const attr_name_to_handle_map &attr_map = (*i).second;
      attr_name_to_handle_map::const_iterator j;

      for (j = attr_map.begin(); j != attr_map.end(); ++j)
      {
        std::cout << "   " << (*j).first << " : " << (*j).second << "\n";
      }
    }
  }
};
  
/**************************************************************************************************/

}} // protox::hla

/**************************************************************************************************/

#endif

/**************************************************************************************************/