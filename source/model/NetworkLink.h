#pragma once

#include "foundation/Types.h"

namespace bitflow::model
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

} // namespace bitflow::model

