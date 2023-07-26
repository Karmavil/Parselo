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
#include <iostream>

Parselo::DecoButton::DecoButton ()
{
  set_margin (10);
  set_expand (false);
  signal_clicked ().connect (
      sigc::mem_fun (*this, &DecoButton::onButtonClicked));
  set_child (m_hbox);
  m_hbox.set_orientation (Gtk::Orientation::HORIZONTAL);
  m_hbox.append (m_icon);
  m_hbox.append (m_label);
}

Parselo::DecoButton::~DecoButton () {}

void
Parselo::DecoButton::setLabel (Glib::ustring text_or_emoji)
{
  m_label.set_label (text_or_emoji);
}

void
Parselo::DecoButton::setIcon (std::string icon_name)
{
  // Creates an absolute path to the image resource
  m_icon.clear ();
  std::string resource = "/com/terifel/Parselo/images/";
  resource += icon_name + ".png";
  m_icon.set_from_resource (resource);
}

void
Parselo::DecoButton::onButtonClicked ()
{
  m_btn_clicked.emit ();
}

Parselo::DecoButton::DecoButtonSignal
Parselo::DecoButton::onBtnClicked ()
{
  return m_btn_clicked;
}
