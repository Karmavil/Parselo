#if !defined(PARSELO_TOPLEVEL_WINDOW_HH)
#define PARSELO_TOPLEVEL_WINDOW_HH

#include "parselo/layouts/about.hh"
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/notebook.h>
#include <gtkmm/paned.h>
#include <gtkmm/window.h>
#include <iostream>

namespace parselo
{
  class AppWindow : public Gtk::Window
  {
  public:
    AppWindow ();
    virtual ~AppWindow ();

  protected:
    Gtk::Box m_VBox;
    Gtk::Notebook m_Notebook;
    Gtk::Frame m_FrameAbout;
    Gtk::Frame m_FrameInquiry;
    Gtk::Frame m_FramePreferences;

    void on_notebook_switch_page (Gtk::Widget *page, guint page_num);
    bool on_escape_key_pressed (guint keyval, guint keycode,
                                Gdk::ModifierType state);
  };
} // namespace parselo

#endif // PARSELO_TOPLEVEL_WINDOW_HH
