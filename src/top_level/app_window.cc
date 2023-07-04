#include "parselo/top_level/app_window.hh"
#include <gtkmm/eventcontrollerkey.h>

parselo::AppWindow::AppWindow ()
{
  auto controller = Gtk::EventControllerKey::create ();
  controller->signal_key_pressed ().connect (
      sigc::mem_fun (*this, &parselo::AppWindow::on_escape_key_pressed),
      false);
  add_controller (controller);
}

parselo::AppWindow::~AppWindow () {}

bool
parselo::AppWindow::on_escape_key_pressed (guint keyval, guint keycode,
                                           Gdk::ModifierType state)
{
  if (keyval == GDK_KEY_Escape)
    this->close ();

  return false;
}
