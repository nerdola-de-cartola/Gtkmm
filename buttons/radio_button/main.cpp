#include "radio_button.hpp"
#include <gtkmm/application.h>

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  RadioButtons buttons;

  //Shows the window and returns when it is closed.
  return app->run(buttons);
}