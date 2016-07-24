// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NetworkNode.h"
#include "boost/graph/adjacency_list.hpp"
#include "boost/graph/properties.hpp"

namespace bitflow
{

/**
  *
  */
class Network
{
public:

  Network();
  ~Network();

private:

  struct network_node_t { typedef boost::vertex_property_tag kind; };
  typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS, boost::property<network_node_t, NetworkNode>> TGraph;

  TGraph graph;
};

} // namespace bitflow

