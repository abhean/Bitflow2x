#pragma once

#define USE_BOOST_UNITS 1

#include <boost/qvm/vec.hpp>
#include <cstdint>

namespace bitflow
{
// Math
typedef boost::qvm::vec<float, 3> Vector3f;
} // namespace bitflow

#if USE_BOOST_UNITS

#include "boost/units/quantity.hpp"
#include "boost/units/systems/si/length.hpp"
#include "boost/units/systems/si/time.hpp"
#include "boost/units/systems/information/bit.hpp"
#include "boost/units/systems/information/byte.hpp"
#include "boost/mpl/divides.hpp"
#include <boost/qvm/vec_access.hpp>


namespace bitflow
{
// Distance / size / position
using boost::units::si::length;
typedef boost::units::quantity<length, float> Length;
typedef boost::qvm::vec<Length, 3> Position;


using boost::units::si::meter;

// Time
using boost::units::si::time;
typedef boost::units::quantity<time, float> Time;

// Information
using boost::units::information::info;
typedef boost::units::quantity<info, std::uint32_t> InfoAmount;

using boost::units::information::bit;
using boost::units::information::byte;

typedef boost::mpl::divides<boost::units::information_dimension, boost::units::time_dimension>::type bandwidth;
typedef boost::units::quantity<bandwidth, float> Bandwidth;

} // namespace bitflow

inline bitflow::Position operator*(bitflow::Position const& position, float scalar)
{
  return bitflow::Position { boost::qvm::X(position) * scalar, boost::qvm::Y(position) * scalar, boost::qvm::Z(position) * scalar };
}

#else

namespace bitflow
{

// Distance / size / position
typedef float Length;
typedef Vector3f Position;

Length const meter = 1.0f;

// Time
typedef float Time;

Time const second = 1.0f;

// Information
typedef std::uint32_t InfoAmount;

InfoAmount const bit = 1;
InfoAmount const byte = 8;

typedef float Bandwidth;

} // namespace bitflow

#endif

