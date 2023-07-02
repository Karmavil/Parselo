#include "parselo/top_level/window.hh"
#include <gtkmm/application.h>
#include <iostream>

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create("com.terifel.parselo");
    return app->make_window_and_run<parselo::Window>(argc, argv);
}
