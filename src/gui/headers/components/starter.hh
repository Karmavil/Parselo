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
// This class was extracted entirely from the documentation:
// https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/sec-custom-css-names.html
// So I think the license for this section is not out of place but it is
// for sure that it should not mention me in the copyright. It is here
// however for future modifications of this source

#if !defined(PARSELO_COMPONENTS_STARTER_HH)
#define PARSELO_COMPONENTS_STARTER_HH

#include <glibmm/extraclassinit.h>
#include <glibmm/ustring.h>

// Calls gtk_widget_class_set_css_name() in the class init function.
class Starter : public Glib::ExtraClassInit
{
public:
  Starter (const Glib::ustring &css_name);

private:
  Glib::ustring m_css_name;
};
#endif // PARSELO_COMPONENTS_STARTER_HH
