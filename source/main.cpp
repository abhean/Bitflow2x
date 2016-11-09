#include "io2d.h"
#include "model/Network.h"
#include "foundation/Memory.h"
#include "boost/graph/graphml.hpp"
#include <experimental/filesystem>
#include <chrono>
#include <cassert>
#include <vector>


int main()
{
  // Test network loading
  std::cout << std::experimental::filesystem::current_path() << std::endl;
  std::ifstream graphStream("data/samplenetwork.graphml");
  std::cout << graphStream.is_open() << std::endl;

  std::experimental::optional<bitflow::model::Network> network = bitflow::model::LoadNetworkFromGraphML(graphStream);
  if (network)
  {
      boost::graph_traits<bitflow::model::Network>::vertex_iterator vi, vend;
      for(boost::tie(vi, vend) = vertices(network.value()); vi != vend; ++vi)
      {
        std::cout << *vi << ", capacity=" << network.value()[*vi].capacity.value() << std::endl;
      }

      auto ds = std::experimental::io2d::make_display_surface(640, 480, std::experimental::io2d::format::argb32);
      float fTextPosX = 50.0f;
      ds.draw_callback([&fTextPosX](std::experimental::io2d::display_surface& ds) {
                                      ds.paint(std::experimental::io2d::rgba_color::firebrick());
                                      fTextPosX += 1.0f;
                                      ds.render_text("Hello world!", { fTextPosX, 50.0 }, std::experimental::io2d::rgba_color::aqua());
      });
      return ds.show();
  }

  return -1;
}

