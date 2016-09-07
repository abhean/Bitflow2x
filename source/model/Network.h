// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NetworkNode.h"
#include "NetworkLink.h"
#include "boost/graph/adjacency_list.hpp"
#include "boost/graph/properties.hpp"
#include <experimental/optional>
#include <experimental/filesystem>

namespace bitflow { namespace model {

struct network_node_t { typedef boost::vertex_property_tag kind; };
using Network = boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS, NetworkNode, NetworkLink>;

std::experimental::optional<Network> LoadNetworkFromGraphML(std::istream& _in_);


} } // namespace bitflow::model

