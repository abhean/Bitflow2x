#include "NetworkNode.h"

namespace bitflow
{

NetworkNode::NetworkNode()
{
  Position p(1.0f * meter, 2.0f * meter, 3.0f * meter);
  Position p2(1.0f * meter, 2.0f * meter, 3.0f * meter);

  Position p3 = p + p2;
  Position p4 = p * 2.0f;

  Vector3f v(1.0f, 2.0f, 3.0f);
  Vector3f v2 = v * 2.0f;
}

} // namespace bitflow

