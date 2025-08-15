#include "./windows/MainWindow.hpp"
#include <gtkmm.h>

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create(argc, argv, "org.jovintech.JovinGit");

  MainWindow window;

  return app->run(window);
}
