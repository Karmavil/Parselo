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

#if !defined(PARSELO_CONTAINERS_INQUIRY_HH)
#define PARSELO_CONTAINERS_INQUIRY_HH

#include "components/buttons/decobutton.hh"
#include <gtkmm/box.h>
#include <gtkmm/frame.h>
#include <gtkmm/label.h>

namespace parselo
{
  class Inquiry : public Gtk::Frame
  {
  public:
    Inquiry ();
    virtual ~Inquiry ();

  protected:
    void onOpenFileButtonClicked ();
    void onPasteButtonClicked ();

    Gtk::Box m_hbox;
    Gtk::Box m_vbox;
    Gtk::Label m_label;
    DecoButton m_btn_open_file;
    DecoButton m_btn_paste;
  };

} // namespace parselo

#endif // PARSELO_CONTAINERS_INQUIRY_HH
