/*************************************************************************
  Parselo - Query the journal about your progam.
  Copyright (C) 2023 Federico Gallo Herosa. https://www.terifel.com
  Find the full description of the license in the following URL:
  https://github.com/Karmavil/Parselo/blob/main/LICENSE

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*************************************************************************/

#include "windows/app_window.hh"
#include "gtest/gtest.h"
#include <gtkmm/application.h>
#include <iostream>

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

        // Calls AppWindow
        m_window = new AppWindow ();
      }
      ~AppWindowTest () override
      {
        // Calls ~AppWindow
        delete m_window;
      }
    };
    TEST_F (AppWindowTest, Simple) { EXPECT_TRUE (1); }

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
