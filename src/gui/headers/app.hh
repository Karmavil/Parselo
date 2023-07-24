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

#if !defined(PARSELO_APP_HH)
#define PARSELO_APP_HH

#include "windows/appwindow.hh"
#include <giomm/application.h>
#include <glibmm/ustring.h>
#include <gtkmm/application.h>
#include <gtkmm/builder.h>
#include <gtkmm/window.h>

namespace Parselo
{
  class App : public Gtk::Application
  {
  public:
    static Glib::RefPtr<App> create ();

  protected:
    App ();
    void on_activate () override;
    void on_startup () override;
    void on_open (const Gio::Application::type_vec_files &,
                  const Glib::ustring &) override;

  private:
    void create_appwindow ();
    void on_hide_window ();
    void on_quit_from_menu ();

    Glib::RefPtr<Gtk::Builder> m_refBuilder;
    AppWindow *_window;
  };
} // namespace

#endif //
