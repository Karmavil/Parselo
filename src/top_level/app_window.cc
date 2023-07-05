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

#include "parselo/top_level/app_window.hh"
#include "parselo/layouts/about.hh"
#include "parselo/layouts/inquiry.hh"
#include "parselo/layouts/preferences.hh"
#include <gtkmm/eventcontrollerkey.h>

parselo::AppWindow::AppWindow ()
{
  // Handler for even key-ESC-pressed (for exit)
  auto controller = Gtk::EventControllerKey::create ();
  controller->signal_key_pressed ().connect (
      sigc::mem_fun (*this, &parselo::AppWindow::on_escape_key_pressed),
      false);
  add_controller (controller);

  set_default_size (300, 300);
  set_size_request (800, 600);

  m_VBox.set_orientation (Gtk::Orientation::VERTICAL);
  set_child (m_VBox);

  m_Notebook.set_margin (10);
  m_Notebook.set_expand ();
  m_VBox.append (m_Notebook);

  auto about = Gtk::make_managed<About> ();
  auto inquiries = Gtk::make_managed<Inquiry> ();
  auto preferences = Gtk::make_managed<Preferences> ();

  m_Notebook.append_page (*about, "About");
  m_Notebook.append_page (*inquiries, "Inquiry");
  m_Notebook.append_page (*preferences, "Preferences");

  m_Notebook.signal_switch_page ().connect (
      sigc::mem_fun (*this, &AppWindow::on_notebook_switch_page));
}

parselo::AppWindow::~AppWindow () {}

bool
parselo::AppWindow::on_escape_key_pressed (guint keyval, guint keycode,
                                           Gdk::ModifierType state)
{
  if (keyval == GDK_KEY_Escape)
    this->close ();
  return false;
}

void
parselo::AppWindow::on_notebook_switch_page (Gtk::Widget *page, guint page_num)
{
  // std::cout << "Switched to " << page_num << ": " << std::endl;
}
