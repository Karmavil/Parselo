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
// however for future modifications of this source.

#include "components/starter.hh"
#include <gtk/gtk.h>
#include <gtkmm/widget.h>

namespace
{
  using BaseObjectType = GtkWidget;
  using BaseClassType = GtkWidgetClass;

  // These callback functions are called from GLib (a C library).
  // They shall have C linkage. (Many compilers accept callback functions
  // with C++ linkage, but such a program has undefined behavior.)
  //
  // If you want the functions with C linkage to have internal linkage,
  // they must be declared 'static', even though they are defined in an
  // anonymous namespace. The compiler respects namespace declarations of
  // functions with C linkage, but the linker does not.
  extern "C"
  {
    // Extra class init function.
    static void
    class_init_function (void *g_class, void *class_data)
    {
      g_return_if_fail (GTK_IS_WIDGET_CLASS (g_class));

      const auto klass = static_cast<BaseClassType *> (g_class);
      const auto css_name = static_cast<Glib::ustring *> (class_data);

      gtk_widget_class_set_css_name (klass, css_name->c_str ());
    }

    // Extra instance init function.
    static void
    instance_init_function (GTypeInstance *instance, void * /* g_class */)
    {
      g_return_if_fail (GTK_IS_WIDGET (instance));

      // Nothing to do here.
      // This extra instance init function just shows how such a function can
      // be added to a custom widget, if necessary.
    }
  } // extern "C"
} // anonymous namespace

Starter::Starter (const Glib::ustring &css_name)
    : Glib::ExtraClassInit (class_init_function, &m_css_name,
                            instance_init_function),
      m_css_name (css_name)
{
}
