#include "Types.h"
#include "Network.h"
#include "yedgraphml.h"
#include <experimental/optional>
#include <iostream>
#include <boost/graph/graphml.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/hana.hpp>
#include <boost/hana/string.hpp>
#include <experimental/any>

namespace bitflow { namespace model {


namespace
{

template <typename external_type>
class property_value_translator
{
 public:

    static external_type get_value(boost::property_tree::ptree const& value)
    {
      return boost::lexical_cast<external_type>(value.get_value(""));
    }
};

template <>
class property_value_translator<Position>
{
public:

    static Position get_value(boost::property_tree::ptree const& value)
    {
      return Position { 0.5f * meter, 1.0f * meter };
    }
};

const auto value_map = boost::hana::make_tuple(
    boost::hana::make_pair(BOOST_HANA_STRING("bool"), boost::hana::type_c<bool>),
    boost::hana::make_pair(BOOST_HANA_STRING("int"), boost::hana::type_c<int>),
    boost::hana::make_pair(BOOST_HANA_STRING("long"), boost::hana::type_c<long>),
    boost::hana::make_pair(BOOST_HANA_STRING("float"), boost::hana::type_c<float>),
    boost::hana::make_pair(BOOST_HANA_STRING("double"), boost::hana::type_c<double>),
    boost::hana::make_pair(BOOST_HANA_STRING("sring"), boost::hana::type_c<std::string>)
);

class mutate_network_impl : public boost::mutate_graph
{
public:

    mutate_network_impl(Network& g)
      : m_g(g)
    { }

    bool is_directed() const
    {
        return boost::is_convertible<typename boost::graph_traits<Network>::directed_category, boost::directed_tag>::value;
    }

    virtual boost::any do_add_vertex()
    {
        return boost::any(add_vertex(m_g));
    }

    virtual std::pair<boost::any,bool> do_add_edge(boost::any source, boost::any target)
    {
        std::pair<Network::edge_descriptor,bool> retval = add_edge(boost::any_cast<Network::vertex_descriptor>(source),
                                                          boost::any_cast<Network::vertex_descriptor>(target), m_g);
        return std::make_pair(boost::any(retval.first), retval.second);
    }

    virtual void set_graph_property(const std::string& name, const boost::property_tree::ptree& value, const std::string& value_type) override
    {
    }

    virtual void set_vertex_property(const std::string& name, boost::any vertex, const boost::property_tree::ptree& value, const std::string& value_type) override
    {
      auto bool_type = boost::hana::second(boost::hana::find_if(value_map, [](auto const&& name_type_tuple) { return boost::hana::first(name_type_tuple) == BOOST_HANA_STRING("bool"); }).value());
      //auto bool_type = value_map[BOOST_HANA_STRING("int")];
      using TBoolType = decltype(bool_type)::type;
      TBoolType b = "test";
      std::cout << b << std::endl;

      Network::vertex_descriptor nodeDescriptor = boost::any_cast<Network::vertex_descriptor>(vertex);
      auto& node = m_g[nodeDescriptor];

      boost::hana::for_each(boost::hana::accessors<NetworkNode>(), [&](auto const& nodePropertyAccessor) {
        auto nodePropertyName = boost::hana::first(nodePropertyAccessor);
        if (boost::hana::to<char const*>(nodePropertyName) == name)
        {
           auto nodePropertyGetter = boost::hana::second(nodePropertyAccessor);
           auto& nodePropertyValueRef = nodePropertyGetter(node);
           using NodePropertyValueType = typename std::remove_reference<decltype(nodePropertyValueRef)>::type;
           nodePropertyValueRef = property_value_translator<NodePropertyValueType>::get_value(value);
        }
      });
    }

    virtual void set_edge_property(const std::string& name, boost::any edge, const boost::property_tree::ptree& value, const std::string& value_type) override
    {
    }

private:

    Network& m_g;

};

}


std::experimental::optional<Network> LoadNetworkFromGraphML(std::istream& in)
{
//  try
  {
    Network network;

    mutate_network_impl gml(network);
    boost::read_graphml(in, gml, 0);

    return std::experimental::make_optional(network);
  }
//  catch (std::exception& exception)
//  {
//    return std::experimental::nullopt;
//  }
}

} } // namespace bitflow::model
