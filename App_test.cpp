#include "App.h"

#include <gtest/gtest.h>
#include <sstream>

TEST(AppShould, output_running_median_on_each_m)
{
  std::ostringstream out;
  App app(out);

  app.run("12 45 m 23 m 20 m 22 m q");
  ASSERT_EQ("28.5 23 21.5 22 ", out.str());
}
