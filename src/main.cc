#include "parselo/top_level/app_window.hh"
#include <gtkmm/application.h>

int
main (int argc, char *argv[])
{
  auto app = Gtk::Application::create ("com.terifel.parselo");
  return app->make_window_and_run<parselo::AppWindow> (argc, argv);
}
