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

#if !defined(PARSELO_CONTAINERS_CMPBUTTON_HH)
#define PARSELO_CONTAINERS_CMPBUTTON_HH

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/frame.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>

namespace parselo
{
  class DecoButton : public Gtk::Frame
  {
  public:
    DecoButton (std::string btn_name, std::string icon_name);
    virtual ~DecoButton ();

    using DecoButtonSignal = sigc::signal<void ()>;
    DecoButtonSignal onBtnClicked ();

  protected:
    void onButtonClicked ();

    DecoButtonSignal m_btn_clicked;
    Gtk::Button m_btn;
    Gtk::Box m_hbox;
    Gtk::Image m_icon;
    Gtk::Label m_label;
  };
} // namespace

#endif // PARSELO_CONTAINERS_CMPBUTTON_HH
