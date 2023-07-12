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
#include "components/nb_pages/about.hh"
#include "components/nb_pages/inquiry.hh"
#include "components/nb_pages/preferences.hh"
#include <gtkmm/eventcontrollerkey.h>
#include <gtkmm/label.h>
#include <iostream>

#if !defined SHIFT
#define SHIFT Gdk::ModifierType::SHIFT_MASK
#endif

#if !defined CTRL
#define CTRL Gdk::ModifierType::CONTROL_MASK
#endif

#if !defined ALT
#define ALT Gdk::ModifierType::ALT_MASK
#endif

parselo::AppWindow::AppWindow ()
{
  set_title ("Parselo");
  set_default_size (300, 300);
  set_size_request (800, 600);

  // Handler for even key-ESC-pressed (for exit)
  auto controller = Gtk::EventControllerKey::create ();
  add_controller (controller);
  controller->signal_key_pressed ().connect (
      sigc::mem_fun (*this, &parselo::AppWindow::on_escape_key_pressed),
      false);

  set_child (m_VBox);
  m_VBox.set_orientation (Gtk::Orientation::VERTICAL);

  m_VBox.append (m_Notebook);
  m_Notebook.set_margin (10);
  m_Notebook.set_expand ();

  auto about = Gtk::make_managed<About> ();
  m_Notebook.append_page (*about, "About");

  auto inquiries = Gtk::make_managed<Inquiry> ();
  m_Notebook.append_page (*inquiries, "Inquiry");

  auto preferences = Gtk::make_managed<Preferences> ();
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
  else
    {
      // TODO: This still needs polishing because in certain
      // combinations it doesn manage appropriately:
      // i.e. when pressing Shift before Ctrl or Alt it still consider
      // those last as keyval/keycode.
      bool isShiftPressed = (state & SHIFT) == SHIFT;
      bool isCtrlPressed = (state & CTRL) == CTRL;
      bool isAltPressed = (state & ALT) == ALT;

      // Check for combinations of two keys (excluding Alt+Ctrl+Shift)
      if ((isShiftPressed && isCtrlPressed) || (isShiftPressed && isAltPressed)
          || (isCtrlPressed && isAltPressed))
        {
          // Handle combination of two keys
          return true;
        }
      else if (isShiftPressed || isCtrlPressed || isAltPressed)
        {
          if (isShiftPressed && !(isCtrlPressed || isAltPressed))
            {
              // Handle individual key press
              if (keyval && keycode)
                return true; // TODO obviously
            }
        }
    }
  return false;
}

void
parselo::AppWindow::on_notebook_switch_page (Gtk::Widget *page, guint page_num)
{
  // auto label = m_Notebook.get_tab_label (*page);
  // Glib::ustring label_text = ((Gtk::Label *)label)->get_text ();
  // TODO: if page == "Inquiry" save buffer
  //
  // TODO: Why am I doing this? The pages should be NotebookPages at this
  // point and there should be an specialized Notebook class.
  // In the situation of changing notebook-pages for frames for example its
  // funcionality could be distributed or reutilized with a different
  // class easily.
}

#if defined(DEBUG)
Glib::ustring
parselo::AppWindow::getNameOfActivePage ()
{
  auto idx = m_Notebook.get_current_page ();
  return getNameOfPageAtIndex (idx);
}
#endif

#if defined(DEBUG)
Glib::ustring
parselo::AppWindow::getNameOfPageAtIndex (uint8_t index)
{
  auto page = m_Notebook.get_nth_page (index);
  auto label = m_Notebook.get_tab_label (*page);
  auto value = ((Gtk::Label *)label)->get_text ();
  return value;
}
#endif
