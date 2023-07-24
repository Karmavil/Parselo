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
#include <iostream>
#include <stdexcept>

Parselo::App::App () : Gtk::Application ("com.terifel.parselo") {}

Glib::RefPtr<Parselo::App>
Parselo::App::create ()
{
  return Glib::make_refptr_for_instance<App> (new App ());
}

void
Parselo::App::create_appwindow ()
{
  _window = AppWindow::create ();
  _window->signal_hide ().connect (
      sigc::mem_fun (*this, &Parselo::App::on_hide_window));
  add_window (*_window);
  _window->set_show_menubar ();
  _window->set_visible (true);
}

void
Parselo::App::on_activate ()
{
  try
    {
      create_appwindow ();
      _window->present ();
    }
  catch (const Glib::Error &ex)
    {
      std::cerr << "» App::on_activate(): " << ex.what () << std::endl;
    }
  catch (const std::exception &ex)
    {
      std::cerr << "App::on_activate(): " << ex.what () << std::endl;
    }
}

void
Parselo::App::on_startup ()
{
  Gtk::Application::on_startup ();
  m_refBuilder = Gtk::Builder::create ();
  // Set shortcut actions
  set_accel_for_action ("win.close", "<Ctrl>q");
  set_accel_for_action ("win.copy", "<Ctrl>c");
  set_accel_for_action ("win.paste", "<Ctrl>v");
  set_accel_for_action ("win.new_doc", "<Ctrl>n");

  std::string resource = "/com/terifel/Parselo/uixml/window_menu.ui";
  std::string node = "winmenu";
  try
    {
      m_refBuilder->add_from_resource (resource);
    }
  catch (const Glib::Error &ex)
    {
      std::cerr << "Failure building menu: " << ex.what () << std::endl;
    }

  auto gmenu = m_refBuilder->get_object<Gio::Menu> (node);
  if (!gmenu)
    g_warning ("GMenu not found");
  else
    set_menubar (gmenu);
}

void
Parselo::App::on_open (const Gio::Application::type_vec_files &files,
                       const Glib::ustring & /* hint */)
{
  // If requested to opening file(s) then open a new view for each one
  AppWindow *appwindow = nullptr;
  auto windows = get_windows ();
  if (windows.size () > 0)
    appwindow = dynamic_cast<AppWindow *> (windows[0]);
  try
    {
      if (!appwindow)
        create_appwindow ();

      for (const auto &file : files)
        _window->open_file_view (file);

      _window->present ();
    }
  catch (const Glib::Error &ex)
    {
      std::cerr << "|Glib| App::on_open(): " << ex.what () << std::endl;
    }
  catch (const std::exception &ex)
    {
      std::cerr << "|Std| App::on_open(): " << ex.what () << std::endl;
    }
}

void
Parselo::App::on_hide_window ()
{
  delete _window;
}

void
Parselo::App::on_quit_from_menu ()
{
  std::vector<Gtk::Window *> windows = get_windows ();
  for (auto &win : windows)
    win->set_visible (false);
}
