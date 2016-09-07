#include "io2d.h"
#include <chrono>
#include <assert.h>
#include <vector>
#include "model/Network.h"
#include "boost/graph/graphml.hpp"
#include <experimental/filesystem>

int main()
{
  // Test basic types/units
  bitflow::Position p {1.0f * bitflow::meter, 2.0f * bitflow::meter, 3.0f * bitflow::meter};
  bitflow::Position p3 { p * 2.0f };
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

