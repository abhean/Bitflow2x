#ifndef YEDGRAPHML_H
#define YEDGRAPHML_H

#include <boost/property_map/dynamic_property_map.hpp>
#include <boost/graph/graphml.hpp>
#include <boost/property_tree/ptree.hpp>
#include <functional>
#include <istream>

class mutate_graph;

namespace bitflow::model
{
void read_yedgraphml(std::istream& in, boost::mutate_graph& g, size_t desired_idx);

}


#endif // YEDGRAPHML_H
