#include "parselo/top_level/app_window.hh"
#include "gtest/gtest.h"

namespace parselo
{
  namespace
  {
    class AppWindowTest : public ::testing::Test
    {
    protected:
      AppWindowTest () {}
      ~AppWindowTest () override {}
    };

    TEST_F (AppWindowTest, ConstructorReturnsInstance)
    {
      EXPECT_NE (this, nullptr);
    }

  } // namespace
} // namespace parselo

int
main (int argc, char **argv)
{
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
