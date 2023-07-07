#include "top_level/app_window.hh"
#include "gtest/gtest.h"
#include <gtkmm/application.h>
#include <iostream>
#include <string>

namespace parselo
{
  namespace
  {
    class AppWindowTest : public ::testing::Test
    {
    protected:
      Glib::RefPtr<Gtk::Application> m_App;
      AppWindow *m_window;
      AppWindowTest ()
      {
        m_App = Gtk::Application::create ("com.terifel.parselo");
        m_App->run ();

        // AppWindow constructor should be called here
        auto window = Gtk::make_managed<AppWindow> ();
        m_window = window;
      }
      ~AppWindowTest () override
      {
        // ~AppWinidow destructor should be called here
        m_window = nullptr;
      }
    };

    TEST_F (AppWindowTest, AppStarted)
    {
      EXPECT_NE (m_App, nullptr);
      EXPECT_NE (m_window, nullptr);
    }

    TEST_F (AppWindowTest, WindowTitleIsAsExpected)
    {
      auto title = m_window->get_title ();
      EXPECT_EQ (title, "Parselo");
    }

#if defined(DEBUG) && DEBUG == 1
    TEST_F (AppWindowTest, AboutIsTheDefaultPage)
    {
      Glib::ustring page_title = m_window->getNameOfActivePage ();
      bool user_preference = false; // TODO
      if (user_preference)
        EXPECT_EQ (page_title, "Whatever");
      else
        EXPECT_EQ (page_title, "About");
    }
#endif
  } // namespace
} // namespace parselo

int
main (int argc, char **argv)
{
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
