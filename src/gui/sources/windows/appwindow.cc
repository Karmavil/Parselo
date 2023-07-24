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

#if !defined SHIFT
#define SHIFT Gdk::ModifierType::SHIFT_MASK
#endif

#if !defined CTRL
#define CTRL Gdk::ModifierType::CONTROL_MASK
#endif

#if !defined ALT
#define ALT Gdk::ModifierType::ALT_MASK
#endif

#include "windows/appwindow.hh"
#include <gtkmm/eventcontrollerkey.h>
#include <gtkmm/gestureclick.h>
#include <iostream>
#include <stdexcept>

Parselo::AppWindow::AppWindow (BaseObjectType *cobject,
                               const Glib::RefPtr<Gtk::Builder> &refBuilder)
    : Gtk::ApplicationWindow (cobject), m_refBuilder (refBuilder),
      m_cttl_menu (this), m_headerbar_menu (this)
{
  set_name ("main_window");
  set_size_request (600, 800); // defaults declared in XML (window.ui)
  set_titlebar (m_headerbar);
  set_child (m_inquiry);

  // Headerbar
  m_headerbar.pack_end (m_headerbar_menu);
  m_headerbar.set_show_title_buttons ();

  m_cttl_menu.onActionSelected ().connect (
      sigc::mem_fun (*this, &Parselo::AppWindow::on_quick_test));

  add_action ("close",
              sigc::mem_fun (*this, &Parselo::AppWindow::on_action_close));
  add_action ("copy",
              sigc::mem_fun (*this, &Parselo::AppWindow::on_action_copy));
  add_action ("paste",
              sigc::mem_fun (*this, &Parselo::AppWindow::on_action_paste));
  add_action ("new_doc",
              sigc::mem_fun (*this, &Parselo::AppWindow::on_action_new_doc));

  auto controller = Gtk::EventControllerKey::create ();
  controller->signal_key_pressed ().connect (
      sigc::mem_fun (*this, &Parselo::AppWindow::on_esc_key_pressed), false);
  add_controller (controller);
}

Parselo::AppWindow *
Parselo::AppWindow::create ()
{
  // Load xml resource and instantiate the widget
  std::string resource = "/com/terifel/Parselo/uixml/window.ui";
  std::string node = "app_window";
  auto ref = Gtk::Builder::create_from_resource (resource);
  auto window = Gtk::Builder::get_widget_derived<AppWindow> (ref, node);
  if (!window)
    {
      Glib::ustring err_msg = "No " + node + " object in " + resource;
      throw std::runtime_error (err_msg);
    }
  return window;
}

void
Parselo::AppWindow::open_file_view (const Glib::RefPtr<Gio::File> & /* file */)
{
}

void
Parselo::AppWindow::on_quick_test (int n, double x, double y)
{
  std::cout << "Quick Test" << std::endl;
  std::cout << "N: " << n << "\nX: " << x << "\nY: " << y << std::endl;
}

bool
Parselo::AppWindow::on_not_implemented (Gdk::ModifierType state)
{ // This code will stay until all actions/shortcuts get set
  bool isShiftPressed = (state & SHIFT) == SHIFT;
  bool isCtrlPressed = (state & CTRL) == CTRL;
  bool isAltPressed = (state & ALT) == ALT;

  // Check for combinations of two keys (excluding Alt+Ctrl+Shift)
  if ((isShiftPressed && isCtrlPressed) || (isShiftPressed && isAltPressed)
      || (isCtrlPressed && isAltPressed))
    {
      // Handle combination of two keys
      return 0; // true;
    }
  else if (isShiftPressed || isCtrlPressed || isAltPressed)
    {
      if (isShiftPressed && !(isCtrlPressed || isAltPressed))
        {
          // Handle individual key press
          return 0; // true;
        }
    }
  return false;
}

void
Parselo::AppWindow::on_action_close ()
{
  set_visible (false);
}

void
Parselo::AppWindow::on_action_copy ()
{
  std::cout << "Action Copy" << std::endl; // TODO: action Copy
}

void
Parselo::AppWindow::on_action_paste ()
{
  std::cout << "Action Paste" << std::endl; // TODO: action Paste
}

void
Parselo::AppWindow::on_action_new_doc ()
{
  std::cout << "Action New doc" << std::endl; // TODO: action New
}

bool
Parselo::AppWindow::on_esc_key_pressed (guint keyval, guint /*keycode*/,
                                        Gdk::ModifierType /*state*/)
{
  if (keyval == GDK_KEY_Escape)
    {
      hide ();
      return true;
    }
  return false;
}
