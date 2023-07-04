#if !defined(PARSELO_TOPLEVEL_WINDOW_HH)
#define PARSELO_TOPLEVEL_WINDOW_HH

#include "parselo/layouts/layout.hh"
#include <gtkmm/button.h>
#include <gtkmm/window.h>

namespace parselo
{
  class AppWindow : public Gtk::Window
  {
  public:
    AppWindow ();
    virtual ~AppWindow ();

  protected:
    parselo::Layout m_layout;

  private:
    bool on_escape_key_pressed (guint keyval, guint keycode,
                                Gdk::ModifierType state);
  };
} // namespace parselo

#endif // PARSELO_TOPLEVEL_WINDOW_HH
