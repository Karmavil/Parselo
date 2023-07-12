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

#include "components/buttons/decobutton.hh"
#include <filesystem>
#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>

parselo::DecoButton::DecoButton (std::string btn_name, std::string icon_name)
{
  set_child (m_Btn);

  // TODO: This is gonna be a problem. Implement a path dispatcher.
  // (There are gonna be different type of resources to read & write)
  auto filepath = "";
  if (icon_name == "document-open")
    filepath = "src/gui/resources/document-open.png";
  else if (icon_name == "edit-paste")
    filepath = "src/gui/resources/edit-paste.png";

  std::filesystem::directory_entry entry{ filepath };
  std::filesystem::path fpath = std::filesystem::absolute (entry.path ());

  auto pmap = Gtk::make_managed<Gtk::Image> (fpath);
  auto label = Gtk::make_managed<Gtk::Label> (" " + btn_name);

  auto hBoxBtn = Gtk::make_managed<Gtk::Box> (Gtk::Orientation::HORIZONTAL);
  hBoxBtn->append (*pmap);
  hBoxBtn->append (*label);

  m_Btn.set_child (*hBoxBtn);
  m_Btn.set_margin (10);
  m_Btn.set_expand (false);

  m_Btn.signal_clicked ().connect (
      sigc::mem_fun (*this, &DecoButton::onButtonClicked));
}

parselo::DecoButton::~DecoButton () {}

void
parselo::DecoButton::onButtonClicked ()
{
  m_btn_clicked.emit ();
}

parselo::DecoButton::DecoButtonSignal
parselo::DecoButton::onBtnClicked ()
{
  return m_btn_clicked;
}
