#if !defined(PARSELO_TOPLEVEL_WINDOW_HH)
#define PARSELO_TOPLEVEL_WINDOW_HH

#include <gtkmm/window.h>

namespace parselo
{
    class Window : public Gtk::Window
    {
      public:
        Window();
        ~Window();

      protected:
        // Protected methods and properties
      private:
        // Protected methods and properties
    };
} // namespace parselo

#endif // PARSELO_TOPLEVEL_WINDOW_HH
