#pragma once

#include "Types.h"

namespace bitflow
{

class NetworkLink
{
public:

  NetworkLink();

private:

  Length length;
  Time latency;
  Bandwidth bandwidth;
};

} // namespace bitflow

