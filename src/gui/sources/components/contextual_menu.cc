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

#include "components/contextual_menu.hh"
#include <iostream>
#include <string>

Parselo::ContextualMenu::ContextualMenu (Gtk::Widget *target_widget)
{
  _ref_action_group = Gio::SimpleActionGroup::create ();
  m_ref_gesture = Gtk::GestureClick::create ();
  m_ref_gesture->set_button (GDK_BUTTON_SECONDARY);
  m_ref_gesture->signal_pressed ().connect (
      sigc::mem_fun (*this, &Parselo::ContextualMenu::onSelection));
  target_widget->add_controller (m_ref_gesture);
}

Parselo::ContextualMenu::~ContextualMenu () {}

Glib::RefPtr<Gio::SimpleActionGroup>
Parselo::ContextualMenu::createActions (std::vector<Glib::ustring> &actions)
{
  for (auto &&item : actions)
    {
      std::cout << "Action: " << item << std::endl;
      //_ref_action_group->add_action (
      //    item,
      //    sigc::mem_fun (*this, &Parselo::ContextualMenu::onActionSelected));
    }
  m_ref_builder = Gtk::Builder::create ();
  return _ref_action_group;
}

void
Parselo::ContextualMenu::onSelection (int n_press, double x, double y)
{
  m_item_selected.emit (n_press, x, y);
}

Parselo::ContextualMenu::CttlMenuSignal
Parselo::ContextualMenu::onActionSelected ()
{
  return m_item_selected;
}
