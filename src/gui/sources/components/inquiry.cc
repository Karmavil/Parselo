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

#include "components/inquiry.hh"
#include <iostream>

Parselo::Inquiry::Inquiry () : m_cttl_menu (this)
{
  set_child (m_vbox);

  m_btn_open_file.onBtnClicked ().connect (
      sigc::mem_fun (*this, &Inquiry::onOpenFileButtonClicked));

  m_btn_paste_log.onBtnClicked ().connect (
      sigc::mem_fun (*this, &Inquiry::onPasteButtonClicked));

  m_hbox.set_orientation (Gtk::Orientation::HORIZONTAL);
  m_hbox.append (m_btn_open_file);
  m_btn_open_file.setIcon ("open-file");
  m_btn_open_file.setLabel (" Open file");
  m_hbox.append (m_btn_paste_log);
  m_btn_paste_log.setIcon ("paste-log");
  m_btn_paste_log.setLabel (" Paste");

  m_vbox.set_orientation (Gtk::Orientation::VERTICAL);
  m_vbox.append (m_hbox);
  m_vbox.append (m_label);
  m_label.set_text ("Inquiries are made here");
  m_cttl_menu.onActionSelected ().connect (
      sigc::mem_fun (*this, &Inquiry::onQuickTest));
}

Parselo::Inquiry::~Inquiry () {}

void
Parselo::Inquiry::onQuickTest (int n, double x, double y)
{
  std::cout << "This is a quick test: "
            << "|" << n << "|" << x << "|" << y << std::endl;
}

void
Parselo::Inquiry::onOpenFileButtonClicked ()
{
  std::cout << "File requested" << std::endl;
}

void
Parselo::Inquiry::onPasteButtonClicked ()
{
  std::cout << "Paste contents" << std::endl;
}
