#if !defined(PARSELO_TOPLEVEL_WINDOW_HH)
#define PARSELO_TOPLEVEL_WINDOW_HH

#include <gtkmm/button.h>
#include <gtkmm/window.h>

namespace parselo
{
    class AppWindow : public Gtk::Window
    {
      public:
        AppWindow();
        virtual ~AppWindow();

      protected:
        // Protected methods and properties
      private:
        // Protected methods and properties
    };
} // namespace parselo

#endif // PARSELO_TOPLEVEL_WINDOW_HH
