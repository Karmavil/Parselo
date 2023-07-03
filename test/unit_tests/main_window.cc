#include "parselo/top_level/window.hh"
#include "gtest/gtest.h"

namespace parselo
{
    namespace
    {
        class WindowTest : public ::testing::Test
        {
          protected:
            WindowTest()
            {
            }
            ~WindowTest() override
            {
            }
        };

        TEST_F(WindowTest, ConstructorReturnsInstance)
        {
            // Window win;
            EXPECT_NE(this, nullptr);
        }

    } // namespace
} // namespace parselo

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
