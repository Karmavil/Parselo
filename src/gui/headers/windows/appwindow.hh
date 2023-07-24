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

#if !defined(PARSELO_WINDOWS_APPWINDOW_HH)
#define PARSELO_WINDOWS_APPWINDOW_HH

#include "components/contextual_menu.hh"
#include "components/headerbar_menu.hh"
#include "components/inquiry.hh"
#include "components/toolbar.hh"
#include <gtkmm/applicationwindow.h>
#include <gtkmm/builder.h>
#include <gtkmm/headerbar.h>
#include <gtkmm/window.h>

namespace Parselo
{
  class AppWindow : public Gtk::ApplicationWindow
  {
  public:
    AppWindow (BaseObjectType *cobject,
               const Glib::RefPtr<Gtk::Builder> &refBuilder);

    static AppWindow *create ();

    void open_file_view (const Glib::RefPtr<Gio::File> &file);

  protected:
    void on_quick_test (int n, double x, double y);
    void on_action_close ();
    void on_action_copy ();
    void on_action_paste ();
    void on_action_new_doc ();
    bool on_esc_key_pressed (guint, guint, Gdk::ModifierType);

    Glib::RefPtr<Gtk::Builder> m_refBuilder;
    ContextualMenu m_cttl_menu;
    Gtk::HeaderBar m_headerbar;
    HeaderBarMenu m_headerbar_menu;
    Inquiry m_inquiry;
    Toolbar *m_toolbar;

  private:
    bool on_not_implemented (Gdk::ModifierType);
  };
} // namespace Parselo

#endif // PARSELO_WINDOWS_APPWINDOW_HH
