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

#include "app.hh"
#include "windows/appwindow.hh"
#include "gtest/gtest.h"
#include <gtkmm/application.h>
#include <iostream>

namespace parselo
{
  class AppWindowTest : public ::testing::Test
  {
  protected:
    Glib::RefPtr<Parselo::App> m_app;
    Parselo::AppWindow *m_window;
    AppWindowTest ()
    {
      m_app = Parselo::App::create ();
      m_window = Parselo::AppWindow::create ();
    }
    ~AppWindowTest () override { m_window->hide (); }
  };

  TEST_F (AppWindowTest, AppStarted) { EXPECT_NE (m_app, nullptr); }

  TEST_F (AppWindowTest, AppWindowCreated) { EXPECT_NE (m_window, nullptr); }

  TEST_F (AppWindowTest, WindowTitleIsAsExpected)
  {
    auto title = m_window->get_title ();
    EXPECT_EQ (title, "Parselo");
  }

} // namespace parselo

int
main (int argc, char **argv)
{
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS ();
}
