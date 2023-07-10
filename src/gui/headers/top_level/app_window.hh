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

#if !defined(PARSELO_TOPLEVEL_WINDOW_HH)
#define PARSELO_TOPLEVEL_WINDOW_HH

#include <glibmm/ustring.h>
#include <gtkmm/box.h>
#include <gtkmm/frame.h>
#include <gtkmm/notebook.h>
#include <gtkmm/window.h>

namespace parselo
{
  class AppWindow : public Gtk::Window
  {
  public:
    AppWindow ();
    virtual ~AppWindow ();

#if defined(DEBUG)
    Glib::ustring getNameOfActivePage ();
    Glib::ustring getNameOfPageAtIndex (uint8_t index);
#endif

  protected:
    Gtk::Box m_VBox;
    Gtk::Notebook m_Notebook;
    Gtk::Frame m_FrameAbout;
    Gtk::Frame m_FrameInquiry;
    Gtk::Frame m_FramePreferences;

    void on_notebook_switch_page (Gtk::Widget *page, guint page_num);
    bool on_escape_key_pressed (guint keyval, guint keycode,
                                Gdk::ModifierType state);
  };
} // namespace parselo

#endif // PARSELO_TOPLEVEL_WINDOW_HH
