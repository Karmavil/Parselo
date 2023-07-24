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

#if !defined(PARSELO_COMPONENTS_CONTEXTUAL_MENU_HH)
#define PARSELO_COMPONENTS_CONTEXTUAL_MENU_HH

#include <giomm/simpleactiongroup.h>
#include <glibmm/refptr.h>
#include <glibmm/ustring.h>
#include <gtkmm/builder.h>
#include <gtkmm/gestureclick.h>
#include <gtkmm/popovermenu.h>
#include <gtkmm/widget.h>
#include <gtkmm/window.h>
#include <memory>
#include <vector>

namespace Parselo
{
  class ContextualMenu
  {
  public:
    ContextualMenu (Gtk::Widget *target_widget);
    virtual ~ContextualMenu ();

    using CttlMenuSignal
        = sigc::signal<void (int n_press, double x, double y)>;
    CttlMenuSignal onActionSelected ();

    Glib::RefPtr<Gio::SimpleActionGroup>
    createActions (std::vector<Glib::ustring> &actions);

  protected:
    CttlMenuSignal m_item_selected;
    Gtk::PopoverMenu m_menu_popup;
    Glib::RefPtr<Gtk::Builder> m_ref_builder;
    Glib::RefPtr<Gtk::GestureClick> m_ref_gesture;

  private:
    void onSelection (int n_press, double x, double y);

    std::vector<Glib::ustring> _actions;
    Glib::RefPtr<Gio::SimpleActionGroup> _ref_action_group;
  };
} // namespace

#endif // PARSELO_COMPONENTS_CONTEXTUAL_MENU_HH
