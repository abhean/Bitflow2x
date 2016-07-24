#include "io2d.h"
#include <chrono>
#include <assert.h>

using namespace std;
using namespace std::chrono;
using namespace std::experimental::io2d;

int main()
{
  auto ds = make_display_surface(640, 480, format::argb32);
  ds.draw_callback([](display_surface& ds) {
          ds.paint(rgba_color::firebrick());
          ds.render_text("Hello world!", { 50.0, 50.0 }, rgba_color::aqua());
  });
  return ds.show();
}

