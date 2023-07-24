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

#if !defined CTRL
#define CTRL Gdk::ModifierType::CONTROL_MASK
#endif

#include "components/preferences.hh"
#include <glibmm/ustring.h>
#include <gtkmm/eventcontrollerkey.h>

Parselo::Preferences::Preferences (
    BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refBuilder)
    : Gtk::AboutDialog (cobject), m_refBuilder (refBuilder)
{
  auto controller = Gtk::EventControllerKey::create ();
  controller->signal_key_pressed ().connect (
      sigc::mem_fun (*this, &Parselo::Preferences::on_esc_key_pressed), false);
  add_controller (controller);
}

// static
Parselo::Preferences *
Parselo::Preferences::create ()
{
  // Load the Builder file and instantiate its widgets
  std::string resource = "/com/terifel/Parselo/uixml/shortcuts.ui";
  std::string node = "shortcuts_boxes";
  auto ref = Gtk::Builder::create_from_resource (resource);
  auto window = Gtk::Builder::get_widget_derived<Preferences> (ref, node);
  if (!window)
    {
      Glib::ustring err_msg = "No " + node + " object in " + resource;
      throw std::runtime_error (err_msg);
    }
  return window;
}

bool
Parselo::Preferences::on_esc_key_pressed (guint keyval, guint /*keycode*/,
                                          Gdk::ModifierType state)
{
  bool is_ctrl_pressed = (state & CTRL) == CTRL;
  bool is_Q_pressed = keyval == GDK_KEY_Q;
  bool is_q_pressed = keyval == GDK_KEY_q;

  if ((is_ctrl_pressed && is_Q_pressed) || (is_ctrl_pressed && is_q_pressed))
    {
      hide ();
      return true;
    }
  return false;
}
