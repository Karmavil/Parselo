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

#include "components/about.hh"
#include <gdkmm/texture.h>
#include <gtkmm/eventcontrollerkey.h>
#include <iostream>

Parselo::About::About (BaseObjectType *cobject,
                       const Glib::RefPtr<Gtk::Builder> &refBuilder)
    : Gtk::AboutDialog (cobject), m_refBuilder (refBuilder)
{
  std::string resource = "/com/terifel/Parselo/images/parselo.png";
  set_logo (Gdk::Texture::create_from_resource (resource));
  set_program_name ("Parselo");
  set_version (VERSION);
  set_copyright ("Federico Gallo");
  set_comments ("Query specific logs from the journal");
  set_website ("http://www.terifel.com/parselo");
  set_website_label ("Terifel website");
  set_license ("GPL version 2 \n\
   Parselo - Query the journal about your progam.                          \n\
   Copyright (C) 2023 Federico Gallo Herosa. https://www.terifel.com       \n\
   Find the full description of the license in the following URL:          \n\
   https://github.com/Karmavil/Parselo/blob/main/LICENSE                   \n\
                                                                           \n\
   This program is free software; you can redistribute it and/or modify    \n\
   it under the terms of the GNU General Public License as published by    \n\
   the Free Software Foundation; either version 2 of the License, or       \n\
   (at your option) any later version.                                     \n\
                                                                           \n\
   This program is distributed in the hope that it will be useful,         \n\
   but WITHOUT ANY WARRANTY; without even the implied warranty of          \n\
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           \n\
   GNU General Public License for more details.                            \n\
                                                                           \n\
   You should have received a copy of the GNU General Public License along \n\
   with this program; if not, write to the Free Software Foundation, Inc., \n\
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.             \n\
 ");

  auto controller = Gtk::EventControllerKey::create ();
  controller->signal_key_pressed ().connect (
      sigc::mem_fun (*this, &Parselo::About::on_esc_key_pressed), false);
  add_controller (controller);
}

// static
Parselo::About *
Parselo::About::create ()
{
  // Load the Builder file and instantiate its widgets
  std::string resource = "/com/terifel/Parselo/uixml/about.ui";
  std::string node = "about";
  auto ref = Gtk::Builder::create_from_resource (resource);
  auto window = Gtk::Builder::get_widget_derived<About> (ref, node);
  if (!window)
    {
      Glib::ustring err_msg = "No " + node + " object in " + resource;
      throw std::runtime_error (err_msg);
    }
  return window;
}

bool
Parselo::About::on_esc_key_pressed (guint keyval, guint /*keycode*/,
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
