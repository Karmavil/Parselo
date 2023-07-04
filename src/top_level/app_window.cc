#include "parselo/top_level/app_window.hh"
#include "parselo/layouts/about.hh"
#include "parselo/layouts/inquiry.hh"
#include "parselo/layouts/preferences.hh"
#include <gtkmm/eventcontrollerkey.h>

parselo::AppWindow::AppWindow ()
{
  // Handler for even key-ESC-pressed (for exit)
  auto controller = Gtk::EventControllerKey::create ();
  controller->signal_key_pressed ().connect (
      sigc::mem_fun (*this, &parselo::AppWindow::on_escape_key_pressed),
      false);
  add_controller (controller);

  set_default_size (300, 300);
  set_size_request (800, 600);

  m_VBox.set_orientation (Gtk::Orientation::VERTICAL);
  set_child (m_VBox);

  m_Notebook.set_margin (10);
  m_Notebook.set_expand ();
  m_VBox.append (m_Notebook);

  auto about = Gtk::make_managed<About> ();
  auto inquiries = Gtk::make_managed<Inquiry> ();
  auto preferences = Gtk::make_managed<Preferences> ();

  m_Notebook.append_page (*about, "About");
  m_Notebook.append_page (*inquiries, "Inquiry");
  m_Notebook.append_page (*preferences, "Preferences");

  m_Notebook.signal_switch_page ().connect (
      sigc::mem_fun (*this, &AppWindow::on_notebook_switch_page));
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

void
parselo::AppWindow::on_notebook_switch_page (Gtk::Widget *page, guint page_num)
{
  std::cout << "Switched to tab with index " << page_num << std::endl;
}
