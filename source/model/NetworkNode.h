#pragma once

#include "Types.h"
#include "boost/hana.hpp"

namespace bitflow::model
{

struct NetworkNode
{
  Position position;
  InfoAmount capacity;
};


} // namespace bitflow::model


// Simple reflection capabilities are implemented using boost::hana
BOOST_HANA_ADAPT_STRUCT(bitflow::model::NetworkNode,
  position,
  capacity
);
