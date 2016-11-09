#pragma once

#include "Types.h"

namespace bitflow::model
{

struct NetworkLink
{
  Length length;
  Time latency;
  Bandwidth bandwidth;
};

} // namespace bitflow::model

