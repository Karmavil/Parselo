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

#include "components/headerbar_menu.hh"
#include <giomm/simpleactiongroup.h>
#include <gtkmm/gestureclick.h>
#include <iostream>
#include <string>

Parselo::HeaderBarMenu::HeaderBarMenu (Gtk::Window *parent)
{
  _parent = parent;
  set_name ("headerbar_menu");
  append (m_button);
  append (m_popover_menu);

  m_button.set_label ("⚙");
  m_button.set_has_frame (false);
  m_button.signal_clicked ().connect (sigc::mem_fun (
      *this, &Parselo::HeaderBarMenu::on_expand_headerbar_menu_clicked));

  // Define actions availabe in menu model
  auto ref_actiongroup = Gio::SimpleActionGroup::create ();
  ref_actiongroup->add_action (
      "about",
      sigc::mem_fun (*this, &Parselo::HeaderBarMenu::onAboutActionSelected));

  ref_actiongroup->add_action (
      "preferences",
      sigc::mem_fun (*this,
                     &Parselo::HeaderBarMenu::onPreferencesActionSelected));
  insert_action_group ("win", ref_actiongroup);

  // Fill headerbar menu (top righ)
  auto ref_builder = Gtk::Builder::create ();
  std::string resource = "/com/terifel/Parselo/uixml/headerbar_menu.ui";
  std::string node = "popup-menu";
  ref_builder->add_from_resource (resource);
  auto gmodel_menu = ref_builder->get_object<Gio::Menu> (node);

  m_popover_menu.set_menu_model (gmodel_menu);
}

Parselo::HeaderBarMenu::~HeaderBarMenu () {}

void
Parselo::HeaderBarMenu::on_expand_headerbar_menu_clicked ()
{
  m_popover_menu.popup ();
}

void
Parselo::HeaderBarMenu::onAboutActionSelected ()
{
  m_about = Parselo::About::create ();
  m_about->set_transient_for (*_parent);
  m_about->set_hide_on_close ();
  m_about->present ();
}

void
Parselo::HeaderBarMenu::onPreferencesActionSelected ()
{
  m_preferences = Parselo::Preferences::create ();
  m_preferences->set_transient_for (*_parent);
  m_preferences->set_hide_on_close ();
  m_preferences->present ();
}
