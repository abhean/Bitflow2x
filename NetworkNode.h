#pragma once

#include "Types.h"

namespace bitflow
{

class NetworkNode
{
public:

  NetworkNode();

  Position const& GetPosition() const { return position;  }
  void SetPosition(Position const& _position) { position = _position;  }

  InfoAmount const& GetCapacity() const { return capacity;  }
  void SetCapacity(InfoAmount const& _capacity) { capacity = _capacity;  }

private:

  Position position;
  InfoAmount capacity;
};

} // namespace bitflow

