#include "../components/GridFiles.hpp"
#include "gtkmm/button.h"
#include "gtkmm/label.h"
#include "gtkmm/textview.h"
#include <gtkmm.h>

class MainWindow : public Gtk::Window {
public:
  MainWindow();

private:
  Gtk::Box vgeneralbox;
  Gtk::TextView message;
  Gtk::Label branch;
  Gtk::Label archivesLbl;
  GridFiles grid;
  Gtk::Box vbottomBox;
  Gtk::Button commit;
  Gtk::Button cancel;

  void css();
  void on_cancel_clicked();
};
