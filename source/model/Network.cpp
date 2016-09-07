#include "Network.h"
#include "boost/graph/graphml.hpp"
#include <experimental/optional>

namespace bitflow { namespace model {


namespace
{

class mutate_network_impl : public boost::mutate_graph_impl<Network>
{
public:

    mutate_network_impl(Network& g, boost::dynamic_properties& dp)
        : boost::mutate_graph_impl<Network>(g, dp)
    { }

//    virtual void set_graph_property(const std::string& name, const std::string& value, const std::string& value_type) override
//    {
//    }
//
//    virtual void set_vertex_property(const std::string& name, boost::any vertex, const std::string& value, const std::string& value_type) override
//    {
//    }
//
//    virtual void set_edge_property(const std::string& name, boost::any edge, const std::string& value, const std::string& value_type) override
//    {
//    }
};

}


std::experimental::optional<Network> LoadNetworkFromGraphML(std::istream& _in_)
{
//  try
  {
    Network network;
    boost::dynamic_properties dp;
    //boost::property_map
//    dp.property()
//    dp.property("label", boost::get(&cVertex::myName, myGraph));
//    mutate_network_impl mg(network,dp);
//    boost::read_graphml(_in_, mg, 0);
    boost::read_graphml(_in_, network, dp);
    return std::experimental::make_optional(network);
  }
//  catch (std::exception& exception)
//  {
//    return std::experimental::nullopt;
//  }
}

} } // namespace bitflow::model
