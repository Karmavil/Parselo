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

#if !defined(PARSELO_HEADERBAR_MENU_HH)
#define PARSELO_HEADERBAR_MENU_HH

#include "components/about.hh"
#include "components/preferences.hh"
#include <giomm/menu.h>
#include <gtkmm/box.h>
#include <gtkmm/builder.h>
#include <gtkmm/button.h>
#include <gtkmm/popovermenu.h>
#include <gtkmm/window.h>

namespace Parselo
{
  class HeaderBarMenu : public Gtk::Box
  {
  public:
    HeaderBarMenu (Gtk::Window *parent);
    ~HeaderBarMenu ();

  protected:
    void on_expand_headerbar_menu_clicked ();
    void onAboutActionSelected ();
    void onPreferencesActionSelected ();

    Glib::RefPtr<Gtk::Builder> m_refBuilder;
    Gtk::Button m_button;
    Gtk::PopoverMenu m_popover_menu;
    About *m_about;
    Preferences *m_preferences;

  private:
    Gtk::Window *_parent;
  };
} // namespace

#endif // PARSELO_HEADERBAR_MENU_HH
