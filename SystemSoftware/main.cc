//#include "examplewindow.h"
#include "Start.cc"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  Start window;

  // Shows the window and returns when it is closed.
  bool Comp;
   Comp= app->run(window);
   return Comp;
}


